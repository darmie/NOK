
#include "nok/shader.hpp"
#include "nok/shader_type.hpp"
#include "Kore/Graphics4/Shader.h"

namespace nok
{
    class ShaderImpl : public nok::Shader, public Kore::Graphics4::Shader {
        public: 
            ShaderImpl(const std::string & source, ShaderType type) : nok::Shader(), Kore::Graphics4::Shader(source.c_str(), getInternalShaderType(type)){};
            ShaderImpl(const std::vector<uint8_t> & data, int32_t length, ShaderType type) : nok::Shader(), Kore::Graphics4::Shader((void*)&data[0],length, getInternalShaderType(type)){};
            ~ShaderImpl(){};

            static std::shared_ptr<nok::Shader> create(const std::vector<uint8_t> & data, int32_t length, ShaderType type){
                return std::make_shared<ShaderImpl>(new ShaderImpl(data, length, type));
            }

            static std::shared_ptr<nok::Shader> createWithSource(const std::string & source, ShaderType type){
                return std::make_shared<ShaderImpl>(new ShaderImpl(source, type));
            }

    };

    static Kore::Graphics4::ShaderType getInternalShaderType(ShaderType type){
        switch (type)
        {
        case ShaderType::FRAGMENTSHADER: return Kore::Graphics4::ShaderType::FragmentShader;
        case ShaderType::VERTEXSHADER: return Kore::Graphics4::ShaderType::VertexShader;
        case ShaderType::GEOMETRYSHADER: return Kore::Graphics4::ShaderType::GeometryShader;
        case ShaderType::TESSELLATIONCONTROLSHADER: return Kore::Graphics4::ShaderType::TessellationControlShader;
        case ShaderType::TESSELLATIONEVALUATIONSHADER: return Kore::Graphics4::ShaderType::TessellationEvaluationShader;
        }
    }
} // namespace nok
