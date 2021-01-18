#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "shape.h"

namespace Engine {

    class Triangle : public Shape  {

        public:
            Triangle();
            virtual ~Triangle();

            void draw();
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
