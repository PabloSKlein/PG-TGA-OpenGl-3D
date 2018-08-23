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

	vector<Group*> *groups;

	vector<glm::vec2 *> *mappings;
	glm::vec3 vertex;
	glm::vec3 normals;



};

