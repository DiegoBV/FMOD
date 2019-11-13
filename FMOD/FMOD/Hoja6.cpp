//#include <fmod.hpp>
//#include <fmod_errors.h>
//#include <iostream>
//#include <map>
//#include "Pista.h"
//
//using namespace FMOD;
//
//// para salidas de error
//void ERRCHECK(FMOD_RESULT result) {
//	if (result != FMOD_OK) {
//		std::cout << FMOD_ErrorString(result) << std::endl;
//		// printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
//		exit(-1);
//	}
//}
//
//Geometry* generaPared(System* system) {
//	Geometry* geometry;
//	system->createGeometry(1, 4, &geometry);
//	FMOD_VECTOR vertex[4] = { { 1,0,0 }, {1,1, 0}, { -1,1,0 }, { -1,0,0 } };
//	int id;
//
//	geometry->addPolygon(1, 0.5, true, 4, vertex, &id);
//	FMOD_VECTOR pos = { 0,0, 0 };
//	geometry->setPosition(&pos);
//
//	return geometry;
//}
//
//int main() { // esto es el main del piano
//
//	System* system;
//	FMOD_RESULT result;
//	result = System_Create(&system); // Creamos el objeto system
//	ERRCHECK(result);
//	// 128 canales (numero maximo que podremos utilizar simultaneamente)
//	result = system->init(128, FMOD_INIT_NORMAL, 0); // Inicializacion de FMOD
//	ERRCHECK(result);
//
//	Reverb3D* reverb;
//	result = system->createReverb3D(&reverb);
//	FMOD_REVERB_PROPERTIES prop2 = FMOD_PRESET_CONCERTHALL;
//	reverb->setProperties(&prop2);
//	FMOD_VECTOR pos = { -2.0f, 0.0f, 0.0f };
//	float mindist = 10.0f;
//	float maxdist = 20.0f;
//	reverb->set3DAttributes(&pos, mindist, maxdist);
//
//	Pista* pistaMap = new Pista(system, "footstep.wav", FMOD_LOOP_NORMAL|FMOD_3D);
//	pistaMap->SetPosition(0,0,1);
//	pistaMap->setConeOrientation(-1, 0, 0);
//	pistaMap->set3DConeAngles(60, 60, 0.1);
//	pistaMap->Play();
//
//	FMOD_VECTOR
//		listenerPos = { 0,0,-1 }, // posicion del listener
//		listenerVel = { 0,0,0 }, // velocidad del listener
//		up = { 0,1,0 }, // vector up: hacia la ``coronilla''
//		at = { 1,0,0 }; // vector at: hacia donde mira
//		// colocamos listener
//	system->set3DListenerAttributes(0, &listenerPos, &listenerVel, &up, &at);
//	
//	Geometry* g = generaPared(system);
//	g->setActive(true);
//	while (true) {
//		char c;
//		std::cin >> c;
//		switch (c)
//		{
//		case 'a': // para mover listener
//			listenerPos.x--;
//			system->set3DListenerAttributes(0, &listenerPos, &listenerVel, &up, &at);
//			break;
//		case 'j':
//			pistaMap->ChangePosition(-1);
//			break;
//		default:
//			
//			break;
//		}
//		system->update();
//	}
//
//	return 0;
//}