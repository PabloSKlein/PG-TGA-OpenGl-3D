#pragma once

// Internal
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <math.h>
#include "Group.h"
#include <vector>

using namespace std;

class Mesh
{
public:
	Mesh();
	~Mesh();

	vector<Group*> groups;

	vector<glm::vec2 *> mappings;
	vector<glm::vec3 *> vertex;
	vector<glm::vec3 *> normals;

	void AddGroup();
	void AddGroup(std::string name);
	void AddGroup(std::vector<int> vertexIndices, std::vector<int> normalIndices, std::vector<int> mappingIndices);
	void AddVertex(glm::vec3 vertex);
	void AddNormal(glm::vec3 normal);
	void AddMapping(glm::vec2 mapping);


};

