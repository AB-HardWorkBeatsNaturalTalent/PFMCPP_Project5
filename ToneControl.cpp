#include "ToneControl.h"

void ToneControl::ToneAlgorithm::printLowerLimit()
{
    std::cout << "lower limit set to:" << this->setLowerLimit(.02f) << std::endl;
}
void ToneControl::ToneAlgorithm::printSecondColor()
{
    std::cout << "second color parameter: " << this->color2 << std::endl;
}
void ToneControl::printKnobColor()
{
    std::cout << "knob color is " << this->knobColor << std::endl;
}
void ToneControl::printAutoAdjust()
{
    std::cout << "auto adjusted tone: "  << this->autoAdjust() << std::endl;
}
ToneControl::ToneControl(std::string toneControlName) : tcName(toneControlName)
{
    std::cout << "ToneControl being constructed" << std::endl;
}

ToneControl::ToneAlgorithm::ToneAlgorithm(): color1(10), color2(11), color3(12)
{
    std::cout << "ToneAlgorithm constructing with upper limit: " <<  upperLimit << "and lower limit: " << lowerLimit <<std::endl;
}

void ToneControl::ToneAlgorithm::setToneColors(int c1, int c2, int c3)
{
    std::cout << "tone color set to " << c1 << ", " << c2 << ", " << c3 << std::endl;
}

bool ToneControl::ToneAlgorithm::setUpperLimit(float upperLimit1)
{
    std::cout << upperLimit1 << std::endl;
    return true;
}

bool ToneControl::ToneAlgorithm::setLowerLimit(float lowerLimit1)
{
    std::cout << lowerLimit1 << std::endl;
    return true;
}

float ToneControl::setToneLevel(float input, float adjust)
{
    std::cout << input << " is good" << std::endl;
    float toReturn = input - adjust;
    std::cout << (input - adjust) << " is adjusted amount" << std::endl;

    return toReturn;
}

bool ToneControl::requireRepair()
{
    return true;
}

bool ToneControl::autoAdjust()
{
    return true;
}

ToneControl::ToneAlgorithm::~ToneAlgorithm()
{
    std::cout << "ToneAlgorithm destructing" << std::endl;
}

void ToneControl::ToneAlgorithm::incrementAndSetColors(int color11, int color22, int color33)
{
    setToneColors(color11, color22, color33);
    std::cout << "before a while" << toIncrement;
    while(toIncrement < 10)
    {
        setToneColors(color11 + toIncrement, color22 + toIncrement, color33 + toIncrement);
        //do nothing
        std::cout << "doing nothing but this" << std::endl;
        ++toIncrement;
    }
    std::cout << "after a while" << toIncrement;            
}

void ToneControl::changeToneAlgorithm()
{
    if(toneAlgoType == 'A')
    {
        toneAlgorithms.incrementAndSetColors(30,40,50);
        toneAlgoType = 'B';
    }
    else
    {
        toneAlgoType = 'A';
        toneAlgorithms.incrementAndSetColors(20,30,52);
    }        
}

void ToneControl::useToneAlgorithm()
{
    changeToneAlgorithm();
}
