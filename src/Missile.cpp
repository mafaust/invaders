#include "Missile.h"

Missile *Missile::getInstance(int x) {
    return new Missile(x);
}

Missile::Missile(int x) : Sprite(x, 500, 40, 40) {
    texture = IMG_LoadTexture(sys.ren, (resPath + "images/missile.png").c_str() );
    launchSound();
}

Missile::~Missile() {
    SDL_DestroyTexture(texture);
}

void Missile::draw() const {
    const SDL_Rect &rect = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

void Missile::launchSound() const {
    Mix_PlayChannel(-1, missile_shot, 0);
}

void Missile::tick(float speed) {
    if(rect.y <= POINT_OF_DISAPPEARANCE)
        ses.remove(this);
    else
        rect.y -= speed * MISSILE_SPEED;
}