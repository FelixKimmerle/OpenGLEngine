#pragma once
#include "Entity.hpp"
#include "Shaders/StaticShader.hpp"
#include "DisplayManager.hpp"

class Renderer
{
  private:
    glm::mat4 projectionMatrix;

  public:
    Renderer(const DisplayManager *dpm, const StaticShader *shader);
    ~Renderer();
    void prepare();
    void render(const Entity &entity, const StaticShader &shader);
    void createProjectionMatrix(float aspectRatio);
};
