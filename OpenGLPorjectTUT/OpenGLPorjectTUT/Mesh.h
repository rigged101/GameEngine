#pragma once
#ifndef MESH_H
#define MESH_H
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <glad/glad.h>
#include "Component.h"

class Mesh : public Component
{

public:

	Mesh();
	~Mesh();
	float* GetCubeVertices();
	void CreateCubeMesh();
	int GetMeshVAO();
	int GetMeshVBO();

	unsigned int * GetMeshVAOPointer();
	unsigned int * GetMeshVBOPointer();


private:
	std::vector<int> m_VAOList;
	unsigned int VAO, VBO;

	float m_cubeVertices[288];

};


#endif // !MESH_H