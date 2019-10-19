#ifndef OBJFILELOADER_H
#define OBJFILELOADER_H

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include "Vertex.hpp"
#include "ModelData.h"


#include "RawModel.hpp"
#include "Loader.hpp"

#include <vector>
#include <string>

#include <glm/glm.hpp>


class OBJFileLoader {
public:
	static RawModel loadOBJ(const std::string &objFileName, Loader& loader);
private:
	static void processVertex(
		int index,
		int textureIndex,
		int normalIndex,
		std::vector<Vertex*>& vertices,
		std::vector<GLuint>& indices);

	static GLfloat convertDataToArrays(
		std::vector<Vertex*>& vertices,
		std::vector<glm::vec2>& textures,
		std::vector<glm::vec3>& normals,
		std::vector<GLfloat>& verticesArray,
		std::vector<GLfloat>& texturesArray,
		std::vector<GLfloat>& normalsArray);

	static void dealWithAlreadyProcessedVertex(
		Vertex *previousVertex,
		int newTextureIndex,
		int newNormalIndex,
		std::vector<GLuint>& indices,
		std::vector<Vertex*>& vertices);

	static void removeUnusedVertices(std::vector<Vertex*>& vertices);
};

#endif
