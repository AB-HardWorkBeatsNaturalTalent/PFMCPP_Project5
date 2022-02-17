#pragma once
#include "Computer.h"
#include "ToneControl.h"
#include "LeakedObjectDetector.h"
struct MusicMachine
{
    Computer computer = Computer("constructor computer");
    ToneControl toneControl = ToneControl("toneMaster construct");

    MusicMachine();
    ~MusicMachine();

    void powerOnComputer( Computer& computer1 );
    void adjustToneControl( ToneControl& toneControl1 );
    void powerOffComputer( Computer& computer1 );
    void endComputing( Computer& computer );
    void printComputerNameAndKnobMaterial();
    JUCE_LEAK_DETECTOR(MusicMachine)
};
