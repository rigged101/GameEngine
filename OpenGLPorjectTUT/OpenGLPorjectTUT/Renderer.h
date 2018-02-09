#pragma once
#include "Component.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <glad/glad.h>
#include "ShaderLoader.h"
#include "Camera.h"
#include "Transform.h"
#include "Mesh.h"
#include "Texture.h"

class Renderer : public Component
{
	

private:
	ShaderLoader m_Shader;
	ShaderLoader GetShader();
	glm::vec3 m_lightPosition;
public:
	void SetLightPosition(glm::vec3 _lightPos);
	void SetShader(ShaderLoader _shader);
	void Render(Camera *_camera, std::shared_ptr<Transform> _transform, std::shared_ptr<Mesh> _mesh, std::shared_ptr<Texture> _texture);
	void Render(Camera *_camera, std::shared_ptr<Transform> _transform, std::shared_ptr<Mesh> _mesh);

	Renderer();
	~Renderer();
};

