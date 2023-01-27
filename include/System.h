#ifndef SYSTEM_H
#define SYSTEM_H

#define RESOLUTION_X 800
#define RESOLUTION_Y 600
#define RIGHT_EDGE 715
#define LEFT_EDGE 10

#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>

struct System {
	System();
	~System();

	SDL_Window* win;
	SDL_Renderer* ren;
    Mix_Chunk* background_music;
    TTF_Font* font;
};

extern std::string resPath;
extern System sys;

#endif
