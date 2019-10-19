#include "Loader.hpp"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Loader::Loader(/* args */)
{
}

Loader::~Loader()
{
    glDeleteVertexArrays(vaos.size(), &vaos[0]);
    glDeleteBuffers(vbos.size(), &vbos[0]);
    glDeleteTextures(textures.size(), &textures[0]);
}

unsigned int Loader::createVAO()
{
    unsigned int vaoID;
    glGenVertexArrays(1, &vaoID);
    vaos.push_back(vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}
void Loader::storeDataInAttributeList(unsigned int num, unsigned int coordinateSize, const void *data, unsigned int size)
{
    unsigned int vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glVertexAttribPointer(num, coordinateSize, GL_FLOAT, false, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void Loader::unbindVAO()
{
    glBindVertexArray(0);
}
#include "OBJFileLoader.h"
RawModel Loader::LoadOBJ(const std::string &fileName)
{
    OBJFileLoader loader;

    return loader.loadOBJ("res/" + fileName + ".obj", *this);
}

RawModel Loader::loadToVAO(const std::vector<float> &positions, const std::vector<float> &textureCoords, const std::vector<float> &normals, const std::vector<unsigned int> &indices)
{
    unsigned int vaoID = createVAO();
    bindIndicesBuffer(indices);
    storeDataInAttributeList(0, 3, &positions[0], positions.size() * sizeof(GLfloat));
    storeDataInAttributeList(1, 2, &textureCoords[0], textureCoords.size() * sizeof(GLfloat));
    unbindVAO();
    return RawModel(vaoID, indices.size());
}

void Loader::bindIndicesBuffer(const std::vector<unsigned int> &indices)
{
    unsigned int vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);
}

unsigned int Loader::loadTexture(const std::string &fileName)
{
    sf::Image img_data;
    if (!img_data.loadFromFile("res/" + fileName + ".png"))
    {
        std::cout << "Could not load: " << fileName << std::endl;
        return 0;
    }
    GLuint textureID;
    glGenTextures(1, &textureID);
    textures.push_back(textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA,
        img_data.getSize().x, img_data.getSize().y,
        0,
        GL_RGBA, GL_UNSIGNED_BYTE, img_data.getPixelsPtr());

    return textureID;
}
