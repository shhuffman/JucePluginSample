/*
  ==============================================================================

    KAPLfo.h
    Created: 20 Oct 2019 7:24:16pm
    Author:  Houston

  ==============================================================================
*/

#pragma once
#include "KAPAudioHelpers.h"

class KAPLfo
{
public:
    KAPLfo();
    ~KAPLfo();

    void setSampleRate(double inSampleRate);

    void reset();

    void process(float inRate, float inDepth, int inNumSamples);

    float* getBuffer();

private:
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferSize];
};