#version 330 core
out vec4 FragColor;
uniform vec4 ourColor; // We will set this from C++

void main() {
    FragColor = ourColor;
}
