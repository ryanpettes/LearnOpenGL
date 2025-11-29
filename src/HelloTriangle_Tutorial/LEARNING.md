# Lesson: Hello Triangle

## Overview

In this lesson, I learned how to draw my first triangle in OpenGL using vertex buffers (VBOs), vertex array objects (VAOs), element buffers (EBOs), and _(laughably simple)_ shaders.

---

## Key Concepts

- **Vertex Input** — How vertex data is sent from the CPU to the GPU.
- **Vertex Buffer Object (VBO)** — Stores vertex data in GPU memory.
- **Vertex Array Object (VAO)** — Keeps track of vertex attribute configurations.
- **Element Buffer Object (EBO)** - Stores indices of vertices to draw, helping avoid vertex repetition in VBOs.
- **Shaders** — Small programs (written in GLSL) that run on the GPU.
- **Render Loop** — The continuous loop responsible for drawing each frame.

---

## Boring Notes _(My Personal Yap Section :))_

This tutorial involved understanding key concepts in OpenGL, including **VAO**s (Vertex Attribute Objects), **VBO**s (Vertex Buffer Objects), and **EBO**s (Element Buffer Objects). The first end result was drawing a simple filled triangle on the screen, which involved creating a VAO and VBO. This required understanding what binding is and how binding works _(which I'll yap about shortly)_, how loading memory into VRAM is performed, and learning early on that OpenGL functions essentially like a giant "State Machine" (in which a VAO is almost like a 'state capture').

The final goal was to draw a rectangle to the screen, and this would naively be done by drawing two separate triangles––however, this incurs repetition in the `vertices[]` array _(as we'd require a total of 6 vertices to define two triangles, but we can clearly specify a rectangle with only 4 vertices)_. To avoid this, we make use of an **Element Buffer Object** (which is created and loaded very similarly to a VBO), and then specify the _order_ in which we would like to draw the vertices. This means we only need to store the 4 **unique** vertices, no repeats!

Finally, this tutorial introduced the concept of **shaders**, and in particular that OpenGL requires that we _at least_ define our own **vertex** and **fragment** shaders. These were both done using string literals inside of `main.cpp`, and the vertex shader simply forwarded vertex position info, while the fragment shader simply colored every fragment a predefined shade of orange.

<details>
  <summary>In-Depth Yapuccino</summary>
  
In order to draw anything on the screen, we need to provide the GPU with data about <i>what</i> should be drawn. This is the purpose of a <b>Vertex Buffer Object</b> (VBO) –– we create our vertex data on the CPU, and then once its created, we load in into VRAM for lightning-fast access when drawing our data.

However, since OpenGL is one giant state machine, we can have multiple VBOs. So, in order to be specific about what particular data we want to draw, we need to <b>bind</b> the desired VBO to set it as "active". Further, we need to specify how the GPU should interpret this data, which is where functions like <code>glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 \* sizeof(float), (void \*)0);</code> come in. Here, we specify how to read data for a particular vertex attribute.

At this stage, a vertex only has one attribute: its <b>position</b>. But later on, there could be much more info describing a vertex, like <i>color</i>, <i>normals</i>, <i>textures</i>, etc. This is why it's important that we tell the GPU not only what our data is, but also how to make sense of it. This is something that a <b>Vertex Attribute Object</b> (VAO) helps us with.

</details>

In the end, I learned a lot about the purpose and basic functionality of VAOs, VBOs, and EBOs. I also learned how to write the simplest versions of vertex and fragment shaders, as well as create a program, attach the shaders to them, and then actually _use_ that program when rendering.
