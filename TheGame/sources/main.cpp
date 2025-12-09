#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>

#include "Engine.h"
#include "MainMenu.h"
#include "FirstLevel.h"


using namespace homer;

Engine& theEngine = Engine::Get();

void InitGamePlay() {
	theEngine.World()->Register("main_menu", new MainMenu());
	theEngine.World()->Register("first", new FirstLevel());
	theEngine.World()->Load("main_menu");

	//crée chacune des scenes
	//ajouter chacune des scene au world
	//load first scene
	//dans chaque scene, crée mes enttyté et add components
	

	//notes for engine:
	//crée une classe base scene avec laquelle je vais exposer le world avec une subclass sandbox(voir lecture dumbass)567
	//engine update(contient : world update(contient: entitylist update(contient : component update())))
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	
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