#pragma once
#include <memory>
#include <vector>
#include "Object.h"
#include "Transform.h"
#include "Input.h"
#include "Mesh.h"
#include "Renderer.h"
#include "GameObject.h"
#include "Component.h"
#include "Camera.h"
#include "Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <glad\glad.h>



class Application
{

private:
	std::vector<std::shared_ptr<GameObject>> listOfGameObjects;


public:

	Input* inputClass = new Input;

	int InitMain();
	void Update();

	Application();
	~Application();

};

