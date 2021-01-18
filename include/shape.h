#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;

namespace Engine  {


    class Shape {
        public:

            Shape(Shader* shader = nullptr); 
            virtual ~Shape();

            virtual void draw(glm::mat4 projection) = 0;
            virtual void update() = 0;
            virtual void handle_input() = 0;


        protected:

            Shape(const Shape&);
            Shape &operator=(const Shape&);
            Shader* m_shader;
    };
};

#endif
