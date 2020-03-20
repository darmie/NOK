// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace nok {

class Texture;
struct AlignedQuad;
struct FontStyle;

class Kavur {
public:
    virtual ~Kavur() {}

    virtual int32_t get_width() = 0;

    virtual void set_width(int32_t w) = 0;

    virtual int32_t get_height() = 0;

    virtual void set_height(int32_t h) = 0;

    static std::shared_ptr<Kavur> load(const std::string & name, const FontStyle & style, float size);

    virtual std::shared_ptr<Texture> getTexture() = 0;

    virtual AlignedQuad getBakedQuad(int32_t char_index, float xpos, float ypos) = 0;

    virtual float getHeight() = 0;

    virtual float charsWidth(const std::string & ch, int32_t offset, int32_t length) = 0;

    virtual float stringWidth(const std::string & ch, int32_t length) = 0;

    virtual float getBaselinePosition() = 0;
};

}  // namespace nok
