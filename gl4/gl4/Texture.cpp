#include "Texture.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const char* file, int internalformat, int format)
{
	//º”‘ÿÕº∆¨
	unsigned char* data = stbi_load(file, &width_, &height_, &nrChannels_, 0);

	glGenTextures(1, &id_);
	glActiveTexture(GL_TEXTURE0 + textureSize);
	textureSizeAdd();
	glBindTexture(GL_TEXTURE_2D, id_);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width_, height_, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);



	//º”‘ÿÕº∆¨ ±∑≠◊™y÷·
	stbi_set_flip_vertically_on_load(true);
}


Texture::~Texture()
{
}

int Texture::textureSize = 0;