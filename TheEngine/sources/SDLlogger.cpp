#include"SDL.h"
#include <iostream>
#include "Windows.h"
#include "SDLlogger.h"

SDLlogger::SDLlogger(){

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		SDL_Log(SDL_GetError());

	}
	else {
		AllocConsole();
		m_Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	}

}
/// <summary>
/// Take a message and a possible value to print in the console
/// </summary>
/// <param name="message"></param>
void SDLlogger::Log(const std::string& message) {
	SDL_Log(message.c_str());
}

/// <summary>
/// exits the console
/// </summary>
void SDLlogger::Quit() {
	FreeConsole();
}
