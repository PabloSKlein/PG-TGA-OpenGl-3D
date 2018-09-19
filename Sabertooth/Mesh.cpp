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

void Mesh::addVertexItem(glm::vec3* vertex)
{
	this->vertex.push_back(vertex);
}

void Mesh::addNormalItem(glm::vec3* normal)
{
	normals.push_back(normal);
}

void Mesh::addMappingItem(glm::vec2* mapping)
{
	mappings.push_back(mapping);
}
