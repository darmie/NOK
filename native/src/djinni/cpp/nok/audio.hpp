// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

#pragma once

#include <cstdint>
#include <memory>

namespace nok {

class AudioBuffer;
class AudioChannel;
class Sound;

class Audio {
public:
    virtual ~Audio() {}

    virtual int32_t get_samplesPerSecond() = 0;

    static std::shared_ptr<AudioChannel> stream(const std::shared_ptr<Sound> & sound, bool loop);

    static void init();

    static std::shared_ptr<AudioBuffer> getBuffer();

    static void setBuffer(const std::shared_ptr<AudioBuffer> & buf);

    static void update();

    static void shutdown();

    static float readSample();
};

}  // namespace nok
