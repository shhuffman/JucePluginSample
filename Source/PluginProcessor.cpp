/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "KAPParameters.h"

using Parameter = AudioProcessorValueTreeState::Parameter;
AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;

    for (int i = 0; i < kParameter_TotalNumParameters; i++)
    {
        params.push_back(std::make_unique<AudioParameterFloat>(
            KAPParameterID[i],
            KAPParameterLabel[i],
            NormalisableRange(0.0f, 1.0f),
            KAPParameterDefaultValue[i]));
    }
    return { params.begin(), params.end() };
}



//==============================================================================
KadenzeAudioPluginAudioProcessor::KadenzeAudioPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
                       parameters(*this,    //reference to the processor
                                   nullptr, //null pointer to where the undoManager would go
                           juce::Identifier("KAP"),
                           createParameterLayout())
                                   
#endif
{
    initializeDSP();
}


//==============================================================================
void KadenzeAudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (int i = 0; i < 2; i++)
    {
        mDelay[i]->setSampleRate(sampleRate);
        mLfo[i]  ->setSampleRate(sampleRate);
    }
}

void KadenzeAudioPluginAudioProcessor::releaseResources()
{
    for (int i = 0; i < 2; i++)
    {
        mDelay[i]->reset();
        mLfo[i]  ->reset();
    }
}

void KadenzeAudioPluginAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);



        float inputGain  = *parameters.getRawParameterValue(KAPParameterID[kParameter_InputGain]);

        float mRate      = *parameters.getRawParameterValue(KAPParameterID[kParameter_ModulationRate]);
        float mDepth     = *parameters.getRawParameterValue(KAPParameterID[kParameter_ModulationDepth]);

        float dTime      = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayTime]);
        float dFeedback  = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayFeedback]);
        float dWetDry    = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayWetDry]);
        float dType      = *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayType]);


        float outputGain = *parameters.getRawParameterValue(KAPParameterID[kParameter_OutputGain]);



        mInputGain[channel]->process(channelData, 
                                     inputGain, 
                                     channelData, 
                                     buffer.getNumSamples());


        float rate = channel == 0 ? 0 : mRate;


        mLfo[channel]->process(rate, 
                               mDepth, 
                               buffer.getNumSamples());


        mDelay[channel]->process(channelData, 
                                 dTime, 
                                 dFeedback, 
                                 dWetDry,
                                 dType,
                                 mLfo[channel]->getBuffer(),
                                 channelData, 
                                 buffer.getNumSamples());


        mOutputGain[channel]->process(channelData,
                                      outputGain,
                                      channelData,
                                      buffer.getNumSamples());
    }
}

AudioProcessorEditor* KadenzeAudioPluginAudioProcessor::createEditor()
{
    return new KadenzeAudioPluginAudioProcessorEditor (*this);
}


//==============================================================================
void KadenzeAudioPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void KadenzeAudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}



//==============================================================================
void KadenzeAudioPluginAudioProcessor::initializeDSP()
{
    for (int i = 0; i < 2; i++)
    {
        mInputGain[i]  = std::make_unique<KAPGain>();
        mOutputGain[i] = std::make_unique<KAPGain>();
        mDelay[i]      = std::make_unique<KAPDelay>();
        mLfo[i]        = std::make_unique<KAPLfo>();
    }
}




//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KadenzeAudioPluginAudioProcessor();
}
