#ifndef VERTEX_H
#define VERTEX_H
#include <vector>
#include <glm/glm.hpp>
class Vertex {
public:
	Vertex(int index, glm::vec3 position);
	void addTangent(glm::vec3 tangent);
	void averageTangents();
	glm::vec3 getAverageTangent();
	int getIndex();
	float getLength();
	bool isSet();
	bool hasSameTextureAndNormal(int textureIndexOther, int normalIndexOther);
	void setTextureIndex(int textureIndex);
	void setNormalIndex(int normalIndex);
	glm::vec3& getPosition();
	int getTextureIndex();
	int getNormalIndex();
	Vertex* getDuplicateVertex();
	void setDuplicateVertex(Vertex* duplicateVertex);

private:
	static constexpr int NO_INDEX = -1;
	glm::vec3 position;
	int textureIndex = NO_INDEX;
	int normalIndex = NO_INDEX;
	Vertex *duplicateVertex = nullptr;
	int index;
	float length;
	std::vector<glm::vec3> tangents;
	glm::vec3 averagedTangent;
};


#endif
