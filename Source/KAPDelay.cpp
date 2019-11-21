/*
  ==============================================================================

    KAPDelay.cpp
    Created: 20 Oct 2019 7:24:34pm
    Author:  Houston

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"


KAPDelay::KAPDelay() : 
    mSampleRate(-1), 
    mFeedbackSample(0.0),
    mTimeSmoothed(0.0f),
    mDelayIndex(0)
{
}

KAPDelay::~KAPDelay(){}

void KAPDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPDelay::reset()
{
    mTimeSmoothed = 0.0f;
    zeromem(mBuffer, sizeof(double) * maxBufferSize);
}

void KAPDelay::process(float* inAudio,
                       float  inTime,
                       float  inFeedback,
                       float  inWetDry,
                       float  inType,
                       float* inModulationBuffer,
                       float* outAudio,
                       int    inNumSamplesToRender)
{
    const double wet = inWetDry;
    const double dry = 1.0f - wet;
    const double feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);
    
    for (int i = 0; i < inNumSamplesToRender; i++)
    {
        if ((int)inType == kKAPDelayType_Delay)
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - inTime);
        else
        {
            const double delayTimeModulation = (0.003 + (0.002 * inModulationBuffer[i]));
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - delayTimeModulation);
        }

        const double delayTimeInSamples = ((mTimeSmoothed) * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);

        mFeedbackSample = sample;
        outAudio[i] = ((inAudio[i] * dry) + (sample * wet));
        mDelayIndex++;

        if (mDelayIndex >= maxBufferSize)
            mDelayIndex -= maxBufferSize;
    }
}


double KAPDelay::getInterpolatedSample(double inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;

    if (readPosition < 0.0f)
        readPosition = readPosition + maxBufferSize;


    // previous sample
    int index_y0 = (int)readPosition - 1;


    // if index_y0 = -1, this sets it to the end of the buffer array
    if (index_y0 <= 0)
        index_y0 += maxBufferSize;

    //current sample
    int index_y1 = readPosition;

    // if we pass the end of our array, make sure we wrap around to the beginning
    if (index_y1 > maxBufferSize)
        index_y1 -= maxBufferSize;
    
    const double sample_y0 = mBuffer[index_y0];
    const double sample_y1 = mBuffer[index_y1];
    const double t = readPosition - (int)readPosition;
    
    double outSample = kap_linear_interp(sample_y0, sample_y1, t);

    return outSample;
}