#define DONUT_USE_IMGUI
#include "Donut/Donut.h"
#include "ImGuizmo/ImGuizmo.h"

#include "Donut/Donut_Camera.h"

void renderLoop(float delta);

void new_frame_event()
{
    ImGuizmo::BeginFrame();
}

int main()
{
    Donut::init(800, 800, renderLoop);
    Donut::get_NewFrameEventListeners().insert(new_frame_event);

    while(Donut::updateLoops());
}

float gizmoMatrix[16] =
{
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
};

Donut_Camera camera({0, 0, 50}, {0, 0, 0}); 

void renderLoop(float delta)
{
    float matrixTranslation[3], matrixRotation[3], matrixScale[3];

    ImVec2 pos1(300, 300);
    ImVec2 pos2(400, 300);
    ImVec2 pos3(350, 400);
    ImU32 color = IM_COL32(255, 0, 0, 255); // Color in RGBA format
    ImGui::Begin("hello");
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    draw_list->AddTriangleFilled(pos1, pos2, pos3, color);

    ImGuizmo::SetRect(
        ImGui::GetWindowPos().x, ImGui::GetWindowPos().y, 
        ImGui::GetWindowWidth(), ImGui::GetWindowHeight());

    ImGuizmo::SetDrawlist();

    ImGuizmo::DrawGrid(
        glm::value_ptr(camera.caculateViewMat()),
        glm::value_ptr(camera.getProjectionMat()),
        gizmoMatrix, 10);

    ImGui::End();

    
}