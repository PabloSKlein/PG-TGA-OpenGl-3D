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
#include "Shader.h"

int WIDTH = 1280;
int HEIGHT = 800;

Mesh *mesh;
Group *group;
Face *face;

vector<Material> materialLib;

void read() {

	//leitura do arquivo obj

}

void drawScene() {

	//desenha na tela

}

int mainAnterior() {

	face = new Face;

	group = new Group();

	group->faces.push_back(face);


	///////// Gera a tela

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Trabalho GA", nullptr, nullptr);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (nullptr == window) {
		std::cout << "Falha ao criar janela GLFW" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Falha ao criar janela GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	glViewport(0, 0, screenWidth, screenHeight);

	///////// Carrega o shader

	Shader ourShader("Shaders/Core/core.vs", "Shaders/Core/core.fs");

	///////// Vertices

	GLfloat vertices[] = {
		//position				//color
		-0.5f, -0.5, 0.0f,		1.0f, 0.0f, 0.0f, //bottom left  //red
		0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f, //bottom right //green
		0.0f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f  //middle top   //blue
	};

	/*for
	f = group->faces[i];
	for
	vi = f->verts[j];
	vec3* v = mesh->vertices[vi];
	mesh = new Mesh();*/

	//mesh->mappings.push_back(new glm::vec2(0, 0));
	//mesh->mappings[0]->x = 0;
	//vector<glm::vec2 *> vector_mappings = new vector<glm::vec2*>();

	///////// Gera VAO e VBO

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//colors
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof GLfloat));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	///////// Loop gerar na tela

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//shaders
		ourShader.Use();

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	///////// Deleta os VAO e VBO atuais

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return EXIT_SUCCESS;

}