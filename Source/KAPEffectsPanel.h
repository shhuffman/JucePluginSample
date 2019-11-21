/*
  ==============================================================================

    KAPEffectsPanel.h
    Created: 20 Oct 2019 11:48:20pm
    Author:  Houston

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

enum class KAPFxPanelStyle
{
    kFxStyle_Delay,
    kFxStyle_Chorus,
    kFxStyle_TotalNumStyles
};

class KAPFxPanel : public KAPPanelBase, public ComboBox::Listener
{
public:
    KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPFxPanel();

    void paint(Graphics& g) override;

    void setFxPanelStyle(KAPFxPanelStyle inStyle);

    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;

private:
    KAPFxPanelStyle mStyle;

    OwnedArray<KAPParameterSlider> mSliders;
};