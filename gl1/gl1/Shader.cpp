#include "Shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* framentPath)
{
	std::string vertexCode;
	std::string framentCode;
	std::ifstream vertexShaderFile;
	std::ifstream framentShaderFile;

	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	framentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try
	{
		//打开文件
		vertexShaderFile.open(vertexPath);
		framentShaderFile.open(framentPath);
		std::stringstream vertexShaderStream, framentShaderStream;
		
		//读取文件缓存内容到数据流中
		vertexShaderStream << vertexShaderFile.rdbuf();
		framentShaderStream << framentShaderFile.rdbuf();

		//关闭文件
		vertexShaderFile.close();
		framentShaderFile.close();

		//数据流转化成string
		vertexCode = vertexShaderStream.str();
		framentCode = framentShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vertexShaderCode = vertexCode.c_str();
	const char* framentShaderCode = framentCode.c_str();

	//编译着色器
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	//顶点着色器
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexShaderCode, NULL);
	glCompileShader(vertex);
	//打印编译错误
	checkCompileErrors(vertex, "VERTEX");
	
	//片段着色器
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &framentShaderCode, NULL);
	glCompileShader(fragment);
	//打印编译错误
	checkCompileErrors(fragment, "FRAGMENT");

	//着色器程序
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	//打印错误
	checkCompileErrors(ID, "PROGRAM");

	//删除着色器
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader()
{
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
#define BUFSIZE 1024

	int success;
	char infoLog[BUFSIZE];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, BUFSIZE, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" 
				<< infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, BUFSIZE, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" 
				<< infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat4(const std::string &name, float value1, float value2, float value3, float value4) const
{
	glUniform4f(glGetUniformLocation(ID, name.c_str()), value1, value2, value3, value4);
}

inline unsigned int Shader::getID()
{
	return ID;
}