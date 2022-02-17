#include "MusicMachine.h"
void MusicMachine::printComputerNameAndKnobMaterial()
{
    std::cout << "music machine computer name is: " << this->computer.computerName << ". The tone control knob material is: " << this->toneControl.knobMaterial << std::endl;
}

MusicMachine::MusicMachine()
{
    std::cout << "MusicMachine constructed" << std::endl;
}
MusicMachine::~MusicMachine()
{
    std::cout << "ending computing" << std::endl;
    endComputing(computer);
    std::cout << "MusicMachine destructed " << std::endl;
}
void MusicMachine::powerOnComputer( const Computer& comp )
{
    comp.runMemtest();
    std::cout << "powering on" << std::endl;
}
void MusicMachine::adjustToneControl(ToneControl& toneControl1)
{
    toneControl1.autoAdjust();
}
void MusicMachine::powerOffComputer(Computer& computer11)
{    
    computer11.updateGraphicsDriver(computer11.graphicsAccelerator);
    std::cout << "updating graphics and powering off" << std::endl;
}
void MusicMachine::endComputing(Computer& computerA)
{
    computerA.runMultipleProcesses();
    std::cout << "computing has ended on computer with" << computerA.motherboardType << " and " << computerA.memoryInGB << "GB of RAM" << std::endl;
}



