#pragma once
#include <glm/glm.hpp>

class Camera
{
private:
    /* data */
public:
    Camera(/* args */);
    ~Camera();
    void Update();
    glm::vec3 position;
    glm::vec3 rotation;
};
