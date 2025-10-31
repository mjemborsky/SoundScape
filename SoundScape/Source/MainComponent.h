#pragma once
#include <JuceHeader.h>
#include "AudioEngine.h"

class MainComponent : public juce::Component, private juce::Slider::Listener
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(juce::Slider* slider) override;

    juce::Slider gainSlider;
    juce::Label gainLabel;
    AudioEngine audioEngine;

    // Declare the buttons as member variables
    juce::TextButton startButton;
    juce::TextButton stopButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
