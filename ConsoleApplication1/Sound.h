#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class Sound {
private:

protected:

public:
	static void PlaySoundEffect(std::string soundFile);
};