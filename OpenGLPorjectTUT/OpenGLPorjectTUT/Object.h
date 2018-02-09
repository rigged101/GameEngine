#pragma once
#ifndef OBJECT_H
#define OBJECT_H


#include <string>
#include <vector>
#include <memory>



class Object 
{

	friend class GameObject;

public:
	Object();
	virtual ~Object();


	
	void makeName(std::string _name);

	std::string getName();

private:
	std::string name;


};


#endif // !Object_H