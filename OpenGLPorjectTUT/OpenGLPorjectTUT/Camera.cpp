#include "Camera.h"


extern GLFWwindow* global_window;


void Camera::CameraMouseNavigation(float _xOffset, float _yOffset)
{



	_xOffset *= MouseSensitivity;
	_yOffset *= MouseSensitivity;

	Yaw += _xOffset;
	Pitch += _yOffset;

	if (Pitch > 89.0f) // these two if statements make sure that when you look down or up you dont reverse the view upon yourself
	{
		Pitch = 89.0f;
	}
	if (Pitch < -89.0f)
	{
		Pitch = -89.0f;
	}
}

void Camera::Update(float _deltaTime) 
{
	glm::vec3 m_forwardVec;
	m_forwardVec.x = cos(glm::radians(Pitch)) * cos(glm::radians(Yaw));
	m_forwardVec.y = sin(glm::radians(Pitch));
	m_forwardVec.z = cos(glm::radians(Pitch)) * sin(glm::radians(Yaw));

	Front = glm::normalize(m_forwardVec);
	Position = inputManager.CameraKeyboardProcessing(Position, Front, Up, _deltaTime);
	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
	
	

}

glm::vec3 Camera::CameraMovementProcessing()
{

	return glm::vec3();
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Front, Up);
}

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::CameraMouseScroll(float _yOffset)
{
	if (Zoom >= 1.0f && Zoom <= 45.0f)
	{
		Zoom -= _yOffset;
	}
	if (Zoom <= 1.0f)
	{
		Zoom = 1.0f;
	}
	if (Zoom >= 45.0f)
	{
		Zoom = 45.0f;
	}
}
