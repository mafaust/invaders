#ifndef MISSILE_H
#define MISSILE_H

#define MISSILE_SPEED 50
#define POINT_OF_DISAPPEARANCE -45

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include "Session.h"
#include "Sprite.h"
#include "System.h"

class Missile : public Sprite {
public:
    static Missile* getInstance(int x);
    ~Missile();

    void draw() const;
    void tick(float speed);
    void launchSound() const;
protected:
    Missile(int x);
private:
    SDL_Texture* texture;
    Mix_Chunk* missile_shot = Mix_LoadWAV((resPath + "sounds/missile_shot.wav").c_str());
};


#endif
