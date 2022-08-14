#include "audio.h"
#include <stdio.h>

#define AUDIO_PATH  "resources/file_example_WAV_1MG.wav" //"resources/composition-four-guitar-drum-melody-20802.mp3"//"resources/file_example_WAV_1MG.wav"
#define AUDIO_PATH_2 "resources/Soft Piano Music_16000_mono.wav"
static Uint8* audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play



void audio_callback(void* userdata, Uint8* stream, int len)
{
	if (audio_len == 0)
		return;

	len = (len > audio_len ? audio_len : len);
	//printf("%p\n", audio_pos);
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

	audio_pos += len;
	audio_len -= len;
}

void audio_play()
{
	// local variables
	static Uint32 wav_length; // length of our sample
	static Uint8* wav_buffer; // buffer containing our audio file
	static SDL_AudioSpec wav_spec; // the specs of our piece of music

	while(!finishGame)
	{
		/* Load the WAV */
// the specs, length and buffer of our wav are filled
		if (SDL_LoadWAV(AUDIO_PATH_2, &wav_spec, &wav_buffer, &wav_length) == NULL) {
			return;
		}

		wav_spec.format = AUDIO_S16;
		wav_spec.callback = audio_callback;
		wav_spec.userdata = NULL;
		wav_spec.freq = 8000;
		printf("wav samples: %d\n", wav_spec.samples);
		printf("wav freq: %d\n", wav_spec.freq);
		printf("wav channels: %d\n", wav_spec.channels);

		// set our global static variables
		audio_pos = wav_buffer; // copy sound buffer
		audio_len = wav_length; // copy file length

		/* Open the audio device */
		if (SDL_OpenAudio(&wav_spec, NULL) < 0) {
			fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
			exit(-1);
		}

		SDL_PauseAudio(0);

		// wait until we're don't playing
		while (audio_len > 0 && !finishGame) {
			SDL_Delay(10);
		}

		// shut everything down
		SDL_CloseAudio();
		SDL_FreeWAV(wav_buffer);

		std::this_thread::sleep_for(std::chrono::seconds(1));

		m.lock();
		i++;
		std::cout << i << std::endl;
		printf("Hello from audio thread\n");

		std::this_thread::sleep_for(std::chrono::seconds(1));
		m.unlock();
	}

}
