/*
EXERCISE 3:
- Create two shader programs where the second program uses a different fragment
shader that outputs the color yellow
- Draw both triangles again where one outputs the color yellow
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// Shader sources
const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *orangeFragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
const char *yellowFragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\n\0";

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

  glViewport(0, 0, 800, 600);

  // --- Create and compile the vertex shader ---
  // ===============================================================================
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  // --- Create and compile the fragment shaders ---
  // ===============================================================================
  // Orange Fragment Shader
  unsigned int orangeFragmentShader;
  orangeFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(orangeFragmentShader, 1, &orangeFragmentShaderSource, NULL);
  glCompileShader(orangeFragmentShader);
  glGetShaderiv(orangeFragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(orangeFragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  // Yellow Fragment Shader
  unsigned int yellowFragmentShader;
  yellowFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(yellowFragmentShader, 1, &yellowFragmentShaderSource, NULL);
  glCompileShader(yellowFragmentShader);
  glGetShaderiv(yellowFragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(yellowFragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  // --- Link shaders to create shader programs ---
  // ===============================================================================
  // Orange Shader Program
  unsigned int orangeShaderProgram;
  orangeShaderProgram = glCreateProgram();
  glAttachShader(orangeShaderProgram, vertexShader);
  glAttachShader(orangeShaderProgram, orangeFragmentShader);
  glLinkProgram(orangeShaderProgram);
  glGetProgramiv(orangeShaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(orangeShaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }
  // Yellow Shader Program
  unsigned int yellowShaderProgram;
  yellowShaderProgram = glCreateProgram();
  glAttachShader(yellowShaderProgram, vertexShader);
  glAttachShader(yellowShaderProgram, yellowFragmentShader);
  glLinkProgram(yellowShaderProgram);
  glGetProgramiv(yellowShaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(yellowShaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }
  // Delete the shaders as they're linked now and no longer necessary
  glDeleteShader(vertexShader);
  glDeleteShader(orangeFragmentShader);
  glDeleteShader(yellowFragmentShader);

  // --- Set up vertex data and buffers ---
  // ===============================================================================
  // Define vertices for a two triangles
  float firstTriangleVertices[] = {-0.9f, -0.5f, 0.0f,  -0.5f, 0.5f,
                                   0.0f,  -0.1f, -0.5f, 0.0f};
  float secondTriangleVertices[] = {0.1f, -0.5f, 0.0f,  0.5f, 0.5f,
                                    0.0f, 0.9f,  -0.5f, 0.0f};

  // 1. Generate and bind VAOs and VBOs for both triangles
  unsigned int VAOs[2], VBOs[2];
  glGenVertexArrays(2, VAOs);
  glGenBuffers(2, VBOs);
  // First Triangle
  glBindVertexArray(VAOs[0]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangleVertices),
               firstTriangleVertices, GL_STATIC_DRAW);
  // Link vertex attributes
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // Second Triangle
  glBindVertexArray(VAOs[1]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangleVertices),
               secondTriangleVertices, GL_STATIC_DRAW);
  // Link vertex attributes
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // --- Render loop ---
  // ===============================================================================
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Wireframe mode

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw first triangle
    glUseProgram(orangeShaderProgram);
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // Draw second triangle
    glUseProgram(yellowShaderProgram);
    glBindVertexArray(VAOs[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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
