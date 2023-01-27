#include "System.h"

System::System() {
	SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    font = TTF_OpenFont((resPath + "fonts/arial.ttf").c_str(), 36);
	win = SDL_CreateWindow("Space Invaders Very Lite", 10, 10, RESOLUTION_X, RESOLUTION_Y, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
    background_music = Mix_LoadWAV((resPath + "sounds/arcade_background.wav").c_str());
    Mix_PlayChannel(-1, background_music, -1);
}

System::~System() {
    Mix_FreeChunk(background_music);
    TTF_CloseFont(font);
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
    TTF_Quit();
	SDL_Quit();
}

System sys;
