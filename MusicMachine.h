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

    void powerOnComputer( const Computer& computer1 ) const;
    void adjustToneControl( ToneControl& toneControl1 );
    void powerOffComputer( const Computer& computer1 ) const;
    void endComputing( const Computer& computer ) const;
    void printComputerNameAndKnobMaterial();
    JUCE_LEAK_DETECTOR(MusicMachine)
};
