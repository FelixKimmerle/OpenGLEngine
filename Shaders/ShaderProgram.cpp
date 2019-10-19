#include "ShaderProgram.hpp"
#include <fstream>
#include <iostream>

void ShaderProgram::LoadFiles(const std::string &fileName)
{
    // Load shaders from file
    m_vertexShaderID = LoadShader(fileName + "vert.glsl", GL_VERTEX_SHADER);
    m_fragmentShaderID = LoadShader(fileName + "frag.glsl", GL_FRAGMENT_SHADER);

    // Create shader program
    m_programID = glCreateProgram();
    // Attach the shaders to the program
    glAttachShader(m_programID, m_vertexShaderID);
    glAttachShader(m_programID, m_fragmentShaderID);

    BindAttributes();
    // Link the program
    glLinkProgram(m_programID);
    glValidateProgram(m_programID);

    // Check validation status
    GLint status;
    glGetProgramiv(m_programID, GL_VALIDATE_STATUS, &status);
    if (status == GL_FALSE)
    {
        // Get info log length
        GLint infoLogLength;
        glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
        // Get the info log
        GLchar *infoLog = new GLchar[infoLogLength];
        glGetProgramInfoLog(m_programID, infoLogLength, NULL, infoLog);
        printf("ERROR: could not validate program:%s \n%s\n", fileName.c_str(), infoLog);
        // Delete the array
        delete[] infoLog;
    }
    LoadAllUniformLocations();
}

ShaderProgram::ShaderProgram()
{
}

ShaderProgram::~ShaderProgram()
{
    // Make sure we are not using this shader
    UnUse();
    // Detach the shaders from the program
    glDetachShader(m_programID, m_vertexShaderID);
    glDetachShader(m_programID, m_fragmentShaderID);
    // Delete the shaders
    glDeleteShader(m_vertexShaderID);
    glDeleteShader(m_fragmentShaderID);
    // Delete the program
    glDeleteProgram(m_programID);
}

GLuint ShaderProgram::LoadShader(const std::string &fileName, GLenum type)
{

    std::ifstream t(fileName);
    std::string str;

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());

    // Create shader ID
    GLuint shaderID = glCreateShader(type);

    // Prepare source for OpenGL
    const GLchar *sourceStrings[1];
    GLint sourceLengths[1];
    sourceStrings[0] = str.c_str();
    sourceLengths[0] = str.length();

    // Load source to OpenGL and compile
    glShaderSource(shaderID, 1, sourceStrings, sourceLengths);
    glCompileShader(shaderID);

    // Check compile status
    GLint status;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        // Get info log length
        GLint infoLogLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        // Get the info log
        GLchar *infoLog = new GLchar[infoLogLength];
        glGetShaderInfoLog(shaderID, infoLogLength, NULL, infoLog);
        printf("ERROR: could not compile shader \n%s\n", infoLog);
        // Delete the array
        delete[] infoLog;
    }

    return shaderID;
}

void ShaderProgram::BindAttribute(int attribute, const std::string &variableName)
{
    glBindAttribLocation(m_programID, attribute, variableName.c_str());
}

void ShaderProgram::LoadUniformVariable(const std::string &name)
{
    unsigned int id = glGetUniformLocation(m_programID, name.c_str());
    std::cout << "Load: " << name << " ID: " << id << std::endl;
    uniformVariables.insert(std::make_pair(name, id));
}

void ShaderProgram::LoadFloat(const GLuint &location, const float &value) const
{
    glUniform1f(location, value);
}

void ShaderProgram::LoadVector(const GLuint &location, const glm::vec3 &value) const
{
    glUniform3f(location, value.x, value.y, value.z);
}

void ShaderProgram::LoadBool(const GLuint &location, const bool &value) const
{
    // if value == true load 1 else 0
    glUniform1f(location, value ? 1.0f : 0.0f);
}

void ShaderProgram::LoadMatrix4(const GLuint &location, const glm::mat4 &matrix)const
{
    glUniformMatrix4fv(location, 1, false, &matrix[0][0]);
}

unsigned int ShaderProgram::GetUniformLocation(const std::string &name)const
{
    return uniformVariables.at(name);
}
