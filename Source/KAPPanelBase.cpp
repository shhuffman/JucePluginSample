/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 20 Oct 2019 11:47:41pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPPanelBase.h"

KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor)
    :mProcessor(inProcessor)
{
}


KAPPanelBase::~KAPPanelBase()
{
}

void KAPPanelBase::paint(Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    g.fillAll();

    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}