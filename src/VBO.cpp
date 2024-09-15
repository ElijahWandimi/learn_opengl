//
// Created by elijah on 9/15/24.
//

#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr vertexCount) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, vertexCount, vertices, GL_STATIC_DRAW);
}

void VBO::Bind() {
  glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void  VBO::Unbind() {
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
  glDeleteBuffers(1, &ID);
}
