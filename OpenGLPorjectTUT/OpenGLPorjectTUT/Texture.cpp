#include "Texture.h"



Texture::Texture()
{

}


Texture::~Texture()
{
}

void Texture::SetDiffuseMap()
{
	m_diffuseMap = m_textureID;
}

int Texture::GetDiffuseMap()
{
	return m_diffuseMap;
}

void Texture::TextureLoader(char const * path)
{

	glGenTextures(1, &m_textureID);
	int width, height, amountComponents;
	unsigned char *data = stbi_load(path, &width, &height, &amountComponents, 0);

	if (data)
	{
		GLenum ofType;
		if (amountComponents == 1)
		{
			ofType = GL_RED;
		}
		else if (amountComponents == 3)
		{
			ofType = GL_RGB;
		}
		else if (amountComponents == 4)
		{
			ofType = GL_RGBA;
		}

		glBindTexture(GL_TEXTURE_2D, m_textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, ofType, width, height, 0, ofType, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);

	}
	else
	{
		std::cout << "TEXTURE FAILED TO LOAD FROM THE PATH:" << path << std::endl;
		stbi_image_free(data);
	}

	//return m_textureID;

}

GLenum Texture::GetActiveTexture()
{
	return GL_TEXTURE0;
}
