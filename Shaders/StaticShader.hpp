#pragma once
#include "ShaderProgram.hpp"
#include "Camera.hpp"

class StaticShader : public ShaderProgram
{
private:
    /* data */
public:
    StaticShader(/* args */);
    virtual ~StaticShader();
    virtual void BindAttributes();
    virtual void LoadAllUniformLocations();
    void LoadTransformationMatrix(const glm::mat4 &mat) const;
    void LoadProjectionMatrix(const glm::mat4 &mat) const;
    void LoadViewMatrix(const Camera &camer) const;

  protected:
};
