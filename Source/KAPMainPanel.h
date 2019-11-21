/*
  ==============================================================================

    KAPMainPanel.h
    Created: 20 Oct 2019 11:47:49pm
    Author:  Houston

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"
#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCenterPanel.h"
#include "KAPEffectsPanel.h"


class KAPMainPanel : public KAPPanelBase
{
public:

    KAPMainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPMainPanel();

private:
    std::unique_ptr<KAPTopPanel>    mTopPanel;
    std::unique_ptr<KAPGainPanel>   mInputGainPanel;
    std::unique_ptr<KAPGainPanel>   mOutputGainPanel;
    std::unique_ptr<KAPCenterPanel> mCenterPanel;
};