#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>
#include <map>
#include "Pista.h"

using namespace FMOD;

int main() { // esto es el main del piano

	System* system;
	FMOD_RESULT result;
	result = System_Create(&system); // Creamos el objeto system
	// 128 canales (numero maximo que podremos utilizar simultaneamente)
	result = system->init(128, FMOD_INIT_NORMAL, 0); // Inicializacion de FMOD

	float rpm = 0;

	std::map<int, Pista*> pistaMap;
	pistaMap.insert({ 1104, new Pista(system, "1104.ogg", FMOD_LOOP_NORMAL) });
	pistaMap.insert({ 1560, new Pista(system, "1560.ogg", FMOD_LOOP_NORMAL) });
	pistaMap.find(1104)->second->Play();
	pistaMap.find(1104)->second->ChangePitch(0);
	pistaMap.find(1560)->second->ChangeVolume(0.0f);
	pistaMap.find(1560)->second->Play();
	FMOD_VECTOR
		listenerPos = { 0,0,-1 }, // posicion del listener
		listenerVel = { 0,0,0 }, // velocidad del listener
		up = { 0,1,0 }, // vector up: hacia la ``coronilla''
		at = { 1,0,0 }; // vector at: hacia donde mira
		// colocamos listener
	system->set3DListenerAttributes(0, &listenerPos, &listenerVel, &up, &at);


	system->update();
	while (true) {
		char c;
		std::cin >> c;
		switch (c)
		{
		case 'a': // para mover listener
			rpm += 100;
			if (rpm < 1000) {
				pistaMap.find(1104)->second->ChangePitch(rpm / 1000.0f);
			}
			else if(rpm >= 1000 && rpm < 1400){
				pistaMap.find(1104)->second->ChangePitch(1);
				pistaMap.find(1560)->second->ChangeVolume(sqrt(((rpm - 1000.0f)/400.0f)));

				pistaMap.find(1560)->second->ChangePitch(rpm / 1600.0f);
				pistaMap.find(1104)->second->ChangeVolume(sqrt((1 - (rpm - 1000.0f)/400.0f)));
			}
			else {
				pistaMap.find(1560)->second->ChangePitch(rpm / 1600.0f);
			}

			std::cout << rpm << std::endl;
			break;
		default:
			
			break;
		}
		system->update();
	}

	return 0;
}