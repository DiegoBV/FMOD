#pragma once
#include <string>

namespace FMOD{
	class System;
	class Channel;
	class Sound;
}
class Pista
{
public:
	Pista(FMOD::System* system, std::string fileName, int mode);
	~Pista();

	void Play();
	void PlaySound();
	void Stop();
	void Pause();
	void ChangeVolume(float newVolume);
	void ChangePan(float newPan);
	void FadeIn(float demora);
	void FadeOut(float demora);
	void FMODFadeIn();
	void FMODFadeOut();
	void ChangePitch(float pitch);
	void SetPosition(float posX = 0, float posY = 0, float posZ = 0);
	void ChangePosition(float posX = 0, float posY = 0, float posZ = 0);
	void setConeOrientation(float x, float y, float z);
	void set3DConeAngles(float insideConeAngle, float outsideConeAngle, float outsideConeVolume);

private:
	
	FMOD::System* system;
	FMOD::Sound* sound;
	FMOD::Channel* channel = nullptr;
	float pitch;
};

