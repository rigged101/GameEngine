#pragma once
#include <iostream>
#include <glfw3.h>
#include <vector>
#include <string>
#include <glm\glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "EnjinKeys.h"
#include "Input.h"


// initial camera paremeter values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVTY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
public:

	// Camera Attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;


	Input inputManager;

	float Yaw;
	float Pitch;


	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;


	//initialisation of the camera
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float _yaw = YAW, float _pitch = PITCH  ) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM)
	{
		Position = position;
		WorldUp = up;
		Yaw = _yaw;
		Pitch = _pitch;

	};



	Camera();
	~Camera();
	void CameraMouseScroll(float _yOffset);
	void CameraMouseNavigation(float _xOffset, float _yOffset);
	void Update(float _deltaTime);
	glm::vec3 CameraMovementProcessing();
	glm::mat4 GetViewMatrix();
};

