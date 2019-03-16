#pragma once
#ifndef SHADER_H_	
#define SHADER_H_

#include <string>

#define  GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:

	Shader(const char* vertexPath, const char* framentPath);
	~Shader();

	//uniform工具函数
	inline void setBool(const std::string &name, bool value) const { glUniform1f(glGetUniformLocation(ID, name.c_str()), (int)value); }
	void setInt(const std::string &name, int value) const { glUniform1i(glGetUniformLocation(ID, name.c_str()), value); }
	void setFloat(const std::string &name, float value) const { glUniform1f(glGetUniformLocation(ID, name.c_str()), value); }
	void setMat4(const char* name, glm::mat4 value) const { glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value)); }


	//激活程序
	inline void use() { glUseProgram(ID); };
	inline unsigned int getID() { return ID; };
protected:
	//打印错误
	void checkCompileErrors(unsigned int shader, std::string type);

private:
	unsigned int ID;

};


#endif // !SHADER_H_

