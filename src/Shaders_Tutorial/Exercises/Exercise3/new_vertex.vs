// Shader to forward position to Fragment shader,
// which will be used to color fragment

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 forwardedPos;

void main() {
  gl_Position = vec4(aPos, 1.0);
  forwardedPos = vec4(aPos, 1.0);
}