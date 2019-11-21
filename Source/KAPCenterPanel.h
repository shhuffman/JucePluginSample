/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 20 Oct 2019 11:47:57pm
    Author:  Houston

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPCenterPanelMenuBar.h"
#include "KAPEffectsPanel.h"

class KAPCenterPanel : public KAPPanelBase
{
public:
    KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanel();



private:
    std::unique_ptr<KAPCenterPanelMenuBar> mMenuBar;
    std::unique_ptr<KAPFxPanel> mFxPanel;
};