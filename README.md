# LearnOpenGL Journey

This is a repository to document my progress as I learn modern OpenGL using **C++** and **GLSL** _(and any other tools I might encounter along the way)_. I am following the [LearnOpenGL](https://learnopengl.com) tutorial, and supplementing this with the **amazing** [OpenGL playlist by TheCherno](https://www.youtube.com/playlist?list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2) on YouTube.

### Progress

<details>
  <summary><b>Getting Started</b></summary>

- [x] Hello Window
- [x] Hello Triangle
- [ ] Shaders
- [ ] Textures
- [ ] Transformations
- [ ] Coordinate Systems
- [ ] Camera

</details>

<details>
  <summary><b>Lighting</b></summary>

- [ ] Colors
- [ ] Basic Lighting
- [ ] Materials
- [ ] Lighting Maps
- [ ] Light Casters
- [ ] Multiple Lights

</details>

<details>
  <summary><b>Model Loading</b></summary>

- [ ] Assimp
- [ ] Mesh
- [ ] Model

</details>

<details>
  <summary><b>Advanced OpenGL</b></summary>

- [ ] Depth Testing
- [ ] Stencil Testing
- [ ] Blending
- [ ] Face Culling
- [ ] Framebuffers
- [ ] Cubemaps
- [ ] Advanced Data
- [ ] Advanced GLSL
- [ ] Geometry Shader
- [ ] Instancing
- [ ] Anti Aliasing

</details>

<details>
  <summary><b>Advanced Lighting</b></summary>

- [ ] Advanced Lighting
- [ ] Gamma Correction
- [ ] Shadows
  - [ ] Shadow Mapping
  - [ ] Point Shadows
- [ ] Normal Mapping
- [ ] Parallax Mapping
- [ ] HDR
- [ ] Bloom
- [ ] Deferred Shading
- [ ] SSAO

</details>

<details>
  <summary><b>PBR (Physically Based Rendering)</b></summary>

- [ ] Theory
- [ ] Lighting
- [ ] IBL
  - [ ] Diffuse Irradiance
  - [ ] Specular IBL

</details>

<details>
  <summary><b>In Practice</b></summary>

- [ ] Debugging
- [ ] Text Rendering
- [ ] 2D Game
  - [ ] Breakout
  - [ ] Setting Up
  - [ ] Rendering Sprites
  - [ ] Levels
  - [ ] Collisions
    - [ ] Ball
    - [ ] Collision Detection
    - [ ] Collision Resolution
  - [ ] Particles
  - [ ] Postprocessing
  - [ ] Powerups
  - [ ] Audio
  - [ ] Render Text
  - [ ] Final Thoughts

</details>

Each folder contains the source code _(if any)_ at the end-of-tutorial stage, accompanying exercises _(if any)_, and notes about what I learned _(always something :))_. This is going to be **a lot** of information, and I really want to emphasize a deep understanding, so progress might be slow.

---

### Goals

- Deepen understanding of GPU pipelines and shader programming
- Create something beautiful from the ground up :)
- Understand the inner workings of GPU programming
  - This includes the low-level details of going from raw vertex data to an image on the screen
- Build a small personal visualization or graphics project at the end

### Setup

To build and run examples _(hopefully this is correct, if not let me know and I'll look into it)_:

```bash
  mkdir build && cd build
  cmake ..
  make
  ./hello_window
```

### Resources

I will update this as I come across new learning materials, but for now this is a list of all the materials I've found helpful so far:

- [LearnOpenGL.com](https://learnopengl.com) — main tutorial series
- [TheCherno's OpenGL YouTube Playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2) — great video supplement for visual learners
