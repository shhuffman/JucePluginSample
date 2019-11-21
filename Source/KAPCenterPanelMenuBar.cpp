/*
  ==============================================================================

    KAPCenterPanelMenuBar.cpp
    Created: 20 Oct 2019 11:48:07pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPCenterPanelMenuBar.h"
#include "KAPParameters.h"


KAPCenterPanelMenuBar::KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);

    const int width = 85;
    mFxTypeComboBox = std::make_unique<KAPParameterComboBox>(mProcessor->parameters, KAPParameterID[kParameter_DelayType]);
    mFxTypeComboBox->addItem("DELAY",  1);
    mFxTypeComboBox->addItem("CHORUS", 2);
    mFxTypeComboBox->setSelectedItemIndex(mProcessor->getParameter((int)kParameter_DelayType), dontSendNotification);
    mFxTypeComboBox->setBounds(getWidth() - width, 0, width, getHeight());
    addAndMakeVisible(mFxTypeComboBox.get());
}


KAPCenterPanelMenuBar::~KAPCenterPanelMenuBar()
{
}

void KAPCenterPanelMenuBar::addFxTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFxTypeComboBox->addListener(inListener);
}

void KAPCenterPanelMenuBar::removeFxTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFxTypeComboBox->removeListener(inListener);
}