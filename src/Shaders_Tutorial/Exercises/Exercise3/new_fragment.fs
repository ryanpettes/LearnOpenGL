// See new_vertex.vs for more info

#version 330 core
in vec4 forwardedPos;

out vec4 FragColor;

void main() {
  FragColor = forwardedPos;
}