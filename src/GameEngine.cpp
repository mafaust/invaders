
#include <string>
#include "Session.h"
#include "Ship.h"
#include "Enemy.h"

// Paths to resource folders
std::string resPath = "../../resources/";


// An example of how Sprite subclasses can be modyfied and reused
class AlienEnemy : public Enemy {
public:
    AlienEnemy(int x, int y) : Enemy(x, y) {}
    void setIcon() {
        SDL_Texture* tex = IMG_LoadTexture(sys.ren, (resPath + "images/alien.png").c_str() );
        setTexture(tex);
    }
};

int main(int argc, char** argv) {
	Ship* ship = Ship::getInstance();
	ses.add(ship);
    for (int i = 0; i < 200 ; ++i) {
        Enemy* enemy = new AlienEnemy(30, -150);
        Enemy* enem = Enemy::getInstance(100, -150);
        enemy->setIcon();
        ses.add(enemy);
        ses.add(enem);
    }
	ses.run();
	return 0;
}