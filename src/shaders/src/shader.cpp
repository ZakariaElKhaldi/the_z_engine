#include "../include/shader.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <alloca.h>
#include <cstdlib>

Shader::Shader(const std::string &filePath){
    std::string vertexSource = ReadFile(filePath + ".vert");
    std::string fragmentSource = ReadFile(filePath + ".frag");
    ID = createShader(vertexSource,fragmentSource);
}

Shader::~Shader(){
    glDeleteProgram(ID);
}

void Shader::bind(){
    glUseProgram(ID);
}

void Shader::unBind(){
   glUseProgram(0);
}

void Shader::setInt(const std::string &uniformName, int value){
    glUniform1i(getUnifromLocation(uniformName),value);
}

void Shader::setFloat(const std::string &uniformName, float value){
    glUniform1f(getUnifromLocation(uniformName),value);
}

void Shader::setVec3(const std::string &uniformName, const glm::vec3 &value){
    glUniform3f(getUnifromLocation(uniformName),value.x,value.y,value.z);
}

void Shader::setVec4(const std::string &uniformName, const glm::vec4 &value){
    glUniform4f(getUnifromLocation(uniformName),value.x,value.y,value.z,value.w);
}

void Shader::setMat4(const std::string &uniformName, const glm::mat4 &value){
    glUniformMatrix4fv(getUnifromLocation(uniformName),1,GL_FALSE,&value[0][0]);
}

int Shader::getUnifromLocation(const std::string &unifromName){
    return glGetUniformLocation(ID,unifromName.c_str());
}

unsigned int Shader::compileShader(unsigned int type, const std::string &source){
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id,1,&src,nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id,GL_COMPILE_STATUS,&result);
    if(result == GL_FALSE){
        int length;
        glGetShaderiv(id,GL_INFO_LOG_LENGTH,&length);
        char* message = (char*)alloca(length*sizeof(char));
        glGetShaderInfoLog(id,length,&length,message);
        std::cout << "FAILED TO COMPILE " << (type == GL_VERTEX_SHADER ? "VERTEX " : "FRAGMENT ") << "SHADER ! " << '\n' << message << std::endl;
        glDeleteShader(id);
        return -1;
        std::exit(EXIT_FAILURE);
    }

    return id;
}

unsigned int Shader::createShader(const std::string &vertexShader, const std::string &fragmentShader){
    unsigned int program = glCreateProgram();

    unsigned int vs = compileShader(GL_VERTEX_SHADER,vertexShader);
    unsigned int fs= compileShader(GL_FRAGMENT_SHADER,fragmentShader);

    glAttachShader(program,vs);
    glAttachShader(program,fs);

    glLinkProgram(program);

    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

std::string Shader::ReadFile(const std::string &filePath){
    std::ifstream file(filePath);
    if(!file.is_open()){
        std::cerr << "!FAILED TO READ FILE " << filePath << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string shaderContent = buffer.str();

    file.close();
    return shaderContent;
}
