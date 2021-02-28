#ifndef VECTOR_H
#define VECTOR_H

namespace Vector {

    struct Vector2 {

        Vector2(float x = 0.0f, float y = 0.0f);

        float x;
        float y;

    };

    struct Vector3 {
        Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

        float x;
        float y;
        float z;
    };

};

#endif
