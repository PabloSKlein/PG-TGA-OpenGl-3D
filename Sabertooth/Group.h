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

class Group
{
public:
	Group();
	~Group();
	
	string name;
	string material;

	vector<Face*> faces;
};

