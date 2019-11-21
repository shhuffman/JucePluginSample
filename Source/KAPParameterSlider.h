/*
  ==============================================================================

    KAPParameterSlider.h
    Created: 21 Oct 2019 7:50:37pm
    Author:  Houston

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterSlider : public Slider
{
public:

    KAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID);

    ~KAPParameterSlider();


private:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterSlider)
};