#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

#include <memory>

class GameObject;


class Component 
{

public:


	std::weak_ptr<GameObject> gameObject;
	std::weak_ptr<GameObject> getGameObject();


	void onAwake();
	void onStart();
	void onUpdate();

	Component();
	virtual ~Component();
private:

};


#endif // !COMPONENT_H