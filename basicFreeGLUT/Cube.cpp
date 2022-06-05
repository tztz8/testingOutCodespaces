#include "Cube.h"

// Math Lib
#define GLM_FORCE_RADIANS
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

unsigned int cube_vao;

void createCube() {
    float side = 0.5f;

    glm::vec4 cube_vertices[] = {{side, side, side, 1.0f},  // v0,v1,v2,v3 (front)
                                 {-side, side, side, 1.0f},
                                 {-side, -side, side, 1.0f},
                                 {side, -side, side, 1.0f},
                                 {side, side, side, 1.0f},  // v0,v3,v4,v5 (right)
                                 {side, -side, side, 1.0f},
                                 {side, -side, -side, 1.0f},
                                 {side, side, -side, 1.0f},
                                 {side, side, side, 1.0f},  // v0,v5,v6,v1 (top)
                                 {side, side, -side, 1.0f},
                                 {-side, side, -side, 1.0f},
                                 {-side, side, side, 1.0f},
                                 {-side, side, side, 1.0f}, // v1,v6,v7,v2 (left)
                                 {-side, side, -side, 1.0f},
                                 {-side, -side, -side, 1.0f},
                                 {-side, -side, side, 1.0f},
                                 {-side, -side, -side, 1.0f},// v7,v4,v3,v2 (bottom)
                                 {side, -side, -side, 1.0f},
                                 {side, -side, side, 1.0f},
                                 {-side, -side, side, 1.0f},
                                 {side, -side, -side, 1.0f},// v4,v7,v6,v5 (back)
                                 {-side, -side, -side, 1.0f},
                                 {-side, side, -side, 1.0f},
                                 {side, side, -side, 1.0f}};


    GLushort cube_indices[] = {0, 1, 2, 2, 3, 0,      // front
                               4, 5, 6, 6, 7, 4,      // right
                               8, 9, 10, 10, 11, 8,      // top
                               12, 13, 14, 14, 15, 12,      // left
                               16, 17, 18, 18, 19, 16,      // bottom
                               20, 21, 22, 22, 23, 20};    // back

    glm::vec3 cube_normals[6*4] = {
            // Front
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            // Right
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            // Top
            {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            // Left
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            // Bottom
            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            // Back
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f}
    };

    glm::vec2 cube_textures[] = { {0.75f, 2.0f/3.0f},  // v0,v1,v2,v3 (front)
                                  {0.5f, 2.0f/3.0f},
                                  {0.5f, 1.0f/3.0f},
                                  {0.75f, 1.0f/3.0f},


                                  {0.75f, 2.0f/3.0f},  // v0,v3,v4,v5 (right)
                                  {0.75f, 1.0f/3.0f},
                                  {1.0f, 1.0f/3.0f},
                                  {1.0f, 2.0f/3.0f},


                                  {0.75f, 2.0f/3.0f},  // v0,v5,v6,v1 (top)
                                  {0.75f, 1.0f},
                                  {0.5f, 1.0f},
                                  {0.5f, 2.0f/3.0f},

                                  {0.5f, 2.0f/3.0f}, // v1,v6,v7,v2 (left)
                                  {0.25f, 2.0f/3.0f},
                                  {0.25f, 1.0f/3.0f},
                                  {0.5f, 1.0f/3.0f},

                                  {0.5f, 0.0f},// v7,v4,v3,v2 (bottom)
                                  {0.75f, 0.0f},
                                  {0.75f, 1.0f/3.0f},
                                  {0.5f, 1.0f/3.0f},

                                  {0.25f, 1.0f/3.0f},// v4,v7,v6,v5 (back)
                                  {0.0f, 1.0f/3.0f},
                                  {0.0f, 2.0f/3.0f},
                                  {0.25f, 2.0f/3.0f} };

    glGenVertexArrays(1, &cube_vao);
    glBindVertexArray(cube_vao);

    unsigned int handle[4];
    glGenBuffers(4, handle);

    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint) 0, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);  // Vertex position

    glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_normals), cube_normals, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint) 1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(1);  // Vertex Normals

    glBindBuffer(GL_ARRAY_BUFFER, handle[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_textures), cube_textures, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(2);  // Vertex texture

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);

    glBindVertexArray(0);

}

void drawCube() {
    glBindVertexArray(cube_vao);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, nullptr);
}

