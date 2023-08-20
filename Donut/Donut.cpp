#include "Donut/Donut.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

SDL_Window* Donut::gWindow = NULL;
SDL_Renderer* Donut::gRenderer = NULL;
SDL_GLContext Donut::gContext = NULL;
RenderLoopFunc Donut::gRenderLoop = NULL;
EventLoopHandlerFunc Donut::gEventLoopHandler = NULL;
MouseData Donut::gMouseData;
Uint32 Donut::gRenderLoopTimer = 0;
std::map<uint32_t, bool> Donut::gIsKeyPressed;

const SDL_GLContext * Donut::get_SDL_GLContext()
{
	return &gContext;
}

void Donut::setupImgui(const SDL_Event & event)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(gWindow, gContext);
	ImGui_ImplOpenGL3_Init();

	ImGui_ImplSDL2_ProcessEvent(&event); // Forward your event to backend
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow(); 
}

bool Donut::init(int screenWidth, int screenHeight,  RenderLoopFunc renderLoop)
{
    //Initialization flag
	bool success = true;

	gRenderLoop = renderLoop;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS ) < 0 )
	{
		Donut_Log( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			Donut_LogWarning( "Linear texture filtering not enabled!" );
		}
		
		if(
			SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 ) < 0 ||
			SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 ) < 0 ||
			SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE ) < 0 )
		{
			Donut_LogError( "Failed to set attribute %s", SDL_GetError());
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );
		if( gWindow == NULL )
		{
			Donut_LogError( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gContext = SDL_GL_CreateContext( gWindow );

			if(gContext == NULL)
			{
				Donut_LogError( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
			}

			GLenum err = glewInit();
			if (GLEW_OK != err || !GLEW_VERSION_3_3)
			{
				/* Problem: glewInit failed, something is seriously wrong. */
				Donut_LogError("Glew failed to init: %s\n", (char*)glewGetErrorString(err));
			}

    
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

			//try software render if hardware fails
			if( gRenderer == NULL )
			{
				Donut_LogError( "Accelerated renderer could not be created! SDL Error: %s\nSwitching to software renderer", SDL_GetError() );
				gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_SOFTWARE);
			}

			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				// //Initialize PNG loading
				// int imgFlags = IMG_INIT_PNG;
				// if( !( IMG_Init( imgFlags ) & imgFlags ) )
				// {
				// 	Donut_LogError( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				// 	success = false;
				// }
			}
		}

		setupImgui();
	}

	return success;
}

void Donut::setEventLoopHandler(EventLoopHandlerFunc eventLoopHandler)
{
	gEventLoopHandler = eventLoopHandler;
}

MouseData Donut::getMouseData()
{
	return gMouseData;
}


bool Donut::updateLoops()
{
	if(gRenderLoop == NULL) return false;

	bool hasMouseScrollEvent = false;

	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quitit ad
		if( e.type == SDL_QUIT )
		{
			return false;
		}

		if(e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
		{
			bool isMouseDown = e.type == SDL_MOUSEBUTTONDOWN;

			if (e.button.button == SDL_BUTTON_LEFT) {
				gMouseData.isLeftMouseDown = isMouseDown;
			}

			if(e.button.button == SDL_BUTTON_RIGHT) 
			{
				gMouseData.isRightMouseDown = isMouseDown;
			}
		}

		if (e.type == SDL_MOUSEWHEEL)
		{
			hasMouseScrollEvent = true;
			gMouseData.mouseScrollOffset = e.wheel.y;
		}

		if(e.type == SDL_MOUSEMOTION)
		{
			gMouseData.mouseX = e.motion.x;
			gMouseData.mouseY = e.motion.y;
		}

		if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
		{
			gIsKeyPressed[e.key.keysym.sym] = e.type == SDL_KEYDOWN;
		}

		if(gEventLoopHandler != NULL)
			gEventLoopHandler(e);
	}

	if(!hasMouseScrollEvent)
	{
		gMouseData.mouseScrollOffset = 0;
	}

	gMouseData.offsetX = gMouseData.mouseX - gMouseData.previousX;
    gMouseData.offsetY = gMouseData.mouseY - gMouseData.previousY;

    gMouseData.previousX = gMouseData.mouseX;
    gMouseData.previousY = gMouseData.mouseY;

	if(gRenderLoopTimer == 0)
	{
		gRenderLoopTimer = SDL_GetTicks();
		return true;	
	}
	
	float deltaTime = (float)(SDL_GetTicks() - gRenderLoopTimer) / 1000;
	gRenderLoopTimer = SDL_GetTicks();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if(gRenderLoop != NULL)
		gRenderLoop(deltaTime);

	return true;
}

bool Donut::isKeyPressed(SDL_KeyCode keyCode)
{
    return gIsKeyPressed[keyCode];
}
void Donut::rendererCopySprite( Sprite sprite )
{
	SDL_RenderCopy( Donut::gRenderer, sprite.texture, NULL, &sprite.rect );
}

SDL_Texture* Donut::loadTexture( const char * path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	// //Load image at specified path
	// SDL_Surface* loadedSurface = IMG_Load( path );
	// if( loadedSurface == NULL )
	// {
	// 	printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	// }
	// else
	// {
	// 	//Create texture from surface pixels
    //     newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
	// 	if( newTexture == NULL )
	// 	{
	// 		printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
	// 	}

	// 	//Get rid of old loaded surface
	// 	SDL_FreeSurface( loadedSurface );
	// }

	return newTexture;
}

void Donut::clean()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

    //Destroy window	
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    // IMG_Quit();
    SDL_Quit();
}
