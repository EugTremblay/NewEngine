#pragma once
#include "Component.h"
#include "IDrawable.h"
/// <summary>
/// base component for visual, adds sprite to the entity
/// </summary>
class Sprite : public Component, public IDrawable {
public:
	virtual ~Sprite() = default;
	Sprite(Entity* ent);
	Sprite(const Sprite& other, Entity* newParent);

	/// <summary>
	/// Sets the base Rect of the image
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="w"></param>
	/// <param name="h"></param>
	virtual void SetRect(float x, float y, float w, float h);
	/// <summary>
	/// Sets only the X and Y 
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	virtual void SetXY(float x, float y);
	virtual float GetX() { return m_Dst.x; };
	virtual float GetY() { return m_Dst.y; };
	/// <summary>
	/// Loads the desired texture to draw
	/// </summary>
	/// <param name="texture"></param>
	virtual void LoadTexture(std::string texture);
	/// <summary>
	/// Flips the texture with a sdl_flip
	/// </summary>
	/// <param name="textureFlip"></param>
	virtual void FlipTexture(Flip textureFlip);
	virtual void Draw();

	Component* Clone(Entity* newParent) const  override;

private:
	size_t m_Id ;
	RectI m_Src;
	RectF m_Dst;
	double m_Angle;
	Flip m_Flip;
	Color m_Color;
};
