/*
  ==============================================================================

    KAPPanelBase.h
    Created: 20 Oct 2019 11:47:41pm
    Author:  Houston

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

class KAPPanelBase : public Component
{
public:

    KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPPanelBase();

    void paint(Graphics& g) override;


protected:

    KadenzeAudioPluginAudioProcessor* mProcessor;
};