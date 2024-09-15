//
// Created by elijah on 9/14/24.
//

#include "shaderClass.h"

std::string get_file_contents(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if(file) {
        std::string contents;
        file.seekg(0, std::ios::end);
        contents.resize(file.tellg());
        file.seekg(0, std::ios::beg);
        file.read(&contents[0], static_cast<std::streamsize>(contents.size()));
        file.close();
        return contents;
    }
    throw errno;
}

Shader::Shader(const char* vertexFilePath, const char* fragmentFilePath) {
    std::string vertexSource = get_file_contents(vertexFilePath);
    std::string fragmentSource = get_file_contents(fragmentFilePath);

    const char* vShaderCode = vertexSource.c_str();
    const char* fShaderCode = fragmentSource.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate() {
    glUseProgram(ID);
}

void Shader::Delete() {
    glDeleteProgram(ID);
}