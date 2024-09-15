//
// Created by elijah on 9/15/24.
//

#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>

class EBO {
    public:
        GLuint ID;
        EBO(GLuint* indices, GLsizeiptr size);

        void Bind();
        void  Unbind();
        void Delete();
};

#endif //EBO_H
