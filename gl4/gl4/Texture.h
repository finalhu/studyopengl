#pragma once

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <gl/glew.h>
#include <GLFW/glfw3.h>


class Texture
{
	typedef unsigned int uint;
	

public:
	Texture(const char* file, int internalformat, int format);
	~Texture();

	inline uint getId()          { return id_; };
	inline int  getWidth()       { return width_; };
	inline int  getHeight()      { return height_; };
	inline int  getNrChannels_() { return nrChannels_; };

	inline void bindTexture() { glBindTexture(GL_TEXTURE_2D, id_); };

protected:

private:
	//纹理单元加一
	inline void textureSizeAdd()
	{
		if (textureSize < 15)
		{
			textureSize++;
		}
	}

private:
	uint id_;
	int width_;
	int height_;
	int nrChannels_;
	//纹理单元长度
	static int textureSize;
};

#endif // !TEXTURE_H_
