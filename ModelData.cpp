#include "ModelData.hpp"

ModelData::ModelData(
		std::vector<GLfloat>& vertices,
		std::vector<GLfloat>& textureCoords,
		std::vector<GLfloat>& normals,
		std::vector<GLuint>& indices,
		GLfloat furthestPoint)
{
	for (int i = 0; i < (int) vertices.size(); i++) {
		this->vertices.push_back(vertices[i]);
	}
	for (int i = 0; i < (int) textureCoords.size(); i++) {
		this->textureCoords.push_back(textureCoords[i]);
	}
	for (int i = 0; i < (int) normals.size(); i++) {
		this->normals.push_back(normals[i]);
	}
	for (int i = 0; i < (int) indices.size(); i++) {
		this->indices.push_back(indices[i]);
	}
	this->furthestPoint = furthestPoint;
}

std::vector<GLfloat>& ModelData::getVertices()
{
	return vertices;
}
 
std::vector<GLfloat>& ModelData::getTextureCoords()
{
	return textureCoords;
}
 
std::vector<GLfloat>& ModelData::getNormals()
{
	return normals;
}
 
std::vector<GLuint>& ModelData::getIndices()
{
		return indices;
}
 
GLfloat ModelData::getFurthestPoint()
{
	return furthestPoint;
}
