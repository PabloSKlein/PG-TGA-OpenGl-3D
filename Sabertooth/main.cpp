#include <GL/glew.h> /* include GLEW and new version of GL on Windows */
#include <GLFW/glfw3.h> /* GLFW helper library */
#include <stdio.h>
#include <math.h>

// GLM Includes
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Mesh.h"
#include "Group.h"
#include "Face.h"


Mesh *mesh;
Group *group;
Face *face;

void read() {

}

void drawScene() {

}

int main() {
	mesh = new Mesh();
	group = new Group();
	face = new Face();

	face->norms = glm::vec2(1.0f)

	mesh->groups = 

}