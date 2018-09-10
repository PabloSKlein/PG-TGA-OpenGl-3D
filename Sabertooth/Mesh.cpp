#include "Mesh.h"



Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::AddGroup()
{
	Group* newGroup = new Group();
	groups.push_back(newGroup);
}

void Mesh::AddGroup(std::string name)
{
	Group* newGroup = new Group();
	newGroup->SetName(name);
	groups.push_back(newGroup);
}

void Mesh::AddGroup(std::vector<int> vertexIndices, std::vector<int> normalIndices, std::vector<int> mappingIndices)
{
	Group* newGroup = new Group();
	newGroup->AddFace(vertexIndices, normalIndices, mappingIndices);
	groups.push_back(newGroup);
}

void Mesh::AddVertex(glm::vec3 vertex)
{
	glm::vec3* newVertex = new glm::vec3(vertex);
	this->vertex.push_back(newVertex);
}

void Mesh::AddNormal(glm::vec3 normal)
{
	glm::vec3* newNormal = new glm::vec3(normal);
	normals.push_back(newNormal);
}

void Mesh::AddMapping(glm::vec2 mapping)
{
	glm::vec2* newMapping = new glm::vec2(mapping);
	mappings.push_back(newMapping);
}
