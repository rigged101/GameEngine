#include "ShaderLoader.h"



ShaderLoader::ShaderLoader()
{

}

ShaderLoader::ShaderLoader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	std::string vertCode, fragCode;
	std::ifstream vertShaderFile, fragShaderFile;

	// initialising exceptions make sure they can be thrown
	vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertShaderFile.open(vertexPath);
		fragShaderFile.open(fragmentPath);


		std::stringstream vertShaderStream, fragShaderStream;

		vertShaderStream << vertShaderFile.rdbuf();
		fragShaderStream << fragShaderFile.rdbuf();

		vertShaderFile.close();
		fragShaderFile.close();

		vertCode = vertShaderStream.str();
		fragCode = fragShaderStream.str();

	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR SHADER FILE READING UNSUCCESSFULL" << std::endl;
		throw;
	}

	const char* vertShaderCode = vertCode.c_str();
	const char* fragShaderCode = fragCode.c_str();


	unsigned int vertex, fragment;
	int success;
	char infoLog[512]; // errochecking purposes error log

	
	vertex = glCreateShader(GL_VERTEX_SHADER); // initialising vertex shader
	glShaderSource(vertex, 1, &vertShaderCode, NULL);
	glCompileShader(vertex);
	
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR SHADER VERTEX COMPLIATION FAILED\n" << infoLog << std::endl;
	}


	fragment = glCreateShader(GL_FRAGMENT_SHADER); // initialising fragment shader
	glShaderSource(fragment, 1, &fragShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 1, NULL, infoLog);
		std::cout << "ERROR SHADER FRAGMENT COMPILATION FAILED" << infoLog << std::endl;
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);

	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR SHADER PROGRAM COMPLIATION LINKING FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);




}


ShaderLoader::~ShaderLoader()
{

}

unsigned int ShaderLoader::GetProgramID()
{
	return ID;
}

void ShaderLoader::Use()
{
	glUseProgram(ID);
}

void ShaderLoader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void ShaderLoader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void ShaderLoader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void ShaderLoader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void ShaderLoader::setVec3(const std::string &name, const glm::vec3 &value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}