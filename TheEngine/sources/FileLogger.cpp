#pragma once
#include"SDL.h"
#include "ILogger.h"
#include <iostream>
#include <fstream>
#include "Engine.h"
#include "FileLogger.h"


using namespace std;

FileLogger::FileLogger() {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		SDL_Log(SDL_GetError());
	}
	else {
		m_LogFile.open("Log.txt");
	}

}
/// <summary>
/// Take a message and a possible value to print in the File
/// </summary>
/// <param name="message"></param>
void FileLogger::Log(const std::string& message) {
	m_LogFile << message;
}

/// <summary>
/// closes the file
/// </summary>
void FileLogger::Quit() {
	m_LogFile.close();
}