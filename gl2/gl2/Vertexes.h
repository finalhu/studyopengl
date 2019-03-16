#pragma once

#ifndef VERTEXES_H_
#define VERTEXES_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Vertexes
{
public:
	Vertexes(float* vertices, unsigned int size);
	//索引缓冲区
	Vertexes(float* vertices, unsigned int verSize, unsigned int* indices, unsigned int indSize);
	Vertexes(float* vertices, unsigned int verSize, unsigned int index, int indSize, int stried, unsigned int offset);
	~Vertexes();

	//设置为线框模式
	inline void setLineMode() { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  };
	//设置回默认模式
	inline void setFillMode() { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); };


	//链接顶点属性
	inline void setVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, 
		GLsizei stried, const void* pointer)
	{
		glVertexAttribPointer(index, size, type, normalized, stried, pointer);
	}
	inline void setEnableVertexAttribArray(GLuint index) { glEnableVertexAttribArray(index); }

	//设置索引缓冲对象
	inline void setEBO(unsigned int* indices, unsigned int size) { initEBO(indices, size); }
	//通过VAO来画图
	inline void drawArrays(int first, int count) { glDrawArrays(GL_TRIANGLES, first, count); }
	//通过EBO来画图
	inline void drawElements(int count, const void* indices) { glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, indices); }

protected:
	//绑定数组对象
	inline void initVAO(unsigned int size) 
	{
		unsigned int* VAO_ = new unsigned int;
		glGenVertexArrays(1, VAO_);
		glBindVertexArray(*VAO_);
		VAO = VAO_;
	}
	//顶点缓冲对象
	inline void initVBO(float* vertices, unsigned int size)
	{
		unsigned int* VBO_ = new unsigned int;
		glGenBuffers(1, VBO_);
		glBindBuffer(GL_ARRAY_BUFFER, *VBO_);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		VB0 = VBO_;
	}
	//索引缓冲对象
	inline void initEBO(unsigned int* indices, unsigned int size)
	{
		unsigned int* EBO_ = new unsigned int;
		glGenBuffers(1, EBO_);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *EBO_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	}

private:
	unsigned int* VAO = nullptr;
	unsigned int* VB0 = nullptr;
	unsigned int* EBO = nullptr;
	unsigned int size_VAO;
	unsigned int size_VBO;
	unsigned int size_EBO;
};


#endif // !VERTEXES_H_
