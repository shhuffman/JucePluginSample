/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "KAPGain.h"
#include "KAPDelay.h"
#include "KAPLfo.h"
#include "KAPAudioHelpers.h"

//==============================================================================
/**
*/
class KadenzeAudioPluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    KadenzeAudioPluginAudioProcessor();
    ~KadenzeAudioPluginAudioProcessor() {}

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override
    {
#if JucePlugin_IsMidiEffect
        ignoreUnused(layouts);
        return true;
#else
        // This is the place where you check if the layout is supported.
        // In this template code we only support mono or stereo.
        if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
            && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
            return false;

        // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
        if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
            return false;
#endif

        return true;
#endif
    }

   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;

    //==============================================================================
    bool hasEditor() const override
    {
        return true; // (change this to false if you choose to not supply an editor)
    }

    //==============================================================================

    //==============================================================================
    const String getName() const override
    {
        return JucePlugin_Name;
    }

    bool acceptsMidi() const override
    {
#if JucePlugin_WantsMidiInput
        return true;
#else
        return false;
#endif
    }

    bool producesMidi() const override
    {
#if JucePlugin_ProducesMidiOutput
        return true;
#else
        return false;
#endif
    }

    bool isMidiEffect() const override
    {
#if JucePlugin_IsMidiEffect
        return true;
#else
        return false;
#endif
    }

    double getTailLengthSeconds() const override
    {
        return 0.0;
    }

    //==============================================================================

    int getNumPrograms() override
    {
        return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                    // so this should be at least 1, even if you're not really implementing programs.
    }

    int getCurrentProgram() override
    {
        return 0;
    }

    void setCurrentProgram(int index) override
    {

    }

    const String getProgramName(int index) override
    {
        return {};
    }

    void changeProgramName(int index, const String& newName) override
    {

    }

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    AudioProcessorValueTreeState parameters;

private:
    //==============================================================================
    
    /** internal */
    void initializeDSP();


    std::unique_ptr<KAPGain>  mInputGain[2];
    std::unique_ptr<KAPGain>  mOutputGain[2];
    std::unique_ptr<KAPDelay> mDelay[2];
    std::unique_ptr<KAPLfo>   mLfo[2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KadenzeAudioPluginAudioProcessor)
};
