
#ifndef AUDIO_H
#define AUDIO_H

#if defined(_WIN32)
#include <SDL.h>
#include <SDL_audio.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#endif
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

class GameAudio
{
	std::string audio_path;
	bool is_running;
public:
	GameAudio(const std::string path);
	void stop() { is_running = false; }
	void start() { is_running = true;  }
	void load_new_music(const std::string path) {}

};


#endif /* AUDIO_H */
