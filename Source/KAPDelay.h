/*
  ==============================================================================

    KAPDelay.h
    Created: 20 Oct 2019 7:24:34pm
    Author:  Houston

  ==============================================================================
*/

#pragma once
#include "KAPAudioHelpers.h"

enum KAPDelayType
{
    kKAPDelayType_Delay = 0,
    kKAPDelayType_Chorus
};

class KAPDelay
{
public:
    KAPDelay();
    ~KAPDelay();

    void setSampleRate(double inSampleRate);

    void reset();
    
    void process(float* inAudio,
                 float  inTime,
                 float  inFeedback,
                 float  inWetDry,
                 float  inType,
                 float* inModulationBuffer,
                 float* outAudio,
                 int    inNumSamplesToRender);


private:
    /** internal */
    double getInterpolatedSample(double inDelayTimeInSamples);

    double mSampleRate;
    double mBuffer[maxBufferSize];
    double mFeedbackSample;

    float mTimeSmoothed;

    int mDelayIndex;
};