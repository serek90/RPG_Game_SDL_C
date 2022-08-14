
#ifndef AUDIO_H
#define AUDIO_H

#include "SDL_audio.h"
#if defined(_WIN32)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

extern bool finishGame;
extern std::mutex m;
void audio_play();
extern int i;


#endif /* AUDIO_H */
