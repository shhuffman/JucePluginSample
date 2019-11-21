/*
  ==============================================================================

    KAPGain.h
    Created: 20 Oct 2019 7:24:25pm
    Author:  Houston

  ==============================================================================
*/

#pragma once


class KAPGain
{
public:
    KAPGain();
    ~KAPGain();

    void process(float* inAudio, 
                 float  inGain,
                 float* outAudio,
                 int    inNumSamplesToRender);


private:
};