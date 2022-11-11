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
	len = 17824;
	printf("pos: %p\n", audio_pos);
	printf("stream :%p\n", stream);
	printf("len: %d     %d", audio_len, len);

	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME );// mix from one buffer into another

	audio_pos += len;
	audio_len -= len;
	//SDL_Delay(1000);
}

void audio_play()
{
	// local variables
	static Uint32 wav_length; // length of our sample
	static Uint8* wav_buffer; // buffer containing our audio file
	static SDL_AudioSpec wav_spec, have; // the specs of our piece of music
	static Uint8* chank;

	while(true)
	{
		/* Load the WAV */
// the specs, length and buffer of our wav are filled
		if (SDL_LoadWAV(AUDIO_PATH_2, &wav_spec, &wav_buffer, &wav_length) == NULL) {
			return;
		}

		wav_spec.format = AUDIO_S16;
		wav_spec.callback = audio_callback;
		wav_spec.userdata = NULL;
		wav_spec.freq = 16000;
		printf("wav samples: %d\n", wav_spec.samples);
		printf("wav freq: %d\n", wav_spec.freq);
		printf("wav channels: %d\n", wav_spec.channels);
		printf("wav format: %d\n", wav_spec.format);

		// set our global static variables
		audio_pos = wav_buffer; // copy sound buffer
		audio_len = wav_length; // copy file length

		/* Open the audio device */
		if (SDL_OpenAudio(&wav_spec, NULL) < 0) {
		//SDL_AudioDeviceID dev = SDL_OpenAudioDevice(NULL, 0, &wav_spec, &have, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
		//if(!dev){
			fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
			exit(-1);
		}
		else
			printf("SDL_OpenAudio ok\n");
		printf("wav samples: %d\n", wav_spec.samples);
		printf("wav freq: %d\n", wav_spec.freq);
		printf("wav channels: %d\n", wav_spec.channels);
		printf("wav format: %d\n", wav_spec.format);


		SDL_PauseAudio(0);

		// wait until we're don't playing
		while (audio_len > 0) {
			SDL_Delay(100);
		}

		// shut everything down
		SDL_CloseAudio();
		SDL_FreeWAV(wav_buffer);

		std::this_thread::sleep_for(std::chrono::seconds(1));

		printf("Hello from audio thread\n");

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}

void audio_play_2()
{

	// load WAV file

	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioSpec want, have;
	SDL_AudioDeviceID dev;

	SDL_memset(&want, 0, sizeof(want)); /* or SDL_zero(want) */
	want.freq = 48000;
	want.format = AUDIO_F32;
	want.channels = 2;
	want.samples = 4096;
	want.callback = audio_callback;  // you wrote this function elsewhere.
	static Uint32 wav_length; // length of our sample
	static Uint8* wav_buffer; // buffer containing our audio file
	static SDL_AudioSpec wav_spec; // the specs of our piece of music
	if (SDL_LoadWAV(AUDIO_PATH_2, &wav_spec, &wav_buffer, &wav_length) == NULL) {
		return;
	}
	dev = SDL_OpenAudioDevice(NULL, 0, &wav_spec, &have, SDL_AUDIO_ALLOW_FORMAT_CHANGE);


	//SDL_LoadWAV(AUDIO_PATH, &wavSpec, &wavBuffer, &wavLength);
	//SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	printf("SDL_Init failed: %s\n", SDL_GetError());
	//auto success = SDL_QueueAudio(dev, wavBuffer, wavLength);
	std::cout << dev << std::endl;
	//std::cout << wavLength << std::endl;
	//std::cout << wavBuffer << std::endl;

	//std::cout << "Audio init succes: " << success  << std::endl;
	SDL_PauseAudioDevice(dev, 0);
	SDL_Delay(30000);
	// clean up

	SDL_CloseAudioDevice(dev);
	SDL_FreeWAV(wavBuffer);

	//while (true)
	{

		std::this_thread::sleep_for(std::chrono::seconds(1));

		printf("Hello from audio thread\n");

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}



GameAudio::GameAudio(const std::string path) : audio_path(path)
{
	is_running = true;
	std::thread audio_thread(&audio_play);
	audio_thread.detach();
}
