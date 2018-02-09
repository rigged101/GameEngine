#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}


void Renderer::SetLightPosition(glm::vec3 _lightPos)
{
	m_lightPosition = _lightPos;
}

void Renderer::SetShader(ShaderLoader _shader)
{
	m_Shader = _shader;
}

ShaderLoader Renderer::GetShader()
{
	return m_Shader;
}

void Renderer::Render(Camera *_camera, std::shared_ptr<Transform> _transform, std::shared_ptr<Mesh> _mesh, std::shared_ptr<Texture> _texture)
{


	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(_camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
	view = _camera->GetViewMatrix();

	GetShader().Use();
	GetShader().setInt("texmaterial.diffuse", 0);
	GetShader().setVec3("light.position", m_lightPosition);
	GetShader().setVec3("viewPos", _camera->Position);

	GetShader().setVec3("light.ambient", glm::vec3(0.2f, 0.2f, 0.2f));
	GetShader().setVec3("light.diffuse", glm::vec3(0.5f, 0.5f, 0.5f));
	GetShader().setVec3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));

	GetShader().setVec3("texMaterial.specular", glm::vec3(0.5f, 0.5f, 0.5f));
	GetShader().setFloat("texMaterial.shininess", 64.0f);

	GetShader().setMat4("projection", projection);
	GetShader().setMat4("view", view);

	GetShader().setMat4("model", _transform->GetModelMatrix());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture->GetDiffuseMap());

	glBindVertexArray(_mesh->GetMeshVAO());
	glDrawArrays(GL_TRIANGLES, 0, 36);



}

void Renderer::Render(Camera *_camera, std::shared_ptr<Transform> _transform, std::shared_ptr<Mesh> _mesh)
{


	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(_camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
	view = _camera->GetViewMatrix();


	GetShader().Use();
	GetShader().setMat4("projection", projection);
	GetShader().setMat4("view", view);


	GetShader().setMat4("model", _transform->GetModelMatrix());

	glBindVertexArray(_mesh->GetMeshVAO());
	glDrawArrays(GL_TRIANGLES, 0, 36);




}


