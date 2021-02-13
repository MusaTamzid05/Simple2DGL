#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "shape.h"

namespace Engine {

    class Triangle : public Shape  {

        public:
            Triangle(const Vector::Vector2& position,
                    const Vector::Vector2& size);

            virtual ~Triangle();

            void draw(glm::mat4 projection);
            void update();
            void handle_input();


        private:


            void init_mesh();

            Triangle(const Triangle&);
            Triangle &operator=(const Triangle&);

            unsigned int VBO;
            unsigned int VAO;




    };

};


#endif
