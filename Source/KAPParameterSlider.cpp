/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 21 Oct 2019 7:50:37pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPParameterSlider.h"

KAPParameterSlider::KAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID)
    : juce::Slider(parameterID)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);

    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
}

KAPParameterSlider::~KAPParameterSlider()
{

}