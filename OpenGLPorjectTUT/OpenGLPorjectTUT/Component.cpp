#include "Component.h"




Component::Component()
{
	
}


Component::~Component()
{

}


std::weak_ptr<GameObject> Component::getGameObject()
{

	return gameObject.lock();
}

void Component::onAwake()
{
}

void Component::onStart()
{


}

void Component::onUpdate()
{

}


