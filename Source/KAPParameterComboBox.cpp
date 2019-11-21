/*
  ==============================================================================

    KAPParameterComboBox.cpp
    Created: 21 Oct 2019 7:50:47pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPParameterComboBox.h"


KAPParameterComboBox::KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID)
    : juce::ComboBox(parameterID)
{
    mAttachment = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
}


KAPParameterComboBox::~KAPParameterComboBox()
{

}