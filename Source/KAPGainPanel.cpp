/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 20 Oct 2019 11:48:27pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPGainPanel.h"
#include "KAPParameters.h"
#include "KAPHelperFunctions.h"


KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}


KAPGainPanel::~KAPGainPanel() {}

void KAPGainPanel::paint(Graphics& g)
{
    KAPPanelBase::paint(g);

    if(mSlider)
        paintComponentLabel(g, mSlider.get());
}

void KAPGainPanel::setParameterID(int inParameterID)
{
    mSlider = std::make_unique<KAPParameterSlider>(mProcessor->parameters, KAPParameterID[inParameterID]);
    const int slider_size = 54;

    mSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5), 
                       (getHeight() * 0.5) - (slider_size * 0.5), 
                        slider_size, 
                        slider_size);

    addAndMakeVisible(mSlider.get());
}