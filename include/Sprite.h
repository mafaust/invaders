#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class Sprite {
public:
    virtual ~Sprite();
	SDL_Rect getRect() const { return rect; }
    virtual void draw() const = 0;
    virtual void keyDown(int x) {}
    virtual void tick(float speed) = 0;
protected:
	Sprite(int x, int y, int w, int h) : rect{x, y, w, h } {}
    SDL_Rect rect;
private:
    // Copying and assignment is forbidden for the rootclass
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite& other) = delete;
};

#endif
