#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
public:
unsigned int ID;
Shader(const char* vertexPath, const char* fragmentPath);
void use();
~Shader();

//Helper for math
void setMat4(const std::string& name, const float* mat) const;
};
