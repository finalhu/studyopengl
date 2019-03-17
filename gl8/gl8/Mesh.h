#ifndef MESH_H_
#define MESH_H_

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>

#include "Shader.h"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 tangent;
	glm::vec3 bitangent;
};

struct Texture
{
	unsigned int id;
	std::string type;
	std::string path;
};


class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	~Mesh();
	void draw(Shader shader);

private:
	void setupMesh();

private:
	std::vector<Vertex> vertices_;
	std::vector<unsigned int> indices_;
	std::vector<Texture> textures_;
	unsigned int vao_;
	unsigned int vbo_;
	unsigned int ebo_;
};


#endif // !MESH_H_

