#include <GL/glew.h> /* include GLEW and new version of GL on Windows */
#include <GLFW/glfw3.h> /* GLFW helper library */
#include <stdio.h>
#include <math.h>

// GLM Includes
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Mesh.h"
#include "Group.h"
#include "Face.h"
#include "Material.h"
#include "Camera.h"

using namespace glm;

// screen
int WIDTH = 1280;
int HEIGHT = 800;

void KeyCallBack(GLFWwindow *window, int key, int scancode, int action, int mode);
void ScrollCallBack(GLFWwindow *window, double xoffset, double yoffset);
void DoMovement();

Camera camera(vec3(0.0f, 0.0f, 3.0f));


void read() {

	// Leitura do arquivo obj

}

void drawScene() {

	// Desenha na tela

}

int main() {

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
		-0.5f, -0.5, 0.0f,		//1.0f, 0.0f, 0.0f, //bottom left  //red
		0.5f, -0.5f, 0.0f,		//0.0f, 1.0f, 0.0f, //bottom right //green
		0.0f, 0.5f, 0.0f,		//0.0f, 0.0f, 1.0f  //middle top   //blue
	};


	///////// Leitura e gravação das meshs a partir dos vertices, normais e texturas
	///////// *** No caso aqui só vertices mesmo ***

	std::vector<Mesh*>* newMeshVector = new std::vector<Mesh*>();

	// Alterar depois: gerar um Mesh para cada triangulo, aqui no caso so tem um triangulo
	Mesh* newMesh = new Mesh();
	
	int i = 9;
	while (i < 9) {

		glm::vec3* newVertex = new glm::vec3();

		newVertex->x = vertices[i];
		newVertex->y = vertices[i];
		newVertex->z = vertices[i];

		newMesh->addVertexItem(newVertex);
		
	}
	newMeshVector->push_back(newMesh);


	///////// Leitura e gravação dos nomes de materiais


	/////////// Cria os grupos e linka com os materiais



	/////////// Bind todas as meshs


	/////////// Projection e camera

	
	
	///////// Loop gerar na tela

	while (!glfwWindowShouldClose(window)) {
		
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		///////// Model, view, projection, camera



		///////// Use shader

		ourShader.Use();


			

		///////// VAO



		///////// Iterar através de diferentes meshs
		//for () {


			///////// Iterar através dos grupos
			//for () {
				
					//glBindVertexArray((*group)->VAO());

					
					
					///////// Cair pra cada uma das texturas

					glEnable(GL_TEXTURE_2D);

						//if () {

							//////// Pega a textura

							//glUniform1i(textureLocation, textureId);
							//glBindTexture(GL_TEXTURE_2D, textureId);

						//}
					

					//glDrawArrays(GL_TRIANGLES, 0, (*group)->GetFacesSize() * 3);
					//glDisable(GL_TEXTURE_2D);


				//}
			//}
		//}

		//glfwSwapBuffers(window);
	//}
	
	///////// Deletar shader



	///////// Fecha a janela

	//glfwTerminate();


	}

}

