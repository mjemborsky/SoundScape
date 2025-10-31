/*
  ==============================================================================

    AudioEngine.cpp
    Created: 30 Oct 2025 12:54:34pm
    Author:  micha

  ==============================================================================
*/
#include "AudioEngine.h"
#include <cmath>

AudioEngine::AudioEngine()
{
    deviceManager.initialiseWithDefaultDevices(0, 2);
    deviceManager.addAudioCallback(this);
}

AudioEngine::~AudioEngine()
{
    deviceManager.removeAudioCallback(this);
}

void AudioEngine::start()
{
    deviceManager.restartLastAudioDevice();
}

void AudioEngine::stop()
{
    deviceManager.closeAudioDevice();
}

void AudioEngine::setGain(float newGain)
{
    gain = juce::jlimit(0.0f, 1.0f, newGain);
}

void AudioEngine::audioDeviceAboutToStart(juce::AudioIODevice* device)
{
    currentSampleRate = device ? device->getCurrentSampleRate() : 44100.0;
    phase = 0.0;
}

void AudioEngine::audioDeviceStopped()
{
    currentSampleRate = 0.0;
}

void AudioEngine::audioDeviceIOCallbackWithContext(
    const float* const* inputChannelData,
    int totalNumInputChannels,
    float* const* outputChannelData,
    int totalNumOutputChannels,
    int numSamples,
    const juce::AudioIODeviceCallbackContext& /*context*/)
{
    juce::ignoreUnused(inputChannelData, totalNumInputChannels);

    const double frequency = 440.0;
    const double twoPi = juce::MathConstants<double>::twoPi;

    for (int sample = 0; sample < numSamples; ++sample)
    {
        float sampleValue = std::sin(phase) * gain;
        phase += twoPi * frequency / currentSampleRate;
        if (phase >= twoPi)
            phase -= twoPi;

        for (int channel = 0; channel < totalNumOutputChannels; ++channel)
            if (outputChannelData[channel] != nullptr)
                outputChannelData[channel][sample] = sampleValue;
    }
}


