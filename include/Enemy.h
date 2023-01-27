#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY_SPEED 50

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Session.h"
#include "Sprite.h"
#include "System.h"
#include "Missile.h"

class Enemy : public Sprite{
public:
    static Enemy* getInstance(int x, int y);
    ~Enemy();

    void draw() const;
    void tick(float speed);
    void keyDown(int x) {}
    void moveLeft(float speed);
    void moveRight(float speed);
    void moveDown();
    void isHit(Missile* m);
    void destructionSound() const;
    virtual void setIcon();
    int getEnemyNumb() const;
    void setEnemyNumb(int numb);
    void setTexture(SDL_Texture* t);
    bool isWaiting() const;
    void setWaiting(bool b);
    static int getDefeatedCount();
protected:
    Enemy(int x, int y);
private:
    SDL_Texture* texture;
    int enemyNumber;
    static int defeatedCount;
    bool reversedMovement;
    bool hit;
    bool waiting;
};

#endif
