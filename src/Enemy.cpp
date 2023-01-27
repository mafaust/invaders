#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int x, int y) : Sprite(x, y, 50, 50){
    setIcon();
    setEnemyNumb(0);
    reversedMovement = false;
    hit = false;
}

Enemy *Enemy::getInstance(int x, int y) {
    return new Enemy(x, y);
}

Enemy::~Enemy() {
    SDL_DestroyTexture(texture);
}

void Enemy::draw() const {
    const SDL_Rect &rect = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

void Enemy::tick(float speed) {
    if(hit) {
        destructionSound();
        defeatedCount++;
        ses.remove(this);
    }

    if(!waiting){
        if(rect.x >= RIGHT_EDGE){
            moveDown();
            reversedMovement = true;
        } else if (rect.x <= LEFT_EDGE) {
            moveDown();
            reversedMovement = false;
        }

        if(reversedMovement) {
            moveRight(speed);
        } else {
            moveLeft(speed);
        }
    }
}

void Enemy::moveDown() {
    rect.y += 50;
}

void Enemy::moveLeft(float speed) {
    rect.x += speed * ENEMY_SPEED;
}

void Enemy::moveRight(float speed) {
    rect.x -= speed * ENEMY_SPEED;
}

void Enemy::isHit(Missile* m) {
    if (m->getRect().x >= this->rect.x - 25 && m->getRect().x <= this->rect.x + 25){
        if (m->getRect().y >= this->rect.y - 25 && m->getRect().y <= this->rect.y + 25)
        {
            hit = true;
        }
    }
}

void Enemy::destructionSound() const {
    Mix_Chunk* impact_explosion = Mix_LoadWAV((resPath + "sounds/impact_explosion.wav").c_str());
    Mix_PlayChannel(-1, impact_explosion, 0);
}

void Enemy::setIcon() {
    texture = IMG_LoadTexture(sys.ren, (resPath + "images/ufo.png").c_str() );
}

int Enemy::defeatedCount = 0;

int Enemy::getDefeatedCount() {
    return defeatedCount;
}

int Enemy::getEnemyNumb() const {
    return enemyNumber;
}

void Enemy::setEnemyNumb(int numb) {
    enemyNumber = numb;
}

bool Enemy::isWaiting() const {
    return waiting;
}

void Enemy::setWaiting(bool b) {
    waiting = b;
}

void Enemy::setTexture(SDL_Texture *t) {
    SDL_DestroyTexture(texture);
    texture = t;
}
