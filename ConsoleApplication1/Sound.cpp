#include "Sound.h"

void Sound::PlaySoundEffect(std::string soundFile) {
	if (PlaySoundA(soundFile.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
		std::cout << "Playing sound: " << soundFile << std::endl;
	}
	else {
		std::cerr << "Error playing sound: " << soundFile << std::endl;
	}
}