
/*
shader compiler
auther: vker-xiaowei
*/

#ifndef SHADER_H
#define SHADER_H

#include <unordered_map>
#include <string>
#include "glm/glm.hpp"


struct ShaderSource
{
	std::string vertexSource;
	std::string fragmentSource;
};

class Shader
{
private:
	unsigned int m_program_id;
	std::string m_filePath;
	std::unordered_map<std::string, int> m_uniformLocationCache;

	ShaderSource parseShader(const std::string file_path);
	int getUniformLocation(const std::string& name);
	unsigned int compileShader(unsigned int type, const std::string& source);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);

public:
	Shader(const std::string& file_path);
	~Shader();

	void bind()const;
	void unBind()const;

	void setUniform1f(const std::string& name, float val);
	void setUniform4f(const std::string& name, float f1, float f2, float f3, float f4);
	void setUniform1i(const std::string& name, int val);
	void setUniformMat4f(const std::string& name, glm::mat4& matrix);
private:

};
#endif
