#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include "Component.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>


class Texture : public Component
{
public:
	Texture();
	~Texture();

	void SetDiffuseMap();
	int GetDiffuseMap();
	void TextureLoader(char const * path);
	GLenum GetActiveTexture();

private:

	unsigned int m_diffuseMap;
	unsigned int m_textureID;

};

#endif // !TEXTURE_H
