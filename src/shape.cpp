#include "shape.h"
#include "shader.h"
#include "vector.h"

namespace Engine {


    Shape::Shape(Shader* shader,
            const Vector::Vector2& position,
            const Vector::Vector2 size):m_shader(shader),
            position(position),
            size(size){

            }

    Shape::~Shape() {
        delete m_shader;
    }

};
