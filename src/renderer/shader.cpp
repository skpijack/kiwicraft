#include "shader.hpp"
Shader::Shader(const char* vertexPath, const char* fragmentPath){
    std::string vCode,fCode;
    std::ifstream vFile, fFile;
    vFile.open(vertexPath);
    fFile.open(fragmentPath);
    if (!vFile.is_open() || !fFile.is_open()) {
        std::cerr << "ERROR::SHADER::FILE_NOT_FOUND: " << vertexPath << " or " << fragmentPath << std::endl;
    }
    std::stringstream vStream,fStream;
    vStream << vFile.rdbuf();
    fStream << fFile.rdbuf();
    vCode = vStream.str();
    fCode = fStream.str();

    const char* vShaderSource = vCode.c_str();
    const char* fShaderSource = fCode.c_str();

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex,1,&vShaderSource,NULL);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment,1,&fShaderSource,NULL);
    glCompileShader(fragment);

    ID = glCreateProgram();
    glAttachShader(ID,vertex);
    glAttachShader(ID,fragment);
    glLinkProgram(ID);

    int success;
    char infoLog[1024];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 1024, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use(){glUseProgram(ID);}
void Shader::setMat4(const std::string& name, const float* mat) const{
    glUniformMatrix4fv(glGetUniformLocation(ID,name.c_str()),1,GL_FALSE,mat);
}
Shader::~Shader() {
    glDeleteProgram(ID);
}
