#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <memory>
#include <vector>
#include "Component.h"


class Transform : public Component, public std::enable_shared_from_this<Transform>
{


public:

	int m_test = 4;
	Transform();
	~Transform();


	void SetParent(std::shared_ptr<Transform> _transform);
	std::shared_ptr<Transform> GetParent();
	void DetachChildren();


	void SetModelMatrix();
	glm::mat4 GetModelMatrix();

	void SetPosition(glm::vec3 _position);
	glm::vec3 GetPosition();


	void SetScale(glm::vec3 _scale);
	glm::vec3 GetScale();

	void SetRotation(float _rotation);
	float GetRotation();
	
	void SetRotationAxis(glm::vec3 _axis);


	void Rotate(float _angle);
	void Translate(glm::vec3 _translate);
	void Scale(glm::vec3 _scale);

private:
	glm::vec3 m_scale;
	glm::vec3 m_rotationAxis;
	float m_rotation;
	glm::vec3 m_position;
	glm::mat4 m_model;
	std::shared_ptr<Transform> m_Parent;
	std::vector<std::shared_ptr<Transform>> m_Children;
	glm::vec3 localScale;
	glm::vec3 localRotation;
	glm::vec3 localPosition;

};


#endif // !TRANSFORM_H
