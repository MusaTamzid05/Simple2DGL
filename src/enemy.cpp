#include "enemy.h"

namespace Engine {

    Enemy::Enemy(int pos_x, int pos_y):Triangle(Vector::Vector2(pos_x, pos_y), Vector::Vector2(30, 30), 0) {

        set_color(new Engine::Color(1.0f, 0.0f, 0.0f));
    }

    Enemy::~Enemy() {

    }

};
