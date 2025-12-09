#include "SDLInput.h"
#include"SDL.h"
#include "Engine.h"

SDLInput::SDLInput() {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		SDL_Log(SDL_GetError());
		
	}

}
bool spaceUp = false;
void SDLInput::Update()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
	

	SDL_Event _event;




	

	while (SDL_PollEvent(&_event)) {

		if (_event.type == SDL_KEYUP)
		{
			SDL_Keycode code = _event.key.keysym.sym;

			if (code == SDLK_SPACE)
			{
				SDL_Log("SPACE UP!");
				spaceUp = true;
			}
			
		}

		switch (_event.type) {
		case SDL_QUIT:
			//A revoir avec js m_IsRunning tourne true
			homer::Engine::Get().Exit();
			
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _buttonDown = _event.button;
			m_MouseStates[_buttonDown.button - 1] = true;
			m_MouseX = _buttonDown.x;
			m_MouseY = _buttonDown.y;
			//Faire ILogger avec une fonction Log qui fait juste faire un sdl_log dans l'interface 
			break;

		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _buttonUp = _event.button;
			SDL_Log("Button up : %d", _buttonUp.button);
			SDL_Log("at (%d, %d)", _buttonUp.x, _buttonUp.y);
			break;
		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _motion = _event.motion;
			SDL_Log("%d, %d", _motion.x, _motion.y);
			break;
		}


	}
}

bool SDLInput::IsKeyDown(int key)
{
	return m_KeyStates[key];
	
}

bool SDLInput::IsSpaceUp()
{
	bool s = spaceUp;
	spaceUp = false;
	return s;
}

bool SDLInput::IsButtonDown(int button)
{
	return m_MouseStates[button];
}
// vien modifier le pointeur pour le changer dans Game(car logique de jeu dans game)
void SDLInput::GetMousePos(int* x, int* y)
{
	*x = m_MouseX;
	*y = m_MouseY;
}
