#ifndef ENEMY_H
#define ENEMY_H


#include "triangle.h"

namespace Engine {

    class Enemy : public Triangle {

        public:

            Enemy(int pos_x, int pos_y);
            virtual ~Enemy();


    };
};
#endif
