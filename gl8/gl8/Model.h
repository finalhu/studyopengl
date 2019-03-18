#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Shader.h"

class Model
{
public:
	Model(const std::string path, bool gamma = false);
	~Model();

	void draw(Shader shader);
	inline std::vector<Mesh>& meshes() { return meshes_; }
	inline std::vector<Texture>& textures_loaded() { return textures_loaded_; }

private:
	void loadModel(std::string const &path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char* path, const std::string &directory, bool gamma = false);

private:
	std::vector<Texture> textures_loaded_;
	std::vector<Mesh> meshes_;
	std::string directory_;
	bool gammaCorrection_;
};


#endif // !MODEL_H_

