#pragma once

#include <glm/glm.hpp>
#include "Camera.hpp"

glm::mat4 createTransformationMatrix(const glm::vec3 &translation,const glm::vec3 &rotation,const float scale); 
glm::mat4 crateViewMatrix(const Camera &camera);