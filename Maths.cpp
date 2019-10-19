#include "Maths.hpp"

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 createTransformationMatrix(const glm::vec3 &translation,const glm::vec3 &rotation,const float scale)
{
    glm::mat4 tmatrix = glm::translate(glm::mat4(1.f), translation);
    tmatrix = glm::rotate(tmatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    tmatrix = glm::rotate(tmatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    tmatrix = glm::rotate(tmatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    tmatrix = glm::scale(tmatrix, glm::vec3(scale, scale, scale));
    return tmatrix;
}

glm::mat4 crateViewMatrix(const Camera &camera)
{
    glm::mat4 viewMatrix = glm::lookAt(camera.position, camera.position + glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
    viewMatrix = glm::translate(viewMatrix, -camera.position);
    viewMatrix = glm::rotate(viewMatrix, glm::radians(-camera.rotation.x), glm::vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(-camera.rotation.y), glm::vec3(0, 1, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(-camera.rotation.z), glm::vec3(0, 0, 1));
    return viewMatrix;
}
