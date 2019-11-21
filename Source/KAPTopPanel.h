/*
  ==============================================================================

    KAPTopPanel.h
    Created: 20 Oct 2019 11:48:43pm
    Author:  Houston

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"

class KAPTopPanel : public KAPPanelBase
{
public:

    KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();

    void paint(Graphics& g) override;

private:
};