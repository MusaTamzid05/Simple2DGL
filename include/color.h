#ifndef COLOR_H
#define COLOR_H

#include "vector.h"

namespace Engine {

    struct Color : public Vector::Vector3 {
        Color(float red, float green, float blue);

        void set_red(float red) { x = red; }
        void set_green(float green) { y = green; }
        void set_blue(float blue) { z = blue; }


        float get_red() { return x; }
        float get_green() { return y; }
        float get_blue() { return z; }



    };

};


#endif
