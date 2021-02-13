#include "triangle.h"
#include "shader.h"
#include <glm/gtx/string_cast.hpp>

namespace Engine {


    Triangle::Triangle(const Vector::Vector2& position,
                    const Vector::Vector2& size):
                    Shape(nullptr, position, size){
        m_shader = new Shader("../shaders/triangle.vert", "../shaders/triangle.frag");
        init_mesh();
        rotate = 180;

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

    void Triangle::draw(glm::mat4 projection) {

        // order = scale rotate translate
        // matrix multiplicatin works in verse order
        m_shader->use();



        glm::vec2 pos = glm::vec2(position.x , position.y);
        glm::vec2 size_  = glm::vec2(size.x , size.y);


        glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(pos, 0.0f));  

		model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f)); 

		model = glm::scale(model, glm::vec3(size_, 1.0f));

        m_shader->setMat4("model", model);
        m_shader->setMat4("projection", projection);


        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Triangle::update() {

    }

    void Triangle::handle_input() {

    }

};

