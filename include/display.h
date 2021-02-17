#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct GLFWwindow;

namespace Engine {

    class Shape;
    class FixedDeltaTimer;

    class Display {

        public:
            Display(const std::string& title = "Window",
                    int width = 640,
                    int height = 480
                    );

            virtual ~Display();
            void run();

            static void framebuffer_size_callback(GLFWwindow* window,
                    int width,
                    int height);

            void update(double delta_time);

        private:


            Display(const Display&);
            Display &operator=(const Display&);

            bool init(const std::string& title);


            void draw();
            void handle_input();

            int width;
            int height;

            GLFWwindow* m_window;

            std::vector<Shape*> shapes;

            glm::mat4 projection;
            FixedDeltaTimer* fixed_timer;
    };

};

#endif
