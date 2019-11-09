//#include <fmod.hpp>
//#include <fmod_errors.h>
//#include <iostream>
//#include <map>
//#include "Pista.h"
//
//using namespace FMOD;
//char arrayChar[] = {'z', 's','x', 'd', 'c', 'v', 'g','b', 'h', 'n', 'j', 'm', ','};
//int iArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//// para salidas de error
//void ERRCHECK(FMOD_RESULT result) {
//	if (result != FMOD_OK) {
//		std::cout << FMOD_ErrorString(result) << std::endl;
//		// printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
//		exit(-1);
//	}
//}
//
//void populateMap(std::map<char, Pista*>& pistaMap, System* system, const char* file) {
//	for (int i = 0; i < 13; i++) {
//		Pista* p = new Pista(system, file);
//		p->ChangePitch(pow(2, iArray[i] / 12.0f));
//		pistaMap.insert({ arrayChar[i], p});
//	}
//}
//
//int main() { // esto es el main del piano
//
//	std::map<char, Pista*> pistaMap;
//	System* system;
//	FMOD_RESULT result;
//	result = System_Create(&system); // Creamos el objeto system
//	ERRCHECK(result);
//	// 128 canales (numero maximo que podremos utilizar simultaneamente)
//	result = system->init(128, FMOD_INIT_NORMAL, 0); // Inicializacion de FMOD
//	ERRCHECK(result);
//
//	populateMap(pistaMap, system, "piano.ogg");
//	//Pista* p = new Pista(system, "piano.ogg");
//	//p->Play();
//
//	while (true) {
//		char c;
//		std::cin >> c;
//		switch (c)
//		{
//		/*case 'a':
//			p->PlaySound();
//			break;
//		case 'p':
//			p->Pause();
//			break;
//		case 's':
//			p->Stop();
//			break;
//		case 'f':
//			p->FMODFadeIn();
//			break;
//		case 'r':
//			p->FMODFadeOut();
//			break;*/
//		default:
//			auto it = pistaMap.find(c);
//			if (it != pistaMap.end()) {
//				it->second->PlaySound();
//			}
//			break;
//		}
//		system->update();
//	}
//
//	return 0;
//}