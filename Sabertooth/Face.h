#pragma once

#include <GL/glew.h> /* include GLEW and new version of GL on Windows */
#include <GLFW/glfw3.h> /* GLFW helper library */
#include <stdio.h>
#include <math.h>

// GLM Includes
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>


#include <vector>

using namespace std;
class Face
{
public:
	Face();

	Face(std::vector<int> vertsArr, std::vector<int> normsArr, std::vector<int> textsArr) {
		verts = vertsArr;
		norms = normsArr;
		texts = textsArr;
	}

	~Face();

	vector<int> verts;
	vector<int> norms;
	vector<int> texts;
	 
};

