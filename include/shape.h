#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "vector.h"
#include "color.h"

class Shader;

namespace Engine  {


    class Shape {
        public:

            Shape(Shader* shader = nullptr, const Vector::Vector2& position = Vector::Vector2(0.0f, 0.0f), const Vector::Vector2 size = Vector::Vector2(0.0f, 0.0f)); 
            virtual ~Shape();

            virtual void draw(glm::mat4 projection) = 0;
            virtual void update() = 0;
            virtual void handle_input() = 0;

            Vector::Vector2 get_position() const;
            void set_position(const Vector::Vector2& position);
            void set_rotate(float rotate) { this->rotate = rotate; }


            void set_color(Color* color);
            Color* get_color() const { return m_color; }

        protected:

            Shape(const Shape&);
            Shape &operator=(const Shape&);
            Shader* m_shader;

            float rotate;


            Vector::Vector2 position;
            Vector::Vector2 size;


            Color* m_color;


    };
};

#endif
