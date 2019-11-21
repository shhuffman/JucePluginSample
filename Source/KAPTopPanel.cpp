/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 20 Oct 2019 11:48:43pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPTopPanel.h"


KAPTopPanel::KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor) : KAPPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}


KAPTopPanel::~KAPTopPanel()
{

}

void KAPTopPanel::paint(Graphics& g)
{
    KAPPanelBase::paint(g);

    g.drawFittedText("KADENZE AUDIO PLUGIN", 0, 0, getWidth()-10, getHeight(), Justification::centredRight, 1);
}