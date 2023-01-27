#include "Ship.h"

Ship::Ship() : Sprite(RESOLUTION_X / SHIP_INITIAL_X, RESOLUTION_Y - SHIP_INITIAL_Y, 75, 75) {
    texture = IMG_LoadTexture(sys.ren, (resPath + "images/spaceship.png").c_str() );
    hit = false;
}

Ship *Ship::getInstance() {
    return new Ship();
}

Ship::~Ship() {
    SDL_DestroyTexture(texture);
}

void Ship::keyDown(int x) {
        Missile* b = Missile::getInstance(x);
        ses.add(b);
}

void Ship::draw() const {
    const SDL_Rect &rect = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

void Ship::moveLeft(float speed) {
        rect.x -= speed * SHIP_SPEED;
        if (rect.x < LEFT_EDGE)
        {
            rect.x = LEFT_EDGE;
        }
}

void Ship::moveRight(float speed) {
        rect.x += speed * SHIP_SPEED;
        if (rect.x > RIGHT_EDGE)
        {
            rect.x = RIGHT_EDGE;
        }
}

bool Ship::isHit(Enemy *e) {
    if (e->getRect().x >= this->rect.x - 25 && e->getRect().x <= this->rect.x + 25) {
        if (e->getRect().y >= this->rect.y - 25 && e->getRect().y <= this->rect.y + 25) {
            hit = true;
        }
    }
    if(hit){
        destructionSound();
        ses.remove(this);
        return true;
    }
    return false;
}

void Ship::destructionSound() const {
    Mix_Chunk* impact_explosion = Mix_LoadWAV((resPath + "sounds/retro_explosion.wav").c_str());
    Mix_PlayChannel(-1, impact_explosion, 0);
}