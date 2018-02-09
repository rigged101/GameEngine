#pragma once
#include <iostream>
#include <glfw3.h>
#include <vector>
#include <string>
#include <glm\glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "EnjinKeys.h"

class Camera;

class Input
{
public:
	

	void ProcessInput();
	glm::vec3 CameraKeyboardProcessing( glm::vec3 _cameraPos, glm::vec3 _cameraFront, glm::vec3 _cameraUp, float _deltaTime);
	bool getKey(int keyCode);
	

	Input();
	~Input();

private:

};

