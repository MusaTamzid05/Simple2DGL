#include "player.h"

namespace Engine {

    Player::Player(int pos_x, int pos_y):Triangle(Vector::Vector2(pos_x, pos_y), Vector::Vector2(30, 30)) {
        set_color(new Engine::Color(1.0f, 0.5f, 0.2f));
    }

    Player::~Player() {

    }

};
