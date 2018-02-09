#pragma once
#ifndef SHADERLOADER_H
#define SHADERLOADER_H


#include <glad\glad.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <glfw3.h>
#include <glm/glm.hpp>
#include "Component.h"

class ShaderLoader : public Component

{
public:
	// the program ID
	unsigned int ID;
	ShaderLoader();
	ShaderLoader(const GLchar* vertexPath, const GLchar* fragmentPath);

	void Use();
	unsigned int GetProgramID();

	// utility uniform functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setMat4(const std::string &name, const glm::mat4 &mat) const;
	void setVec3(const std::string &name, const glm::vec3 &value) const;

	~ShaderLoader();
};

#endif // !SHADERLOADER_H