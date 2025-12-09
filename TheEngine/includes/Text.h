#pragma once
#include "Component.h"
#include "IDrawable.h"
/// <summary>
/// Component that shows text
/// </summary>
class Text : public Component, public IDrawable {
 public:
	 virtual ~Text() = default;
	 Text(Entity* ent);
	 Text(const Text& other, Entity* newParent);

	 virtual void Draw();
	 /// <summary>
	 /// Loads the desired font for future texts
	 /// </summary>
	 /// <param name="fileName"></param>
	 /// <param name="fontSize"></param>
	 virtual void LoadFontt(std::string fileName, int fontSize);
	 /// <summary>
	 /// Sets the text to the passed string
	 /// </summary>
	 /// <param name="text"></param>
	 /// <param name="x"></param>
	 /// <param name="y"></param>
	 /// <param name="color"></param>
	 virtual void SetText(std::string text, int x, int y, Color color);

	 Component* Clone(Entity* newParent) const override;
private:
	size_t m_Id;
	std::string m_Text;
	int m_X;
	int m_Y;
	Color m_Color;

};