#pragma once
#include "RawModel.hpp"
#include <vector>
#include <string>
#include <glm/glm.hpp>

class Loader
{
private:
  unsigned int createVAO();
  void storeDataInAttributeList(unsigned int num, unsigned int coordinateSize, const void *data, unsigned int size);
  void unbindVAO();
  void bindIndicesBuffer(const std::vector<unsigned int> &indices);

  std::vector<unsigned int> vaos;
  std::vector<unsigned int> vbos;
  std::vector<unsigned int> textures;

public:
  Loader(/* args */);
  ~Loader();
  RawModel loadToVAO(const std::vector<float> &positions, const std::vector<float> &textureCoords,const std::vector<float> &normals, const std::vector<unsigned int> &indices);
  RawModel LoadOBJ(const std::string &file);
  unsigned int loadTexture(const std::string &fileName);
};
