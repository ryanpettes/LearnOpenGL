#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
  // --- Initialize GLFW ---
  // ===============================================================================
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // --- Create a GLFW window ---
  // ===============================================================================
  GLFWwindow *window =
      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // --- Load OpenGL function pointers using GLAD ---
  // ===============================================================================
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // Fix MacOS Retina display quirk
  // `glViewport(0, 0, 800, 600);` DOESN'T WORK as expected, replace with:
  int fbWidth, fbHeight;
  glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
  glViewport(0, 0, fbWidth, fbHeight);

  // Set up shader program
  Shader ourShader = Shader("vertex.vs", "fragment.fs");

  // --- Set up vertex data and buffers ---
  // ===============================================================================
  float vertices[] = {
      // positions         // colors
      0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
      0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f  // top
  };

  // 1. Generate and bind a Vertex Array Object (VAO)
  unsigned int VAO;           // Vertex Array Object
  glGenVertexArrays(1, &VAO); // Generate 1 VAO, storing id in VAO
  glBindVertexArray(VAO);     // Bind the VAO

  // 2. Generate and bind a Vertex Buffer Object (VBO)
  unsigned int VBO;      // Vertex Buffer Object
  glGenBuffers(1, &VBO); // Generate 1 buffer, storing id in VBO
  glBindBuffer(GL_ARRAY_BUFFER,
               VBO); // Bind the buffer to the GL_ARRAY_BUFFER target
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
               GL_STATIC_DRAW); // Copy vertex data to buffer

  // --- Link vertex attributes ---
  // ===============================================================================
  // Position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (const void *)0);
  glEnableVertexAttribArray(0);
  // Color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (const void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // --- Render loop ---
  // ===============================================================================
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Wireframe mode

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    // Background color
    glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ourShader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // --- Clean up and exit ---
  // ===============================================================================
  glfwTerminate();
  return 0;
}

// Callback function to adjust the viewport when the window is resized
// ================================================================================
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

// Function to process input (currently unused)
// ================================================================================
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}