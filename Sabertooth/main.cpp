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
#include "Material.h"


Mesh *mesh;
Group *group;
Face *face;

vector<Material> materialLib;

void read() {

}

void drawScene() {

}

int main() {

	face = new Face;

	group = new Group();

	group->faces.push_back(face);

	/*for

		f = group->faces[i];
		for
			vi = f->verts[j];
			vec3* v = mesh->vertices[vi];

	mesh = new Mesh();*/



	//mesh->mappings.push_back(new glm::vec2(0, 0));
	//mesh->mappings[0]->x = 0;
	//vector<glm::vec2 *> vector_mappings = new vector<glm::vec2*>();
}