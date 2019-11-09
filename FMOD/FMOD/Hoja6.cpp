#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>
#include <map>
#include "Pista.h"

using namespace FMOD;

// para salidas de error
void ERRCHECK(FMOD_RESULT result) {
	if (result != FMOD_OK) {
		std::cout << FMOD_ErrorString(result) << std::endl;
		// printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
		exit(-1);
	}
}



int main() { // esto es el main del piano

	
	System* system;
	FMOD_RESULT result;
	result = System_Create(&system); // Creamos el objeto system
	ERRCHECK(result);
	// 128 canales (numero maximo que podremos utilizar simultaneamente)
	result = system->init(128, FMOD_INIT_NORMAL, 0); // Inicializacion de FMOD
	ERRCHECK(result);

	Pista* pistaMap = new Pista(system, "footstep.wav", FMOD_LOOP_NORMAL|FMOD_3D);
	pistaMap->SetPosition();
	pistaMap->Play();

	FMOD_VECTOR
		listenerPos = { 0,0,0 }, // posicion del listener
		listenerVel = { 0,0,0 }, // velocidad del listener
		up = { 0,1,0 }, // vector up: hacia la ``coronilla''
		at = { 1,0,0 }; // vector at: hacia donde mira
		// colocamos listener
	system->set3DListenerAttributes(0, &listenerPos, &listenerVel, &up, &at);
	

	while (true) {
		char c;
		std::cin >> c;
		switch (c)
		{
		case 'a': // para mover listener
			listenerPos.x++;
			system->set3DListenerAttributes(0, &listenerPos, &listenerVel, &up, &at);
			break;
		case 'j':
			pistaMap->ChangePosition(-1);
			break;
		default:
			
			break;
		}
		system->update();
	}

	return 0;
}