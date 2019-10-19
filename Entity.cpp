#include "Entity.hpp"

Entity::Entity(TexturedModel p_model, glm::vec3 p_position, glm::vec3 p_rotation, float p_scale) : model(p_model), position(p_position), rotation(p_rotation), scale(p_scale)
{
}

Entity::~Entity()
{
}

void Entity::Move(const glm::vec3 offset)
{
    position += offset;
}
void Entity::Rotate(const glm::vec3 offset)
{
    rotation += offset;
}