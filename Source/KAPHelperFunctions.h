/*
  ==============================================================================

    KAPHelperFunctions.h
    Created: 21 Oct 2019 10:51:18pm
    Author:  Houston

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"


inline void paintComponentLabel(Graphics& g, Component* inComponent)
{
    const int x = inComponent->getX() - (inComponent->getWidth() * 0.25);
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth() * 1.5;
    const int h = 20;

    const String label = inComponent->getName();

    //const float cornerSize = 3.0f;

    g.setColour(Colours::darkgrey);
    g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
}