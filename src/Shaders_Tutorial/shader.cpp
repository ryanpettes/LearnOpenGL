#include <glad/glad.h>
#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

#define INFO_LOG_SIZE 512

// PRE: vertexPath and fragmentPath are strings specifying paths to
//      respective shader files to be read
// POST: if files exist, they are read into std::string objects
Shader::Shader(const char *vertexPath, const char *fragmentPath) {
  // 1. Retrieve source code from file paths
  // =======================================
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;

  // Ensure ifstream objects can throw exceptions
  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    // Open files
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);
    std::stringstream vShaderStream, fShaderStream;

    // Read buffer contents into streams
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    // Close file handlers
    vShaderFile.close();
    fShaderFile.close();

    // Read buffer contents into strings
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  } catch (std::ifstream::failure e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
  }

  // Convert to C strings (same contents, but null-terminated with `\0`)
  const char *vShaderCode = vertexCode.c_str();
  const char *fShaderCode = fragmentCode.c_str();

  // 2. Attempt to compile shaders
  // ======================================
  unsigned int vertex, fragment;
  int success;
  char infoLog[INFO_LOG_SIZE];

  // Vertex shader
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, NULL);
  glCompileShader(vertex);
  // Print errors, if any
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex, INFO_LOG_SIZE, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  // Fragment shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, NULL);
  glCompileShader(fragment);
  // Print errors, if any
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment, INFO_LOG_SIZE, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  // 3. Attempt to link shaders
  // =========================
  id = glCreateProgram();
  glAttachShader(id, vertex);
  glAttachShader(id, fragment);
  glLinkProgram(id);
  // Print errors, if any
  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id, INFO_LOG_SIZE, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }

  // Delete shaders, since they are now successfully linked and no longer needed
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

// Function to use/activate program specified by this object
void Shader::use() { glUseProgram(id); }

// Function to set boolean uniform
void Shader::setBool(const std::string &name, bool value) const {
  unsigned int loc = glGetUniformLocation(id, name.c_str());
  glUniform1i(loc, (int)value);
}

// Function to set integer uniform
void Shader::setInt(const std::string &name, int value) const {
  unsigned int loc = glGetUniformLocation(id, name.c_str());
  glUniform1i(loc, value);
}

// Function to set float uniform
void Shader::setFloat(const std::string &name, float value) const {
  unsigned int loc = glGetUniformLocation(id, name.c_str());
  glUniform1f(loc, value);
}
