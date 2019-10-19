#pragma once
#include "RawModel.hpp"
#include "ModelTexture.hpp"

class TexturedModel
{
private:
    /* data */
public:
    TexturedModel(RawModel p_rawModel,ModelTexture p_texture);
    ~TexturedModel();
    RawModel rawModel;
    ModelTexture texture;
};
