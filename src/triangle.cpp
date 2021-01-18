#include "triangle.h"
#include "shader.h"

namespace Engine {


    Triangle::Triangle() {
        m_shader = new Shader("../shaders/triangle.vert", "../shaders/triangle.frag");
        init_mesh();

    }

    Triangle::~Triangle() {

    }

    void Triangle::init_mesh() {

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f,
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);


        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }

    void Triangle::draw() {

        m_shader->use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Triangle::update() {

    }

    void Triangle::handle_input() {

    }

};

