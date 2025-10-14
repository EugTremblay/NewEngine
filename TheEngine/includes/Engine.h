#pragma once // ajouter dans tout les .h
#include <string>
#include "IInput.h"
#include "ILogger.h"
#include "IWorld.h"
#include "IGraphics.h"
#include "IAudio.h"

namespace homer {
	class Engine final {
	public:
		static Engine& Get() {
			static Engine instance;
			/*if (instance == nullptr)
			{
				instance = new Engine();
			}*/
			return instance;
		}
		/// <summary>
		/// Initializes the project and every variables
		/// </summary>
		/// <param name="title"></param>
		/// <param name="w"></param>
		/// <param name="h"></param>
		/// <returns></returns>
		bool Init(const char* title, int w, int h);
		/// <summary>
		/// starts the projects and contains the main loop
		/// </summary>
		void Start();
		/// <summary>
		/// Exit the application
		/// </summary>
		void Exit();
		IInput* Input();
		//IWorld* World();
	private:
		/// <summary>
		/// processes all the player inputs
		/// </summary>
		void ProcessInput();
		void Update(float dt);
		/// <summary>
		/// Renders the game
		/// </summary>
		void Render();
		/// <summary>
		/// Closes the application and deletes everything
		/// </summary>
		void ShutDown();
	private:
		IInput* m_Input = nullptr;
		ILogger* m_Logger = nullptr;
		IWorld* m_World = nullptr;
		IGraphics* m_Graphics = nullptr;
		IAudio* m_Audio = nullptr;
		bool m_IsRunning = false;
		bool m_IsInit = false;
		size_t m_TextTest = 0;
		size_t m_TextureTest = 0;
		size_t m_SoundTest = 0;
		size_t m_MusicTest = 0;
	};
}
