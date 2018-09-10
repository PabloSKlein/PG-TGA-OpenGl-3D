#pragma once

// GLM Includes
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

// Internal
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <math.h>

#include "Face.h"
#include <vector>

using namespace std;

enum GroupType
{
	NONE,
	EMPTY,
	V,
	V_T,
	V_N,
	V_T_N
};

class Group
{
public:
	Group();
	~Group();
	
	string name;
	string material;

	vector<Face*> faces;

	void SetName(std::string name) {
		this->name = name;
	};

	std::string GetName() {
		return name;
	};

	void AddFace(std::vector<int> vertexIndices, std::vector<int> normalIndices, std::vector<int> mappingIndices);

	std::vector<Face*> GetFaces() {
		return faces;
	}

};

