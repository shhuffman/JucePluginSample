/*
  ==============================================================================

    KAPGainPanel.h
    Created: 20 Oct 2019 11:48:27pm
    Author:  Houston

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

class KAPGainPanel : public KAPPanelBase
{
public:

    KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPGainPanel();

    void paint(Graphics& g) override;

    void setParameterID(int inParameterID);

private:

    std::unique_ptr<KAPParameterSlider> mSlider;
};