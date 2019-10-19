#pragma once
#include "TexturedModel.hpp"
#include <glm/glm.hpp>

class Entity
{
private:
    /* data */
public:
    Entity(TexturedModel model,glm::vec3 position,glm::vec3 rotation, float scale);
    ~Entity();
    void Move(const glm::vec3 offset);
    void Rotate(const glm::vec3 offset);
    TexturedModel model;
    glm::vec3 position;
    glm::vec3 rotation;
    float scale;
};
