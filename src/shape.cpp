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



    Vector::Vector2 Shape::get_position() const {
        return position;
    }


    void Shape::set_position(const Vector::Vector2& position) {
        this->position = position;
    }

};
