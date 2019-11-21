/*
  ==============================================================================

    KAPCenterPanelMenuBar.h
    Created: 20 Oct 2019 11:48:07pm
    Author:  Houston

  ==============================================================================
*/

#pragma once


#include "KAPPanelBase.h"
#include "KAPParameterComboBox.h"

class KAPCenterPanelMenuBar : public KAPPanelBase
{
public:
    KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanelMenuBar();

    void addFxTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFxTypeComboBoxListener(ComboBox::Listener* inListener);

private:

    std::unique_ptr<KAPParameterComboBox> mFxTypeComboBox;
};