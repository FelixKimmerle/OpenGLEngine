#ifndef MODELDATA_H
#define MODELDATA_H
#include <vector>
#include <SFML/OpenGL.hpp>
class ModelData
{
public:
	ModelData(
		std::vector<GLfloat>& vertices,
		std::vector<GLfloat>& textureCoords,
		std::vector<GLfloat>& normals,
		std::vector<GLuint>& indices,
		GLfloat furthestPoint);
	// TODO: destructor

	std::vector<GLfloat>& getVertices();
	std::vector<GLfloat>& getTextureCoords();
	std::vector<GLfloat>& getNormals();
	std::vector<GLuint>& getIndices();
	GLfloat getFurthestPoint();
private:
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> textureCoords;
	std::vector<GLfloat> normals;
	std::vector<GLuint> indices;
	GLfloat furthestPoint;
};

#endif
