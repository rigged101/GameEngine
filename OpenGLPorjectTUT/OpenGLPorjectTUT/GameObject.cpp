#include "GameObject.h"
#include "Transform.h"







void GameObject::onAwake()
{

	
}


void GameObject::onStart()
{
}

void GameObject::onUpdate()
{

}

GameObject::GameObject()
{

}


std::shared_ptr<GameObject> GameObject::create()
{
	std::shared_ptr<GameObject> rtn = std::make_shared<GameObject>();
	rtn->AddChildComponent<Transform>();

	return rtn;
}

GameObject::~GameObject()
{
}


