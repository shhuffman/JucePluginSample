/*
  ==============================================================================

    KAPParameters.h
    Created: 21 Oct 2019 7:26:38pm
    Author:  Houston

  ==============================================================================
*/

#pragma once


enum KAPParameters
{
    kParameter_InputGain = 0,
    kParameter_DelayTime,
    kParameter_DelayFeedback,
    kParameter_DelayWetDry,
    kParameter_DelayType, // chorus or delay?
    kParameter_OutputGain,
    kParameter_ModulationRate,
    kParameter_ModulationDepth,
    kParameter_TotalNumParameters
};

static float KAPParameterDefaultValue[kParameter_TotalNumParameters] =
{
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    0.5f
};


static String KAPParameterLabel[kParameter_TotalNumParameters] =
{
    "Input Gain",
    "Delay Time",
    "Feedback",
    "Wet/Dry",
    "Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth",
};


static String KAPParameterID[kParameter_TotalNumParameters] =
{
    "inGain",
    "delayTime",
    "delayFeedback",
    "delayWetDry",
    "delayType",
    "outGain",
    "modRate",
    "modDepth"
};