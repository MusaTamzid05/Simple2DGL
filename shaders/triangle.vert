#version 330 core

layout (location = 0) in vec3 aPos;


uniform mat4 model;
uniform mat4 projection;
uniform vec4 color;

out vec4 color_out;


void main() {
    gl_Position = projection * model *  vec4(aPos.x, aPos.y, 0.0, 1.0f);
    color_out = color;
}
