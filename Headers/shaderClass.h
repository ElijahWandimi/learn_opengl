//
// Created by elijah on 9/14/24.
//

#ifndef SHADERCLASS_H
#define SHADERCLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* filename);

class Shader {
    public:
        GLuint ID;
        Shader(const char* vertexFilePath, const char* fragmentFilePath);

    void Activate();
    void Delete();
};

#endif //SHADERCLASS_H
