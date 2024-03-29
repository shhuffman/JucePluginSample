/*
  ==============================================================================

    KAPGain.cpp
    Created: 20 Oct 2019 7:24:25pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPGain.h"
#include "JuceHeader.h"


KAPGain::KAPGain()
{

}


KAPGain::~KAPGain()
{

}

void KAPGain::process(float* inAudio,
                      float  inGain,
                      float* outAudio,
                      int inNumSamplesToRender)
{
    float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);


    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        outAudio[i] = inAudio[i] * gainMapped;
    }
}