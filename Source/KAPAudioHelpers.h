/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 20 Oct 2019 7:23:47pm
    Author:  Houston

  ==============================================================================
*/

#pragma once

#define _USE_MATH_DEFINES

// useful for smoothing at the block level
constexpr auto kParameterSmoothingCoeff_Generic = 0.04;

// useful for smoothing sample rates
constexpr auto kParameterSmoothingCoeff_Fine    = 0.002;

#include <cmath>
#include <math.h>

const int maxBufferSize = 192000;

// Linear Interpolation Function
//
// float v0 -- position 1
// float v1 -- position 2
// float t  -- fractional difference between position points
inline double kap_linear_interp(double v0, double v1, double t)
{
    return (1 - t) * v0 + t * v1;
}