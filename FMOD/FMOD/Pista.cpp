#include "Pista.h"
#include <fmod.hpp>
#include <fmod_errors.h>
#include <chrono>
#include <thread>
#include <iostream>

using namespace FMOD;

Pista::Pista(System* system, std::string fileName, int mode): system(system) {

	FMOD_RESULT result = system->createSound(
		fileName.c_str(), // path al archivo de sonido
		mode, // valores (por defecto en este caso: sin loop, 2D)
		0, // informacion adicional (nada en este caso)
		&sound); // h

	result = system->playSound(
		sound, // buffer que se "engancha" a ese canal
		0, // grupo de canales, 0 sin agrupar (agrupado en el master)
		true, // arranca con "pause" (no se reproduce directamente)
		&channel); // devuelve el canal que asigna
		// el sonido ya se esta reproduciendo	ChangeVolume(1.0f);
}

Pista::~Pista() {

}


void Pista::Play() {
	channel->setPaused(false);
}

void Pista::PlaySound()
{
	//TODO: Preguntar a jaime una mejor forma
	channel->stop();
	this->Play();
	system->playSound(
		sound, // buffer que se "engancha" a ese canal
		0, // grupo de canales, 0 sin agrupar (agrupado en el master)
		false, // arranca con "pause" (no se reproduce directamente)
		&channel); // devuelve el canal que asigna
		// el sonido ya se esta reproduciendo
	channel->setPitch(pitch);
}

void Pista::Stop() {
	channel->stop();
}

void Pista::Pause() {
	channel->setPaused(true);
}

void Pista::ChangeVolume(float newVolume) {
	channel->setVolume(newVolume);
}

void Pista::ChangePan(float newPan)
{
	channel->setPan(newPan);
}

void Pista::FadeIn(float demora)
{
	float demoraTimer = demora;
	float currVol;
	
	while (demoraTimer > 0) {
		channel->getVolume(&currVol);
		ChangeVolume(currVol + (1 / demora));
		demoraTimer--;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void Pista::FadeOut(float demora)
{
	float demoraTimer = demora;
	float currVol;

	while (demoraTimer > 0) {
		channel->getVolume(&currVol);
		ChangeVolume(currVol - (1 / demora));
		demoraTimer--;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void Pista::FMODFadeIn()
{
	unsigned long long dspclock;
	channel->getDSPClock(NULL, &dspclock);

	channel->addFadePoint(dspclock, 0.0f);
	channel->addFadePoint(dspclock + 20000, 1.0f);
}

void Pista::FMODFadeOut()
{
	unsigned long long dspclock;
	channel->getDSPClock(NULL, &dspclock);

	channel->addFadePoint(dspclock, 1.0f);
	channel->addFadePoint(dspclock + 20000, 0.0f);
}

void Pista::ChangePitch(float pitch)
{
	channel->setPitch(pitch);
}

void Pista::SetPosition(float posX, float posY, float posZ)
{
	FMOD_VECTOR pos = { posX, posY, posZ };
	channel->set3DAttributes(&pos, &FMOD_VECTOR());
}

void Pista::ChangePosition(float posX, float posY, float posZ)
{
	FMOD_VECTOR pos, vel;
	channel->get3DAttributes(&pos, &vel);
	
	pos.x += posX;
	pos.y += posY;
	pos.z += posZ;

	channel->set3DAttributes(&pos, &FMOD_VECTOR());
	channel->get3DAttributes(&pos, &vel);
	std::cout << pos.x;
}

void Pista::setConeOrientation(float x, float y, float z)
{
	FMOD_VECTOR dir = { x, y, z }; // vector de direccion de los conos
	channel->set3DConeOrientation(&dir);
}

void Pista::set3DConeAngles(float insideConeAngle, float outsideConeAngle, float outsideConeVolume)
{
	channel->set3DConeSettings(insideConeAngle, outsideConeAngle, outsideConeVolume);
}
