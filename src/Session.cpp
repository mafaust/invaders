#include "Session.h"
#include <SDL2/SDL.h>
#include <chrono>
#include <thread>
#include "System.h"
#include "Ship.h"
#include "Enemy.h"

#define FPS 60
// A constant for the missile icon that helps to allign it with the center of the spaceship
#define CENTERED_MISSILE 18
// To smoothen up the movement I used a technique described here: https://cplusplus.com/forum/general/155845/
float speed = 5.0 / FPS;
int enemyCounter = 0;
int timeCounter = 0;
using namespace std;

void Session::add(Sprite* comp) {
	added.push_back(comp);
}

void Session::remove(Sprite *comp) {
    removed.push_back(comp);
}

void Session::run() {
	bool quit = false;
    Uint32 tickInterval = 1000 / FPS;
	while (!quit) {
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: quit = true; break;
            case SDL_KEYDOWN:
                for (Sprite* c : sprites)
                    if (Ship* s = dynamic_cast<Ship*>(c)){
                        switch (event.key.keysym.sym) {
                            case SDLK_RIGHT: s->moveRight(speed); break;
                            case SDLK_LEFT: s->moveLeft(speed); break;
                            case SDLK_SPACE:
                                s->keyDown(s->getRect().x + CENTERED_MISSILE); break;
                        }
                    }
			}
		}

        for(Sprite* c : sprites){
            if(Enemy* e = dynamic_cast<Enemy*>(c)){
                if(e->getEnemyNumb() == 0){
                    e->setEnemyNumb(enemyCounter);
                    enemyCounter++;
                }
            }
            enemyCounter = 0;
        }
        timeCounter++;

        for(Sprite* c : sprites){
            if (Enemy* e = dynamic_cast<Enemy*>(c)){
                // Generation of enemies with delay
                if(e->isWaiting() && e->getEnemyNumb() == enemyCounter){
                    if(timeCounter % 50 == 0) {
                        e->setWaiting(false);
                        enemyCounter++;
                    }
                }
                // Collision mechanism
                for(Sprite* s : sprites){
                    if (Missile* m = dynamic_cast<Missile*>(s)){
                        e->isHit(m);
                    }
                    if(Ship* sh = dynamic_cast<Ship*>(s)){
                        if(sh->isHit(e)){
                            quit = true;
                        }
                    }
                }
            }
            c->tick(speed);
        }

        for(Sprite* c : added)
            sprites.push_back(c);
        added.clear();

        for(Sprite* c : removed)
            for(vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end();)
                if(*i == c){
                    i = sprites.erase(i);
                } else
                    i++;
        removed.clear();

        // Get data about amount defeated enemies and print it as a text
        std::string defeatedString = std::to_string(Enemy::getDefeatedCount());
        SDL_Color white = {255,255,255};
        SDL_Surface* defeatedSurf = TTF_RenderText_Solid(sys.font, defeatedString.c_str(), white);
        SDL_Texture* defeatedTx = SDL_CreateTextureFromSurface(sys.ren, defeatedSurf);
        SDL_Rect varvRect = {10, 10, defeatedSurf->w, defeatedSurf->h};
        SDL_FreeSurface(defeatedSurf);

		SDL_SetRenderDrawColor(sys.ren, 0, 0, 0, 0);
		SDL_RenderClear(sys.ren);
        // Text
        SDL_RenderCopy(sys.ren, defeatedTx, NULL, &varvRect);
		for (Sprite* c : sprites)
			c->draw();
		SDL_RenderPresent(sys.ren);

        // Delay if needed
        int delay = nextTick - SDL_GetTicks();
        if(delay > 0)
            SDL_Delay(delay);
	}
}

Session ses;
