#ifndef SHIP_H
#define SHIP_H

#define SHIP_INITIAL_X 2
#define SHIP_INITIAL_Y 75
#define SHIP_SPEED 500

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Session.h"
#include "Sprite.h"
#include "System.h"
#include "Missile.h"
#include "Enemy.h"

class Ship : public Sprite {
public:
    static Ship* getInstance();
    ~Ship();

    void draw() const;
    void tick(float speed) {}
    void keyDown(int x);
    void moveLeft(float speed);
    void moveRight(float speed);
    bool isHit(Enemy* e);
    void destructionSound() const;
protected:
    Ship();
private:
    SDL_Texture* texture;
    bool hit;
};
#endif
