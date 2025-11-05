/*
  ==============================================================================

    AudioEngine.h
    Created: 30 Oct 2025 12:55:34pm
    Author:  micha

  ==============================================================================
*/
#pragma once

#include <juce_audio_devices/juce_audio_devices.h>
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>

class AudioEngine : public juce::AudioIODeviceCallback
{
public:
    AudioEngine();
    ~AudioEngine() override;

    void audioDeviceIOCallbackWithContext(
        const float* const* inputChannelData,
        int totalNumInputChannels,
        float* const* outputChannelData,
        int totalNumOutputChannels,
        int numSamples,
        const juce::AudioIODeviceCallbackContext& context
    ) override;


    void audioDeviceAboutToStart(juce::AudioIODevice* device) override;
    void audioDeviceStopped() override;

    void start();
    void stop();
    void setGain(float newGain);

private:
    juce::AudioDeviceManager deviceManager;
    double currentSampleRate = 44100.0;
    double phase = 0.0;
    float gain = 0.5f;
};