#include "Shaders/StaticShader.hpp"
#include <iostream>
#include "Maths.hpp"

StaticShader::StaticShader(/* args */)
{
    LoadFiles("Shaders/basic");
}

StaticShader::~StaticShader()
{
}

void StaticShader::BindAttributes()
{
    std::cout << "BIND" << std::endl;
    BindAttribute(0, "position");
    BindAttribute(1, "textureCoords");
}

void StaticShader::LoadAllUniformLocations()
{
    LoadUniformVariable("transformationMatrix");
    LoadUniformVariable("projectionMatrix");
    LoadUniformVariable("viewMatrix");
}
void StaticShader::LoadTransformationMatrix(const glm::mat4 &mat)const
{
    LoadMatrix4(GetUniformLocation("transformationMatrix"), mat);
}

void StaticShader::LoadProjectionMatrix(const glm::mat4 &mat) const
{
    LoadMatrix4(GetUniformLocation("projectionMatrix"), mat);
}

void StaticShader::LoadViewMatrix(const Camera &camera) const
{
    LoadMatrix4(GetUniformLocation("viewMatrix"), crateViewMatrix(camera));
}
