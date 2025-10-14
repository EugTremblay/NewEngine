#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>

#include "Engine.h"
#include "MainMenu.h"


using namespace homer;
void InitGamePlay() {
	//theEngine.World() ->Register("main_menu",new MainMenu())
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	Engine& theEngine = Engine::Get();
	if (theEngine.Init("Galaga", 800, 600)) {
		InitGamePlay();
		theEngine.Start();
	}
	//exemple d'implementation
	/*IInput* i = theEngine.Input();
	int x = 0;
	int y = 0;
	i->GetMousePos(&x, &y);*/

	//delete theEngine;
	return 0;
}