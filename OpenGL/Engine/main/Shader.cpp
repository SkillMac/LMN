
#include "Shader.h"
#include "glad/glad.h"
#include "log.h"

#include <fstream>
#include <sstream>

ShaderSource Shader::parseShader(const std::string file_path)
{
	std::ifstream stream(file_path);
	std::string line;
	std::stringstream shaderStreamList[2];

	bool vertex_flag = false, fragment_flag = false;
	while (std::getline(stream, line))
	{
		if (line.find("[vertex]") != std::string::npos)
		{
			vertex_flag = true;
			fragment_flag = false;
			continue;
		}
		else if (line.find("[fragment]") != std::string::npos)
		{
			vertex_flag = false;
			fragment_flag = true;
			continue;
		}

		if (vertex_flag)
			shaderStreamList[0] << line << "\n";
		if (fragment_flag)
			shaderStreamList[1] << line << "\n";
	}
	stream.close();
	return {shaderStreamList[0].str(), shaderStreamList[1].str()};
}

int Shader::getUniformLocation(const std::string & name)
{
	if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
	{
		return m_uniformLocationCache[name];
	}
	int location = glGetUniformLocation(m_program_id, name.c_str());
	if (location == -1)
	{
		std::string desc = "getUniformLocation" + name + " doesn't exist!";
		Log::get_instance()->warn<std::string>(desc);
	}
	else
	{
		m_uniformLocationCache[name] = location;
	}
	return 0;
}

unsigned int Shader::compileShader(unsigned int type, const std::string & source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* info = new char[length];
		glGetShaderInfoLog(id, length, &length, info);
		std::string shaderType = type == GL_VERTEX_SHADER ? "vertex" : "fragment";
		std::string desc = shaderType + "shader => compile faile" + std::string(info);
		Log::get_instance()->error<std::string>(desc);
		delete[] info;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

unsigned int Shader::createShader(const std::string & vertexShader, const std::string & fragmentShader)
{
	unsigned int programId = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
	glAttachShader(programId, vs);
	glAttachShader(programId, fs);
	glLinkProgram(programId);
	glValidateProgram(programId);
	int result;
	glGetProgramiv(programId, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		std::string desc = "program link fail";
		glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &length);
		if (length > 0)
		{
			char* info = new char[length];
			glGetProgramInfoLog(programId, length, &length, info);
			desc = desc + std::string(info);
			delete[] info;
		}
		Log::get_instance()->error<std::string>(desc);
		glDeleteProgram(programId);
		return  0;
	}
	return programId;
}

Shader::Shader(const std::string & file_path) : m_filePath(file_path), m_program_id(0)
{
	ShaderSource source = parseShader(file_path);
	m_program_id = createShader(source.vertexSource, source.fragmentSource);
}

Shader::~Shader()
{
	glDeleteProgram(m_program_id);
}

void Shader::bind() const
{
	glUseProgram(m_program_id);
}

void Shader::unBind() const
{
	glUseProgram(0);
}

void Shader::setUniform1f(const std::string & name, float val)
{
	glUniform1f(getUniformLocation(name), val);
}

void Shader::setUniform4f(const std::string & name, float f1, float f2, float f3, float f4)
{
	glUniform4f(getUniformLocation(name), f1, f2, f3, f4);
}

void Shader::setUniform1i(const std::string & name, int val)
{
	glUniform1i(getUniformLocation(name), val);
}

void Shader::setUniformMat4f(const std::string & name, glm::mat4 & matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}
