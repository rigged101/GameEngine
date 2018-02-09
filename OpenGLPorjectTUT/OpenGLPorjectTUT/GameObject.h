#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H



#include "Component.h"
#include <vector>
#include <memory>
#include <iostream>

class Component;

class GameObject :  public std::enable_shared_from_this<GameObject>

{
	

public:

	template<typename T>
	std::shared_ptr<T> AddChildComponent()
	{
		std::shared_ptr<T> temp_component(new T());

		temp_component->gameObject = shared_from_this();
		m_components.push_back(temp_component);

		
		return temp_component;
	}

	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		for (int i = 0; i < m_components.size(); i++)
		{
			std::shared_ptr<T> t;
			t = std::dynamic_pointer_cast<T>(m_components.at(i));

			if (t.get() != NULL)
			{
				return t;
			}
		}
		return std::shared_ptr<T>();
	}
	

	void onAwake();
	void onStart();
	void onUpdate();
	

	static std::shared_ptr<GameObject> create();
	

	GameObject();
	~GameObject();
	


private:
	std::vector<std::shared_ptr<Component>> m_components;

};

#endif // !GAMEOBJECT_H