#include "Input.h"




Input::Input()
{

}


Input::~Input()
{

}

extern GLFWwindow* global_window;


void Input::ProcessInput()
{	

	if (glfwGetKey(global_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(global_window, true);
	}
	if (glfwGetKey(global_window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		std::cout << "\n\nSpace Pressed Polling" <<  std::endl;
	}

}


glm::vec3 Input::CameraKeyboardProcessing(glm::vec3 _cameraPos, glm::vec3 _cameraFront, glm::vec3 _cameraUp, float  _deltaTime)
{

	float cameraSpeed = 2.5f * _deltaTime;


	if (getKey(ENJIN_KEY_D) == true && getKey(ENJIN_KEY_W) == true)
	{
		return _cameraPos += (glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_A) == true && getKey(ENJIN_KEY_W) == true)
	{
		return _cameraPos += (-glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_Z) == true && getKey(ENJIN_KEY_S) == true)
	{
		return _cameraPos += (-_cameraUp * cameraSpeed) + (-cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_X) == true && getKey(ENJIN_KEY_S) == true)
	{
		return _cameraPos += (_cameraUp * cameraSpeed) + (-cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_Z) == true && getKey(ENJIN_KEY_W) == true)
	{
		return _cameraPos += (-_cameraUp * cameraSpeed) + (cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_X) == true && getKey(ENJIN_KEY_W) == true)
	{
		return _cameraPos += (_cameraUp * cameraSpeed) + (cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_A) == true && getKey(ENJIN_KEY_S) == true)
	{
		return _cameraPos += (-glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (-cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_D) == true && getKey(ENJIN_KEY_S) == true)
	{
		return _cameraPos += (glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (-cameraSpeed * _cameraFront);
	}
	if (getKey(ENJIN_KEY_D) == true && getKey(ENJIN_KEY_X) == true)
	{
		return _cameraPos += (glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (_cameraUp * cameraSpeed);
	}
	if (getKey(ENJIN_KEY_D) == true && getKey(ENJIN_KEY_Z) == true)
	{
		return _cameraPos += (glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (-_cameraUp * cameraSpeed);
	}
	if (getKey(ENJIN_KEY_A) == true && getKey(ENJIN_KEY_Z) == true)
	{
		return _cameraPos += (-glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (-_cameraUp * cameraSpeed);
	}
	if (getKey(ENJIN_KEY_A) == true && getKey(ENJIN_KEY_X) == true)
	{
		return _cameraPos += (-glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed) + (_cameraUp * cameraSpeed);
	}
	if (getKey(ENJIN_KEY_W) == true)
	{
		return _cameraPos += cameraSpeed * _cameraFront;
	}
	if (getKey(ENJIN_KEY_S) == true)
	{
		return _cameraPos -= cameraSpeed * _cameraFront;
	}
	if (getKey(ENJIN_KEY_A) == true)
	{
		//std::cout << "blablabal" << std::endl;
		return _cameraPos -= glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed;
	}
	if (getKey(ENJIN_KEY_D) == true)
	{
		return _cameraPos += glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed;
	}
	if (getKey(ENJIN_KEY_Z) == true)
	{
		return _cameraPos -= _cameraUp * cameraSpeed;
	}
	if (getKey(ENJIN_KEY_X) == true)
	{
		return _cameraPos += _cameraUp * cameraSpeed;
	}




	return _cameraPos;

}



bool Input::getKey(int keyCode)
{
	return glfwGetKey(global_window, keyCode);
}



