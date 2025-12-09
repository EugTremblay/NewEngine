#pragma once

namespace homer
{
	enum EKey 
	{
		EKEY_A = 4,
		EKEY_B = 5,
		EKEY_C = 6,
		EKEY_D = 7,
		EKEY_E = 8,
		EKEY_F = 9,
		EKEY_G = 10,
		EKEY_H = 11,
		EKEY_I = 12,
		EKEY_J = 13,
		EKEY_K = 14,
		EKEY_L = 15,
		EKEY_M = 16,
		EKEY_N = 17,
		EKEY_O = 18,
		EKEY_P = 19,
		EKEY_Q = 20,
		EKEY_R = 21,
		EKEY_S = 22,
		EKEY_T = 23,
		EKEY_U = 24,
		EKEY_V = 25,
		EKEY_W = 26,
		EKEY_X = 27,
		EKEY_Y = 28,
		EKEY_Z = 29,

		EKEY_1 = 30,
		EKEY_2 = 31,
		EKEY_3 = 32,
		EKEY_4 = 33,
		EKEY_5 = 34,
		EKEY_6 = 35,
		EKEY_7 = 36,
		EKEY_8 = 37,
		EKEY_9 = 38,
		EKEY_0 = 39,

		EKEY_RETURN = 40,
		EKEY_ESCAPE = 41,
		EKEY_BACKSPACE = 42,
		EKEY_TAB = 43,
		EKEY_SPACE = 44,

		EKEY_MINUS = 45,
		EKEY_EQUALS = 46,
		EKEY_LEFTBRACKET = 47,
		EKEY_RIGHTBRACKET = 48,
		EKEY_BACKSLASH = 49
	};
	class IInput {
	public:
		virtual ~IInput() = default;

		/// <summary>
		/// Checks is a specified key is down on the keyboard
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		virtual bool IsKeyDown(int key) = 0;
		/// <summary>
		/// Checks if space got pressed
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		virtual bool IsSpaceUp() = 0;
		/// <summary>
		/// Checks if a mouse button is down
		/// </summary>
		/// <param name="button"></param>
		/// <returns></returns>
		virtual bool IsButtonDown(int button) = 0;
		/// <summary>
		/// Checks the mouse position on the screen
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		virtual void GetMousePos(int* x, int* y) = 0;
	protected:
		friend class Engine;
		virtual void Update() = 0;
	};
}