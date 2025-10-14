#include "Engine.h"
#include <Time.h>
//#include "SDL.h"
#include "vld.h"
#ifdef USE_SDL
#include "SDLInput.h"
#include "SDLlogger.h"
#include "FileLogger.h"
#include "SDLGraphics.h"
#include "SDLAudio.h"
#elif USE_GFLW
#include "GLFWInput.h"

#endif

bool homer::Engine::Init(const char* title, int w, int h){

#ifdef USE_SDL
	m_Input = new SDLInput();
	m_Graphics = new SDLGraphics();
	m_Audio = new SDLAudio();
#ifdef _DEBUG
	m_Logger = new SDLlogger();
#else
	m_Logger = new FileLogger();
#endif
#elif USE_GFLW

#endif
	if (m_Graphics != nullptr)
	{
		m_IsInit = m_Graphics->Initialize(std::string(title), w, h);
		m_TextTest = m_Graphics->LoadFont("Font.ttf", 50);
		m_TextureTest = m_Graphics->LoadTexture("SpaceShip.png");
	}
	if (m_Audio != nullptr)
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
		m_SoundTest = m_Audio->LoadSound("Sample.mp3");
		m_MusicTest = m_Audio->LoadMusic("Music.mp3");
	}

	return m_IsInit;
}


void homer::Engine::Start(){

	float MS_PER_UPDATE = 1000 / 60;

	if (!m_IsInit) {
		if (!Init("Unkown title",800,600)) {
			exit(1);
		}
	}

	m_IsRunning = true;
	clock_t previous = clock();
	float lag = 0.0f;
	while (m_IsRunning){

		clock_t current = clock();
		float dt = static_cast<float>(current - previous);
		previous = current;
		lag += dt;
		
		ProcessInput();

		while (lag >= MS_PER_UPDATE) {

			Update(dt);
			lag -= MS_PER_UPDATE;
		}
		
		Render();
		
	}
	ShutDown();
}

homer::IInput* homer::Engine::Input(){
	return m_Input;
}

void homer::Engine::Exit() {
	m_IsRunning = false;
	
}

//analyser le code de la librairie
// acceder au code de la libraire
// essayer de le comprendre
// ajusteer notre code en consequence
// si on a une solution plus simple, la faire(gere changer l'ordre lol)

//#ifndef SDL_SCANCODE_COUNT
//#define SDL_SCANCODE_COUNT 512
//#endif
//unsigned char temp_keyStates[SDL_SCANCODE_COUNT] = { 0 };



void homer::Engine::ProcessInput(){

	m_Input->Update();

}

static float _x = 0.0f;
static float _y = 0.0f;

void homer::Engine::Update(float dt){
	//c'est du code Gameplay dans TheGame TODO
	if (m_Input -> IsKeyDown(EKEY_D)){
		_x += 10.0f * dt;
		m_Logger->Log(F("X POSITION {}", _x));
	}
	if (m_Input->IsKeyDown(EKEY_A)) {
		_x -= 10.0f * dt;
		m_Logger->Log(F("X POSITION {}", _x));
	}
	if (m_Input->IsKeyDown(EKEY_W)) {
		_y -= 10.0f * dt;
		m_Logger->Log(F("X POSITION {}", _y));
	}
	if (m_Input->IsKeyDown(EKEY_S)) {
		_y += 10.0f * dt;
		m_Logger->Log(F("X POSITION {}", _y));
	}
	//TEST
	if (m_Input->IsKeyDown(EKEY_SPACE)) {
		m_Audio->PlaySFX(m_SoundTest);
		m_Logger->Log("Play SFX");
	}
	if (m_Input->IsKeyDown(EKEY_M)) {
		m_Audio->PlayMusic(m_MusicTest);
		m_Logger->Log("Play music");
	}
#if _DEBUG
	if (m_Input->IsKeyDown(EKEY_ESCAPE)) {
		ShutDown();
	}
#endif
}

void homer::Engine::Render(){

	if (m_Graphics != nullptr)
	{
		m_Graphics->Clear();




		RectI rectI = { 100,100,50,50 };
		RectF rect = { _x,_y,100.0f,100.0f };
		//m_Graphics->FillRect(rect,Color::Red);
		m_Graphics->DrawString("Press space for sound and m for music", m_TextTest, 50, 50, Color::Blue);
		Flip flip = { true,true };
		m_Graphics->DrawTexture(m_TextureTest, rectI, rect, 90, flip, Color::Red);


		m_Graphics->Present();
	}

	

}

void homer::Engine::ShutDown(){
	
	
	
	if (m_Logger != nullptr)
	{
		m_Logger->Quit();
		delete m_Logger;
	}
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	if (m_Audio != nullptr)
	{
		Mix_CloseAudio();
		Mix_Quit();
		delete m_Audio;
	}
	if (m_Graphics != nullptr)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
	}
	
	
}
