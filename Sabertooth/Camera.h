#ifndef CAMERA_H
#define CAMERA_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

using namespace glm;

// Possiveis posições da camera
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	right
};

// Valores padrões da camera
//YAW ângulo direita e esquerda
const float YAW = -90.0f;
//PITCHA ângulo cima e baixo
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
public:
	vec3 position;
	vec3 front;
	vec3 up;
	vec3 right;
	vec3 worldUp;

	float Yaw;
	float Pitch;

	float movementSpeed;
	float mouseSensitivity;
	float Zoom;

	Camera(vec3 position, vec3 up, float yaw = YAW, float pitch = PITCH) : front(vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), Zoom(ZOOM)
	{
		this->position = position;
        this->worldUp = up;
        this->Yaw = yaw;
        this->Pitch = pitch;
        updateCameraVectors();
	}

	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : front(vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), Zoom(ZOOM)
	{
		this->position = vec3(posX, posY, posZ);
		this->worldUp = vec3(upX, upY, upZ);
		this->Yaw = yaw;
		this->Pitch = pitch;
		updateCameraVectors();
	}

	// Transforma coordenados no espaço para 2D
	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(position, position + front, up);
	}

	//Interação com teclado. Delta time = tempo entre os frames
	void ProcessKeyboard(Camera_Movement direction, float deltaTime)
	{
		float velocity = movementSpeed * deltaTime;
		if (direction == FORWARD)
			position += front * velocity;
		if (direction == BACKWARD)
			position -= front * velocity;
		if (direction == LEFT)
			position -= right * velocity;
		if (direction == right)
			position += right * velocity;
	}

	// Processando o movimento do mouse nas coordenadas x e y
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= mouseSensitivity;
		yoffset *= mouseSensitivity;

		Yaw += xoffset;
		Pitch += yoffset;

		// Impede ângulo maior que 90 graus para tela não virar
		if (constrainPitch)
		{
			if (Pitch > 89.0f)
				Pitch = 89.0f;
			if (Pitch < -89.0f)
				Pitch = -89.0f;
		}

		// Atualiza coordenadas front, right e up
		updateCameraVectors();
	}

	// Entradas pelo "scroll" do mouse
	void ProcessMouseScroll(float yoffset)
	{
		if (Zoom >= 1.0f && Zoom <= 45.0f)
			Zoom -= yoffset;
		if (Zoom <= 1.0f)
			Zoom = 1.0f;
		if (Zoom >= 45.0f)
			Zoom = 45.0f;
	}

	 GLfloat getZoom() {
		return this->Zoom;
	}

	// Calcula posição da camera de acordo com os angulos de Euler
	void updateCameraVectors()
	{
		vec3 front;
		front.x = cos(radians(Yaw)) * cos(radians(Pitch));
		front.y = sin(radians(Pitch));
		front.z = sin(radians(Yaw)) * cos(radians(Pitch));
		front = normalize(front);

		right = normalize(cross(front, worldUp)); // Normaliza os vetores, quando mais próximo, mais perto do zero.
		up = normalize(cross(right, front));
	}
};
#endif