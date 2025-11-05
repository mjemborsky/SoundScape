#include "MainComponent.h"

MainComponent::MainComponent()
{
    // Add and make the buttons visible
    addAndMakeVisible(startButton);
    startButton.setButtonText("Start");
    startButton.onClick = [this]() { audioEngine.start(); };

    addAndMakeVisible(stopButton);
    stopButton.setButtonText("Stop");
    stopButton.onClick = [this]() { audioEngine.stop(); };

    // Add and configure the gainSlider
    addAndMakeVisible(gainSlider);
    gainSlider.setRange(0.0, 1.0, 0.01);
    gainSlider.setValue(0.5);
    gainSlider.onValueChange = [this]() { audioEngine.setGain((float)gainSlider.getValue()); };
    gainSlider.addListener(this);

    setSize(400, 200);  // Set the size of the component
}

MainComponent::~MainComponent()
{
    // Destructor is empty, but can be used to clean up if needed
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::white);  // Set background to white
    g.setColour(juce::Colours::black);  // Set text color to black
    g.setFont(14.0f);  // Set font size
    g.drawText("Gain", 50, 150, 50, 20, juce::Justification::centredLeft);  // Draw label
}

void MainComponent::resized()
{
    // Set bounds for the start button, stop button, and gain slider
    startButton.setBounds(50, 50, 100, 40);
    stopButton.setBounds(200, 50, 100, 40);
    gainSlider.setBounds(50, 120, 250, 40);
}

void MainComponent::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioEngine.setGain((float)gainSlider.getValue());  // Update gain when slider value changes
    }
}