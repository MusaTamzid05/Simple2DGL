#include "display.h"
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>
#include "shape.h"

#include "triangle.h"
#include "player.h"
#include "enemy.h"
#include "vector.h"
#include "fixed_delta_timer.h"

namespace Engine {


    Display::Display(const std::string& title,
            int width,
            int height):width(width), height(height) {

        if(!init(title)) {
            std::cerr << "Could not intialize display.\n";
            return;
        }

        std::cout << "Display initialize.\n";

        projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
        shapes.push_back(new Player(width / 2, height - 20));
        shapes.push_back(new Enemy(width / 2, 20));

        fixed_timer = new FixedDeltaTimer(this);

    }

    Display::~Display() {


        delete fixed_timer;

        for(Shape* shape : shapes)
            delete shape;

        glfwTerminate();
    }

    bool Display::init(const std::string& title) {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width,
                height,
                title.c_str(),
                nullptr,
                nullptr
                );

        if(m_window == nullptr) {
            std::cerr << "could not initialize glfw.\n";
            return false;
        }

        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "could not initialize glad.\n";
            return false;
        }

        return true;
    }

    void Display::draw() {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        for(Shape* shape : shapes)
            shape->draw(projection);
    }

    void Display::update(double delta_time) {

        for(Shape* shape : shapes)
            shape->update();

    }


    void Display::handle_input() {

        if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window, true);


        for(Shape* shape : shapes)
            shape->handle_input();
    }

    void Display::run() {


        if(m_window == nullptr) {
            std::cerr << "could not run.\n";
            return;
        }

        while(!glfwWindowShouldClose(m_window)) {
            handle_input();
            fixed_timer->update();
            draw();

            glfwSwapBuffers(m_window);
            glfwPollEvents();

            
        }
    }


    void Display::framebuffer_size_callback(GLFWwindow* window,
            int width,
            int height) {
        glViewport(0, 0, width, height);
    }


}
