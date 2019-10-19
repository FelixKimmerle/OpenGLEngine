#include "Renderer.hpp"

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include "Maths.hpp"

#define FOV 70
#define NEAR_PLANE 0.1f
#define FAR_PLANE 1000

Renderer::Renderer(const DisplayManager *dpm, const StaticShader *shader) : projectionMatrix(0)
{
    createProjectionMatrix(dpm->GetAspectRatio());
    shader->Use();
    shader->LoadProjectionMatrix(projectionMatrix);
    shader->UnUse();
}

Renderer::~Renderer()
{
}

void Renderer::prepare()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Renderer::render(const Entity &entity, const StaticShader &shader)
{
    glBindVertexArray(entity.model.rawModel.vaoID);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glm::mat4 transformationMatrix = createTransformationMatrix(entity.position, entity.rotation, entity.scale);
    shader.LoadTransformationMatrix(transformationMatrix);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, entity.model.texture.textureID);
    glDrawElements(GL_TRIANGLES, entity.model.rawModel.vertexCount, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

void Renderer::createProjectionMatrix(float aspectRatio)
{
    float y_scale = (float)((1.0 / tan(glm::radians(FOV / 2.0))));
    float x_scale = y_scale / aspectRatio;
    float frustrum_length = FAR_PLANE - NEAR_PLANE;

    projectionMatrix[0][0] = x_scale;
    projectionMatrix[1][1] = y_scale;
    projectionMatrix[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustrum_length);
    projectionMatrix[2][3] = -1;
    projectionMatrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustrum_length);
    projectionMatrix[3][3] = 0;
}