#include "Transform.h"



glm::vec3 Transform::GetPosition()
{

	return m_position;
}

void Transform::SetScale(glm::vec3 _scale)
{
	if (GetParent() != NULL)
	{
		std::shared_ptr<Transform> temp_transform = GetParent();

		while (temp_transform.get() != NULL)
		{
			m_scale = temp_transform->m_scale;
			temp_transform = temp_transform->GetParent();
		}

		m_scale = m_scale + _scale;
	}
	else
	{
		m_scale = _scale;
	}

}

glm::vec3 Transform::GetScale()
{
	return m_scale;
}

void Transform::SetRotation(float _rotation)
{
	if (GetParent() != NULL)
	{
		std::shared_ptr<Transform> temp_transform = GetParent();

		while (temp_transform.get() != NULL)
		{
			m_rotation = temp_transform->m_rotation;
			temp_transform = temp_transform->GetParent();
		}

		m_rotation = m_rotation + _rotation;
	}
	else
	{
		m_rotation = _rotation;
	}

}


float Transform::GetRotation()
{
	return m_rotation;
}

void Transform::SetRotationAxis(glm::vec3 _axis)
{
	m_rotationAxis = _axis;
}


void Transform::SetParent(std::shared_ptr<Transform> _transform)
{

	if (this->m_Parent.get() != NULL)
	{
		for (int i = 0; i < this->m_Parent->m_Children.size(); i++)
		{
			if (this->m_Parent->m_Children.at(i).get() == this)
			{
				this->m_Parent->m_Children.erase(this->m_Parent->m_Children.begin() + i);
				break;
			}
		}
	}

	if (_transform != NULL)
	{
		
		_transform->m_Children.push_back(shared_from_this());
	}

	
	this->m_Parent = _transform;
}

std::shared_ptr<Transform> Transform::GetParent()
{
	return m_Parent;
}

void Transform::DetachChildren()
{
	for (int i = 0; i < m_Children.size(); i++)
	{
		std::shared_ptr<Transform> m_child = m_Children.at(i);
		m_child->SetParent(NULL);
	}
	m_Children.clear();
}


Transform::Transform()
{

}


Transform::~Transform()
{
}

void Transform::SetModelMatrix()
{
	glm::mat4 _model = glm::mat4();

	_model = glm::translate(_model, GetPosition());
	_model = glm::rotate(_model, glm::radians(GetRotation()), m_rotationAxis);
	_model = glm::scale(_model, GetScale());

	m_model = _model;
	
}

glm::mat4 Transform::GetModelMatrix()
{
	return m_model;
}

void Transform::SetPosition(glm::vec3 _position)
{
	if (GetParent() != NULL)
	{
		std::shared_ptr<Transform> temp_transform = GetParent();

		while (temp_transform.get() != NULL)
		{
			m_position = temp_transform->m_position;
			temp_transform = temp_transform->GetParent();
		}

		m_position = m_position  + _position;
	}
	else
	{
		m_position = _position;
	}
}



void Transform::Rotate(float _angle)
{
	m_rotation += _angle;
}

void Transform::Translate(glm::vec3 _translate)
{
	localPosition.x += _translate.x;
	localPosition.y += _translate.y;
	localPosition.z += _translate.z;

}

void Transform::Scale(glm::vec3 _scale)
{
	m_scale += _scale;
}
