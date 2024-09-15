#include <cmath>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <shaderClass.h>
#include <VAO.h>
#include <VBO.h>
#include <EBO.h>

GLfloat vertices[] = {
    -0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
    0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
    0.0f, 0.5f * static_cast<float>(sqrt(3)) * 2/3, 0.0f,
    -0.5f / 2, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f,
    0.5f / 2, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f,
    0.0f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
};

GLuint indices[] = {
    0, 3, 5,
    3, 2, 4,
    5, 4, 1
};

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(720, 680, "Hello OpenGL", NULL, NULL);

    if(!window) {
      glfwTerminate();
      return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();
    glViewport(0, 0, 720, 680);

    Shader shaderProgram("shaders/default.vert", "shaders/default.frag");

    VAO vao1;
    vao1.Bind();

    VBO vbo1(vertices, sizeof(vertices));
    EBO ebo1(indices, sizeof(indices));

    vao1.LinkVBO(vbo1, 0);
    vao1.Unbind();
    vbo1.Unbind();
    ebo1.Unbind();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();
        vao1.Bind();

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    vao1.Delete();
    vbo1.Delete();
    ebo1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
