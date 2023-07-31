#ifndef DONUT_B2_DEBUGDRAW_H
#define DONUT_B2_DEBUGDRAW_H

#include<box2d/box2d.h>
#include<vector>

struct Donut_VertexData
{
    const b2Vec3 defaultColor = b2Vec3(0, 0, 1);

    std::vector<float> vertices;
    std::vector<float> colors;

    void addVertexData(b2Vec3 vertice, b2Vec3 color)
    {
        vertices.push_back(vertice.x);
        vertices.push_back(vertice.y);
        vertices.push_back(vertice.z);

        colors.push_back(color.x);
        colors.push_back(color.y);
        colors.push_back(color.z);
    } 
};

class Donut_b2_DebugDraw : private b2Draw
{
    /// Draw a closed polygon provided in CCW order.
	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;

	/// Draw a solid closed polygon provided in CCW order.
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;

	/// Draw a circle.
	void DrawCircle(const b2Vec2& center, float radius, const b2Color& color) override;

	/// Draw a solid circle.
	void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) override;

	/// Draw a line segment.
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;

	/// Draw a transform. Choose your own length scale.
	/// @param xf a transform.
	void DrawTransform(const b2Transform& xf) override;

	/// Draw a point.
	void DrawPoint(const b2Vec2& p, float size, const b2Color& color) override;
};
#endif