#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <iostream>
#include "Sprite.h"

class Session {
public:
	void add(Sprite* sprite);
    void remove(Sprite* sprite);
	void run();
private:
	std::vector<Sprite*> sprites;
    std::vector<Sprite*> added, removed;
};

extern Session ses;

#endif