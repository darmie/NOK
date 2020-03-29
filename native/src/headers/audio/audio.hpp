#pragma once 

#include "nok/audio.hpp"
#include "nok/audio_channel.hpp"
#include "nok/audio1.hpp"
#include "nok/audio_buffer.hpp"
#include "nok/resampling_audio_channel.hpp"
#include "nok/sound.hpp"
#include "nok/stream_channel.hpp"
#include "Kore/Audio2/Audio.h"
#include <mutex>

namespace nok
{
    class Sound : nok::Sound {
        public:
            Sound() : nok::Sound(){};
            ~Sound(){};

            std::vector<uint8_t> get_compressedData();

            std::vector<float> get_uncompressedData();

            float get_length();

            int32_t get_channels();

            int32_t get_sampleRate();

            void set_compressedData(const std::vector<uint8_t> & b);

            void set_uncompressedData(const std::vector<float> & d);

            void set_length(float length);

            void set_channels(int32_t channels);

            void set_sampleRate(int32_t rate);

            void unload();

            static std::shared_ptr<Sound> create();            
    };
    class AudioChannelImpl : public nok::AudioChannel {
        public:
            AudioChannelImpl(bool looping) : nok::AudioChannel(){
               this->looping = looping; 
            };
            ~AudioChannelImpl(){};

            bool looping;

            std::vector<float> get_data();
            void set_data(const std::vector<float> & d);

            static std::shared_ptr<AudioChannel> create(bool looping);

            void nextSamples(const std::vector<float> & requestedSamples, int32_t requestedLength, int32_t sampleRate);

            void play();

            void pause();

            void stop();

            float get_length();

            float get_position();

            void set_position(float pos);

            float get_volume();

            void set_volume(float vol);

            bool get_finished();

            void max(int32_t a, int32_t b);

            void min(int32_t a, int32_t b);

    };
    class StreamChannelImpl : public nok::StreamChannel , public AudioChannelImpl {
        public:
           StreamChannelImpl(const std::vector<uint8_t> & data, bool looping) :  nok::StreamChannel(), AudioChannelImpl(looping) {
               this->data = data;
               this->looping = looping;
           };
           ~StreamChannelImpl(){};

            std::vector<uint8_t> data;
            bool looping;

            std::vector<float> get_data();

            static std::shared_ptr<StreamChannel> create(const std::vector<uint8_t> & data, bool looping);

            void nextSamples(const std::vector<float> & requestedSamples, int32_t requestedLength, int32_t sampleRate);

            void play();

            void pause();

            void stop();

            float get_length();

            float get_position();

            void set_position(float pos);

            float get_volume();

            void set_volume(float vol);

            bool get_finished();

            void max(int32_t a, int32_t b);

            void min(int32_t a, int32_t b);           
    };

    class ResamplingAudioChannelImpl : public nok::ResamplingAudioChannel, public AudioChannelImpl {
        public:
            ResamplingAudioChannelImpl(bool loop, int sampleRate) : nok::ResamplingAudioChannel(), AudioChannelImpl(loop){};
            ~ResamplingAudioChannelImpl(){};

            std::vector<float> get_data();
            void set_data(const std::vector<float> & d);

            int32_t get_samplesRate();

            static std::shared_ptr<ResamplingAudioChannel> create(bool looping, int sampleRate);

            float sample(int32_t position, int32_t sampleRate);

            void lerp(float v0, float v1, float t);

            int32_t sampleLength(int32_t sampleRate);

            void nextSamples(const std::vector<float> & requestedSamples, int32_t requestedLength, int32_t sampleRate);

            void play();

            void pause();

            void stop();

            float get_length();

            float get_position();

            void set_position(float pos);

            float get_volume();

            void set_volume(float vol);

            bool get_finished();

            void max(int32_t a, int32_t b);

            void min(int32_t a, int32_t b);
    };

    class Audio1Impl : public nok::Audio1 {
        private:
            static const int channelCount = 32;
            static std::vector<AudioChannelImpl*>soundChannels;
            static std::vector<AudioChannelImpl*>streamChannels;

            static std::vector<AudioChannelImpl*>internalSoundChannels;
            static std::vector<AudioChannelImpl*>internalStreamChannels;

            static std::vector<float> sampleCache1;
            static std::vector<float> sampleCache2;

            static int lastAllocationCount;

        public:
            Audio1Impl() : nok::Audio1(){};
            ~Audio1Impl(){};

            std::mutex mutex;

            static void init() {
                soundChannels = std::vector<AudioChannelImpl*>(channelCount);
                streamChannels = std::vector<AudioChannelImpl*>(channelCount);
                
                internalSoundChannels = std::vector<AudioChannelImpl*>(channelCount);
                internalStreamChannels = std::vector<AudioChannelImpl*>(channelCount);

                sampleCache1 = std::vector<float>(512);
                sampleCache2 = std::vector<float>(512);
                lastAllocationCount;
            }

            float max(float a, float b) {
                return a > b ? a : b;
            }

            float min(float a, float b) {
                return a < b ? a : b;
            }

            float mix(int32_t samples, const std::shared_ptr<AudioBuffer> & buffer) {
                if (sampleCache1.size < samples) {
                    sampleCache1.assign(samples * 2, 0);
                    sampleCache2.assign(samples * 2, 0);
                    lastAllocationCount;
                } else {
                    lastAllocationCount += 1;
                }

                for(int i; i < samples; i++){
                    sampleCache2[i];
                }

                mutex.lock();

                for(int i; i < channelCount; i++){
                    internalSoundChannels[i] = soundChannels[i];
                }

                for(int i; i < channelCount; i++){
                    internalStreamChannels[i] = streamChannels[i];
                }

                mutex.unlock();

                for(int i; i < channelCount; i++){
                    AudioChannelImpl* channel = internalSoundChannels[i];
                    if(channel == nullptr || channel->get_finished()) continue;

                    channel->nextSamples(sampleCache1, samples, buffer.get()->get_samplesPerSecond());
                    for(int i; i < samples; i++){
                        sampleCache2[i] += sampleCache1[i] * channel->get_volume();
                    }
                }

                for(int i; i < channelCount; i++){
                    AudioChannelImpl* channel = internalStreamChannels[i];
                    if(channel == nullptr || channel->get_finished()) continue;

                    channel->nextSamples(sampleCache1, samples, buffer.get()->get_samplesPerSecond());
                    for(int i; i < samples; i++){
                        sampleCache2[i] += sampleCache1[i] * channel->get_volume();
                    }
                }

                for(int i; i < samples; i++){
                    static_cast<AudioBufferImpl*>(buffer.get())->data[(buffer.get()->get_writeLocation())] =  max(min(sampleCache2[i], 1.0), -1.0);
                    buffer.get()->set_writeLocation(buffer.get()->get_writeLocation()+1);
                    if(buffer.get()->get_writeLocation() >= buffer.get()->get_size()){
                        buffer.get()->set_writeLocation(0);
                    }
                }

            }

            std::shared_ptr<AudioChannel> play(const std::shared_ptr<Sound> & sound, bool loop) {
                AudioChannelImpl* channel = nullptr;
                if(AudioImpl::samplesPerSecond != (sound.get())->get_sampleRate()){
                    channel = new ResamplingAudioChannelImpl(loop, sound.get()->get_sampleRate());
                }else{
                    #if ios
                    channel = new ResamplingAudioChannelImpl(loop, sound.get()->get_sampleRate());
                    #else 
                    channel = new AudioChannelImpl(loop);
                    #endif
                }
                channel->set_data(sound.get()->get_uncompressedData());
                bool foundChannel = false;

                mutex.lock();

                for(int i; i < channelCount; i++){
                    if (soundChannels[i] == nullptr || soundChannels[i]->get_finished()) {
                        soundChannels[i] = channel;
                        foundChannel = true;
                        break;
                    }
                }

                mutex.unlock();

                return foundChannel ? std::make_shared<AudioChannel>(channel) : nullptr;
            }

            void playAgain(const std::shared_ptr<AudioChannel> & channel) {
                mutex.lock();
                for(int i; i < channelCount; i++){
                    if (soundChannels[i] == channel.get()) {
                        soundChannels[i] = nullptr;
                    }
                }
                for(int i; i < channelCount; i++){
                    if (soundChannels[i] == nullptr || soundChannels[i]->get_finished() || soundChannels[i] == static_cast<AudioChannelImpl*>(channel.get())) {
                        soundChannels[i] = static_cast<AudioChannelImpl*>(channel.get());
                        break;
                    }
                }

                mutex.unlock();
            }

            std::shared_ptr<AudioChannel> stream(const std::shared_ptr<Sound> & sound, bool loop) {
                AudioChannel* hardwareChannel = AudioImpl::stream(sound, loop).get();

                if (hardwareChannel != nullptr) return std::make_shared<AudioChannelImpl>(hardwareChannel);

                StreamChannelImpl * channel = static_cast<StreamChannelImpl*>(StreamChannelImpl::create(sound->get_compressedData(), loop).get());

                bool foundChannel = false;

                mutex.lock();

                for(int i; i < channelCount; i++){
                    if (streamChannels[i] == nullptr || streamChannels[i]->get_finished()) {
                        streamChannels[i] = static_cast<AudioChannelImpl*>(channel);
                        foundChannel = true;
                        break;
                    }
                }

                mutex.unlock();
                return foundChannel ? std::make_shared<AudioChannel>(channel) : nullptr;
            }
    };

    class AudioBufferImpl : public nok::AudioBuffer, public Kore::Audio2::Buffer {
        public:
            AudioBufferImpl(): nok::AudioBuffer(), Kore::Audio2::Buffer(){};
            ~AudioBufferImpl(){};
            int readLocation;
            int writeLocation;

            static std::shared_ptr<AudioBuffer> create(int32_t size, int32_t channels, int32_t samplesPerSecond) {
                Kore::Audio2::Buffer buffer;
                buffer.format.channels = channels;
                buffer.format.samplesPerSecond = samplesPerSecond;
                buffer.dataSize = size;

                std::shared_ptr<AudioBuffer> buf = std::make_shared<AudioBufferImpl>(static_cast<AudioBufferImpl*>(&buffer));
                buf.get()->set_readLocation(0);
                buf.get()->set_writeLocation(0);

            }

            int32_t get_channels() {
                return this->format.channels;
            }

            int32_t get_samplesPerSecond() {
                return this->format.samplesPerSecond;
            }

            std::vector<float> get_data() {
                const unsigned char* data = this->data;
                return std::vector<float>(data, data + (sizeof(data)/sizeof(data[0])));
            }

            int32_t get_size() {
                return this->dataSize;
            }

            int32_t get_readLocation() {
                return this->readLocation;
            }

            int32_t get_writeLocation() {
                return this->writeLocation;
            }

            void set_channels(int32_t channels) {
                this->format.channels = channels;
            }

            void set_samplesPerSecond(int32_t samples) {
                this->format.samplesPerSecond = samples;
            }

            void set_data(const std::vector<float> & data) {
                this->data = (uint8_t*)(&data[0]);
            }

            void set_size(int32_t s) {
                this->dataSize = s;
            }

            void set_readLocation(int32_t loc) {
                this->readLocation = loc;
            }

            void set_writeLocation(int32_t loc) {
                this->writeLocation = loc;
            }
    };
    class AudioImpl : public nok::Audio {
        public:
            AudioImpl() : nok::Audio(){};
            ~AudioImpl(){};

            static AudioBufferImpl* buffer;
            static const int samplesPerSecond = 44100;

            static void init() {
                Kore::Audio2::init();
                buffer = static_cast<AudioBufferImpl*>(getBuffer().get());
            }

            static float readSample(){
                nok::AudioBuffer* buffer = static_cast<nok::AudioBuffer*>(getBuffer().get());
                if(buffer == nullptr) return 0;

                float value = buffer->get_data()[buffer->get_readLocation()];
                int location = buffer->get_readLocation();
                buffer->set_readLocation(++location);
                if(buffer->get_readLocation() >= buffer->get_size()){
                    buffer->set_readLocation(0);
                }

                return value;
            }

            static std::shared_ptr<AudioBuffer> getBuffer() {
                if(buffer == nullptr){
                    buffer = static_cast<AudioBufferImpl*>(static_cast<Kore::Audio2::Buffer*>(&Kore::Audio2::buffer));
                }

                return std::make_shared<AudioBufferImpl>(buffer);
            }

            static void setBuffer(const std::shared_ptr<AudioBuffer> & buf){
                buffer = static_cast<AudioBufferImpl*>(buf.get());
            }

            int32_t get_samplesPerSecond(){
                return samplesPerSecond;
            }

            static void update() {
                Kore::Audio2::update();
            }

            static void shutdown() {
                Kore::Audio2::shutdown();
            }

            static std::shared_ptr<AudioChannel> stream(const std::shared_ptr<Sound> & sound, bool loop) {

            }
    };
} // namespace nok
