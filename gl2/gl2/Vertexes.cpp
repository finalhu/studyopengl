#include "Vertexes.h"

Vertexes::Vertexes(float* vertices, unsigned int size)
{
	initVAO(1);
	initVBO(vertices, size);
}

Vertexes::Vertexes(float* vertices, unsigned int verSize, unsigned int* indices, unsigned int indSize)
{
	initVAO(1);
	initVBO(vertices, verSize);
	initEBO(indices, indSize);
}

Vertexes::Vertexes(float* vertices, unsigned int verSize, unsigned int index, int indSize, int stried, unsigned int offset)
{
	initVAO(1);
	initVBO(vertices, verSize);
	setVertexAttribPointer(index, indSize, GL_FLOAT, GL_FALSE, stried, (void*)offset);
	setEnableVertexAttribArray(index);
}

Vertexes::~Vertexes()
{
	glDeleteVertexArrays(size_VAO, VAO);
	delete VAO;

	glDeleteBuffers(size_VAO, VB0);
	delete VB0;
	if (EBO)
	{
		glDeleteBuffers(size_EBO, EBO);
		delete EBO;
	}

}

