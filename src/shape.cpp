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

    void Shape::set_color(Color* color) {
        m_color = color;
        m_shader->use();
        m_shader->setVec4("color", m_color->get_red(), m_color->get_green(), m_color->get_blue(), 1.0f);
    }

};
