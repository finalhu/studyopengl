#pragma once
#ifndef SHADER_H_	
#define SHADER_H_

#include <string>

class Shader
{
public:

	Shader(const char* vertexPath, const char* framentPath);
	~Shader();

	//激活程序
	void use();
	//uniform工具函数
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setFloat4(const std::string &name, float value1, float value2, float value3, float value4) const;
	inline unsigned int getID();
protected:
	//打印错误
	void checkCompileErrors(unsigned int shader, std::string type);

public:
	unsigned int ID;
	
};


#endif // !SHADER_H_
