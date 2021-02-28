#ifndef PLAYER_H
#define PLAYER_H

#include "triangle.h"

namespace Engine {

    class Player : public Triangle {

        public:

            Player(int pos_x, int pos_y);
            virtual ~Player();


    };
};
#endif
