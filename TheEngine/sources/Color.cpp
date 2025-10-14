#include "Color.h"

const Color& Color::Black = Color(0, 0, 0);
const Color& Color::White = Color(255, 255, 255);
const Color& Color::Red = Color(255, 0, 0);
const Color& Color::Green = Color(0, 255, 0);
const Color& Color::Blue = Color(0, 0, 255);

Color::Color(uchar red, uchar green, uchar blue, uchar alpha)
	:red(red),
	green(green),
	blue(blue),
	alpha(alpha)
{
}
