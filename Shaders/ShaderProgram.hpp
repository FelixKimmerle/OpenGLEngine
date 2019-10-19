#pragma once

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>
#include <string>
#include <map>

class ShaderProgram
{
public:
  ShaderProgram();
  void LoadFiles(const std::string &fileName);
  virtual ~ShaderProgram();
  inline void Use() const { glUseProgram(m_programID); }
  inline void UnUse() const { glUseProgram(0); }

private:
  GLuint m_programID;
  GLuint m_vertexShaderID;
  GLuint m_fragmentShaderID;

  GLuint LoadShader(const std::string &fileName, GLenum type);

  std::map<std::string, unsigned int> uniformVariables;

protected:
  virtual void BindAttributes() = 0;
  virtual void LoadAllUniformLocations() = 0;
  void BindAttribute(int attribute, const std::string &variableName);
  void LoadUniformVariable(const std::string &name);
  void LoadFloat(const GLuint &location, const float &value) const;
  void LoadVector(const GLuint &location, const glm::vec3 &value) const;
  void LoadBool(const GLuint &location, const bool &value) const;
  void LoadMatrix4(const GLuint &location, const glm::mat4 &matrix) const;
  unsigned int GetUniformLocation(const std::string &name) const;
};
