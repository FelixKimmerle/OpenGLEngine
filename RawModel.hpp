#pragma once


class RawModel
{
private:
    /* data */
public:
    RawModel(unsigned int p_vaoID,unsigned int p_vertexCount);
    ~RawModel();
    unsigned int vaoID;
    unsigned int vertexCount;
};
