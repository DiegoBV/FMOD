#pragma once
namespace FMOD{
	class System;
	class Channel;
	class Sound;
}
#include <string>
class Pista
{
public:
	Pista(FMOD::System* system, std::string fileName);
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

private:
	FMOD::System* system;
	FMOD::Sound* sound;
	FMOD::Channel* channel = nullptr;
	float pitch;
};

