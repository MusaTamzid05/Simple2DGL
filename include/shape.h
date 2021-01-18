#ifndef SHAPE_H
#define SHAPE_H

class Shader;

namespace Engine  {


    class Shape {
        public:

            Shape(Shader* shader = nullptr); 
            virtual ~Shape();

            virtual void draw() = 0;
            virtual void update() = 0;
            virtual void handle_input() = 0;


        protected:

            Shape(const Shape&);
            Shape &operator=(const Shape&);
            Shader* m_shader;
    };
};

#endif
