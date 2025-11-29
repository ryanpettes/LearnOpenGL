#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
  // Shader program's ID
  unsigned int id;

  // Constructor reads and builds the shader
  Shader(const char *vertexPath, const char *fragmentPath);

  // Use/activate this shader
  void use();

  // Utility functions for manipulating uniforms
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
};

#endif