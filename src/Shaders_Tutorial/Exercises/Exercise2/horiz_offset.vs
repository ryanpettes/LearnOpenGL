// Shader to push triangle to the right by a
// horizontal offset specified by a uniform

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

uniform float horizOffset;

void main() {
  gl_Position = vec4(aPos.x + horizOffset, aPos.yz, 1.0);
  ourColor = aColor;
}