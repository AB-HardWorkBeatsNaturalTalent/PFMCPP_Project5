#pragma once
#include "LeakedObjectDetector.h"
struct ToneControl
{
    struct ToneAlgorithm
    {
        //1 tone color 1
        int color1;
        //2 tone color 2
        int color2;
        //3 tone color 3
        int color3;
        //4 upper Limit
        float upperLimit = 1.0f;
        //5 lower Limit
        float lowerLimit = 0.0f;

        ToneAlgorithm();
        ~ToneAlgorithm();
        //1 set tone colors
        void setToneColors(int color1, int color2, int color3);//input each color to set
        //2 set upper limit
        bool setUpperLimit(float upperLimit = 1.0f);
        //return true if success, else false;
        //3 set lower limit
        bool setLowerLimit(float lowerLimit = 0.0f);
        //return true if success, else false;
        
        int toIncrement = 0;

        void incrementAndSetColors(int color11, int color22, int color33);

        void printLowerLimit();
        void printSecondColor();
    };
    

    //1) front pickup tone control setting (float)
    float frontPickupToneControlSetting = 1.0f;
    //2) rear pickup tone control setting  (float)
    float rearPickupToneControlSetting = 1.0f;
    //3) knob color (std::string)
    std::string knobColor = "silver";
    //4) knob material (std::string)
    std::string knobMaterial = "plastic";
    //5) is smooth to turn (bool)
    bool isSmoothToTurn = true;
    std::string tcName;

    ToneAlgorithm toneAlgorithms;
    char toneAlgoType = 'A';

    void changeToneAlgorithm();


    ToneControl(std::string tcName);
    //1) set tone level
    float setToneLevel(float inputLevel, float adjustment); //apply adjustment to the inputlevel and return the adjusted tone level
    //2) require repair
    bool requireRepair();//returns true if the tone control requires repair
    //3) auto adjust
    bool autoAdjust();//returns true if autoAdjust is turned on; else false 

    void useToneAlgorithm();

    void printAutoAdjust();
    void printKnobColor();
    JUCE_LEAK_DETECTOR(ToneControl)
};
