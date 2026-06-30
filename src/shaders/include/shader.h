#pragma once
#include <string>
#include "../../../lib/glm/glm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../lib/glad/include/glad/glad.h"

class Shader{
    private:
        unsigned int ID;

    public:
        Shader(const std::string &filePath);
        ~Shader();
        void bind();
        void unBind();
        void setInt(const std::string &uniformName, int value);
        void setFloat(const std::string &uniformName, float value);
        void setVec3(const std::string &uniformName, const glm::vec3 &value);
        void setVec4(const std::string &uniformName, const glm::vec4 &value);
        void setMat4(const std::string &uniformName, const glm::mat4 &value);

    private:
        int getUnifromLocation(const std::string &unifromName);
        unsigned int compileShader(unsigned int type,const std::string &source);
        unsigned int createShader(const std::string &vertexShader, const std::string &fragmentShader);
        std::string ReadFile(const std::string &filePath);
};
