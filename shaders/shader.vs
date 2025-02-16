#version 330 core

layout(location = 0) in vec2 vertexPosition; // Vertex position input

void main() {
    gl_Position = vec4(vertexPosition, 0.0, 1.0); // Pass vertex positions to gl_Position
}
