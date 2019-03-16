#include "Shader.h"

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
		//���ļ�
		vertexShaderFile.open(vertexPath);
		framentShaderFile.open(framentPath);
		std::stringstream vertexShaderStream, framentShaderStream;

		//��ȡ�ļ��������ݵ���������
		vertexShaderStream << vertexShaderFile.rdbuf();
		framentShaderStream << framentShaderFile.rdbuf();

		//�ر��ļ�
		vertexShaderFile.close();
		framentShaderFile.close();

		//������ת����string
		vertexCode = vertexShaderStream.str();
		framentCode = framentShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vertexShaderCode = vertexCode.c_str();
	const char* framentShaderCode = framentCode.c_str();

	//������ɫ��
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	//������ɫ��
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexShaderCode, NULL);
	glCompileShader(vertex);
	//��ӡ�������
	checkCompileErrors(vertex, "VERTEX");

	//Ƭ����ɫ��
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &framentShaderCode, NULL);
	glCompileShader(fragment);
	//��ӡ�������
	checkCompileErrors(fragment, "FRAGMENT");

	//��ɫ������
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	//��ӡ����
	checkCompileErrors(ID, "PROGRAM");

	//ɾ����ɫ��
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