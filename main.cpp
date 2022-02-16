/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
         
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */



/*
Thing 1) Computer
 */
struct Computer
{ 
    struct GraphicsAccelerator
    {
        //is gsync capable
        bool isGSyncCapable;
        //number of cuda cores
        int numberOfCUDACores;
        //model name 
        std::string modelName = "default GPU";
        //price
        float price = 100.00f;
        //maximum SLI capability
        int maxSLICapability = 2;

        GraphicsAccelerator();
        ~GraphicsAccelerator();
        //accelerate the graphics
        void accelerateGraphics();//attempts to run code in parallel
        //set price of Graphics accelerator
        bool setPrice(float newPrice = 100.0f);
        //output cuda version and number of cores
        std::string outputCUDAVersionAndCores();//returns a string representing the cuda capbility 

        void printMaxSLI();

        void boostTheGraphics(int toMultiply);
        int parallelSpeedIncreaseFactor(int desiredFactor);
    };

    //1) number of processor cores (int)
    int numberOfProcessorCores;
    //2) memory In GB (int)
    int memoryInGB;
    //3) graphics accelerator (std::string)
    GraphicsAccelerator graphicsAccelerator;
    //4) motherboard type (std::string)
    std::string motherboardType;
    //5) audio interface name (std::string)
    std::string audioInterfaceName;
    std::string computerName;

    Computer(std::string pcName);
    //1) run multiple processes 
    void runMultipleProcesses();
    //2) run memtest
    void runMemtest();
    //3) update Graphics Driver
    //return true on connection success
    bool updateGraphicsDriver(GraphicsAccelerator& graphicsAccelerator);
    //input the graphics accelerator to update drivers for
    //returns true if driver updated successfully;
    double analyzeEnergyConsumption(int numberOfSecondsPoweredOn);
    std::string memoryTopologyBlocksPerCore();
    void printMemInGB();
    JUCE_LEAK_DETECTOR(Computer)
};
Computer::Computer(std::string pcName) : numberOfProcessorCores(5),  memoryInGB(32), motherboardType("micro ATX"), audioInterfaceName("ableton"), computerName(pcName)
{
    std::cout << "Computer being constructed" << std::endl; 
}
Computer::GraphicsAccelerator::GraphicsAccelerator() : isGSyncCapable(true), numberOfCUDACores(1200)
{
    std::cout << "GraphicsAccelerator being constructed" << std::endl;
}
void Computer::GraphicsAccelerator::accelerateGraphics()
{
    //do nothing
}
bool Computer::GraphicsAccelerator::setPrice([[maybe_unused]]float toPrice)
{
    return false;
}
std::string Computer::GraphicsAccelerator::outputCUDAVersionAndCores()
{
    return "hello world";
}

void Computer::GraphicsAccelerator::printMaxSLI()
{        
    std::cout << "max sli capability: " << this->maxSLICapability << std::endl;
}

void Computer::runMultipleProcesses()
{
    //imagine running in parallel
}
void Computer::runMemtest()
{    
    std::cout << "memtest running on " << memoryInGB << "GB" << std::endl;
}
bool Computer::updateGraphicsDriver(GraphicsAccelerator& gA)
{
    std::string throwAway = gA.outputCUDAVersionAndCores();  
    return true;
}
void Computer::printMemInGB()
{
    std::cout << this->memoryInGB << " GB of RAM in this model" << std::endl;
}

Computer::GraphicsAccelerator::~GraphicsAccelerator()
{
    std::cout << "GraphicsAccelerator destructor" << std::endl;
}
void Computer::GraphicsAccelerator::boostTheGraphics(int multiply)
{
    if(multiply >0)
    {
        int testValue = 0;
        while(multiply > 0)
        {
            ++testValue;
            std::cout << "Boosted!" << std::endl;
            --multiply;
        }
        std::cout << "Out of Boost" << std::endl;
    }
    else
    {
        std::cout << "zero or negative boost only" << std::endl;
    }
} // part 5 begin.

int Computer::GraphicsAccelerator::parallelSpeedIncreaseFactor(int desiredFactor)
{
    int totalCoresProcessing = 0;
    for(int i = 0; i <= maxSLICapability; ++i)
    {
        std::cout << "boosted processor core block i: " << i * desiredFactor << std::endl;
        totalCoresProcessing += i * desiredFactor;
        if(i == 6) break;
    }
    std::cout << "more money more problems solved" << std::endl;
    return totalCoresProcessing;
}

double Computer::analyzeEnergyConsumption(int numberOfSecondsPoweredOn)
{
    double consumed = numberOfSecondsPoweredOn * memoryInGB * .0345;
    if(graphicsAccelerator.isGSyncCapable)
    {
        consumed *= 4;
    }
    std::cout << "for the sake of science; energy consumed: " << consumed << std::endl;
    return consumed;

}

std::string Computer::memoryTopologyBlocksPerCore()
{
    //number of cores & number of GB RAM
    int memoryPerCore = memoryInGB / numberOfProcessorCores;
    
    std::string memoryTopology = "";        
    while(numberOfProcessorCores > 0)
    {
        for(int i = 0; i <= memoryPerCore; ++i)
        {
            memoryTopology += "block: ";
            memoryTopology += std::to_string(i);
            memoryTopology += "core :";
            memoryTopology += std::to_string(numberOfProcessorCores);
            memoryTopology += "\n"; 
        }
        --numberOfProcessorCores;
    }
    return memoryTopology;
}
struct ComputerWrapper
{
    ComputerWrapper( Computer* ptr ) : ptrToComputer( ptr ) { }
    ~ComputerWrapper() 
    {
        delete ptrToComputer;
    }
    Computer* ptrToComputer = nullptr;
};

/*
 copied UDT 2: Teacher
 */
struct Teacher
{

    //1) credential type (std::string)
    std::string credentialType = "no credential";
    //2) domain expertise (std::string)
    std::string domainExpertise;
    //3) number of classes taught (int)
    int numberOfClassesTaught = 6;
    //4) years of tenure (float)
    float yearsOfTenure = 1;
    //5) rating by students (char)
    char ratingByStudents  = 'F';

    Teacher();
    ~Teacher();
    //1) give lecture
    void giveLecture();
    //2) private tutoring
    // returns the amount of money made from private tutoring
    float privateTutoring(float hourlyRate, int numberOfHours = 1); //input hourly rate and number of hours
    //3) assign homework
    void assignHomework(std::string homeworkAssignment);//input a string representation of the homework

    void printStudentsRating();
    void sayMeaninglessNumbers(int startingWith);
    JUCE_LEAK_DETECTOR(Teacher)
};

Teacher::Teacher() : domainExpertise("philosophy")
{
    std::cout << "Teacher being constructed" << std::endl;
}
Teacher::~Teacher()
{
    std::cout << "Teacher destructing" << std::endl;
}
void Teacher::giveLecture()
{
    std::cout << "class of " << domainExpertise <<std::endl;
}
float Teacher::privateTutoring(float hourlyRate, int numberOfHours)
{
    return hourlyRate * numberOfHours;
}
void Teacher::assignHomework(std::string homeworkAssignment)
{
    std::cout << homeworkAssignment << " assigned to class" << std::endl;
}
void Teacher::sayMeaninglessNumbers(int startingWith)
{
    if(startingWith > 0)
    {        
        int numberOfStuff = numberOfClassesTaught * startingWith;
        std::cout << "I have taught " << numberOfStuff << "things" << std::endl;
        std::cout << "that is ";
        while(startingWith > 0)
        {
            --startingWith;
            std::cout << "so interesting: " << startingWith << std::endl;
        }
        std::cout << std::endl;
        return;
    }
    std::cout << "i have only taught 1 thing" << std::endl;        
}
void Teacher::printStudentsRating()
{
    std::cout << "the students rate you: " << this->ratingByStudents << std::endl;
}



struct TeacherWrapper
{
    TeacherWrapper( Teacher* ptr ) : ptrToTeacher(ptr) { }
    ~TeacherWrapper()
    {
        delete ptrToTeacher;
    }
    Teacher* ptrToTeacher = nullptr;
};
/*
 copied UDT 3: ToneControl
 */
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
struct ToneControlWrapper
{
    ToneControlWrapper( ToneControl* ptr ) : ptrToToneControl(ptr) { }
    ~ToneControlWrapper()
    {
        delete ptrToToneControl;
    }
    ToneControl* ptrToToneControl = nullptr;
};


/*
 new UDT 4: MusicMachine
 with 2 member functions
 */
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
void MusicMachine::powerOnComputer( Computer& comp )
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


struct MusicMachineWrapper
{
    MusicMachineWrapper( MusicMachine* ptr ) : ptrToMusicMachine(ptr) { }
    ~MusicMachineWrapper()
    {
        delete ptrToMusicMachine;
    }
    MusicMachine* ptrToMusicMachine = nullptr;
};
/*
 new UDT 5:
 with 2 member functions
 */
struct Classroom
{
    Teacher teacher;
    std::string classroomName;

    Classroom();
    ~Classroom();

    void hireTeacher(Teacher& teach);
    void fireTeacher();
    void chooseClassPresident(std::string nameOfPresident);
    void printClassroomName();
    JUCE_LEAK_DETECTOR(Classroom)
};

void Classroom::printClassroomName()
{
    std::cout << "the classroom name is: " << this->classroomName << std::endl;
}
Classroom::Classroom() : classroomName("default name")
{
    std::cout << "Constructing Classroom named:" << classroomName << std::endl;
}
Classroom::~Classroom()
{   
    std::cout << "before the classroom is gone, it will elect a new class president " << std::endl;
    chooseClassPresident("billy");
    std::cout << "Classroom destructed" << std::endl;
}
void Classroom::hireTeacher(Teacher& teacherToHire)
{
    teacherToHire.giveLecture();
    std::cout << "Welcome aboard" << std::endl;
}
void Classroom::fireTeacher()
{
    std::cout << "you're outta here!" << std::endl;
}
void Classroom::chooseClassPresident(std::string nameOfPresident)
{
    std::cout << "the new president is: " << nameOfPresident << std::endl;
}
struct ClassroomWrapper
{
    ClassroomWrapper( Classroom* ptr ) : ptrToClassroom(ptr) { }
    ~ClassroomWrapper()
    {
        delete ptrToClassroom;
    }
    Classroom* ptrToClassroom = nullptr;
};


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
//GraphicsAccelerator methods
    auto computerGraphicsAccelerator = Computer::GraphicsAccelerator();
    computerGraphicsAccelerator.outputCUDAVersionAndCores();
    computerGraphicsAccelerator.accelerateGraphics();
    computerGraphicsAccelerator.setPrice(400.0f);

    std::cout << "cuda info: " << computerGraphicsAccelerator.outputCUDAVersionAndCores() << std::endl;

    std::cout << "max sli capability: " << computerGraphicsAccelerator.maxSLICapability << std::endl;
    computerGraphicsAccelerator.printMaxSLI();

//Computer methods
    auto computer = ComputerWrapper( new Computer("doopy") );
    
    std::cout << "updated graphics: " << computer.ptrToComputer->updateGraphicsDriver(computerGraphicsAccelerator) << std::endl;
    computer.ptrToComputer->runMemtest();
    computer.ptrToComputer->runMultipleProcesses();

    std::cout << computer.ptrToComputer->memoryInGB << " GB of RAM in this model" << std::endl;
    computer.ptrToComputer->printMemInGB();

    

//Teacher methods
    auto teacher = TeacherWrapper( new Teacher() );
    teacher.ptrToTeacher->assignHomework("lesson 2");
    teacher.ptrToTeacher->giveLecture();    
    std::cout << "money made: " << teacher.ptrToTeacher->privateTutoring(50.00f) << std::endl;

    std::cout << "the students rate you: " << teacher.ptrToTeacher->ratingByStudents << std::endl;
    teacher.ptrToTeacher->printStudentsRating();

//ToneControl methods
    auto toneControl = ToneControlWrapper( new ToneControl("boopy") );  
    toneControl.ptrToToneControl->setToneLevel(3.9f, 2.0f);
    toneControl.ptrToToneControl->requireRepair();
    std::cout << "auto adjusted tone: "  << toneControl.ptrToToneControl->autoAdjust() << std::endl;
    toneControl.ptrToToneControl->printAutoAdjust();
    std::cout << "knob color is " << toneControl.ptrToToneControl->knobColor << std::endl;
    toneControl.ptrToToneControl->printKnobColor();

//ToneAlgorithm methods
    auto toneAlgorithm = ToneControl::ToneAlgorithm();
    toneAlgorithm.setUpperLimit(1.09f);
    toneAlgorithm.setToneColors(1, 2, 3);
    std::cout << "lower limit set to:" << toneAlgorithm.setLowerLimit(.02f) << std::endl;
    toneAlgorithm.printLowerLimit();
    std::cout << "second color parameter: " << toneAlgorithm.color2 << std::endl;
    toneAlgorithm.printSecondColor();

//MusicMachine methods
    auto musicMachine = MusicMachineWrapper( new MusicMachine() );
    musicMachine.ptrToMusicMachine->powerOnComputer(*computer.ptrToComputer);
    musicMachine.ptrToMusicMachine->adjustToneControl(*toneControl.ptrToToneControl);
    musicMachine.ptrToMusicMachine->powerOffComputer(*computer.ptrToComputer);
    musicMachine.ptrToMusicMachine->endComputing(*computer.ptrToComputer);

    std::cout << "music machine computer name is: " << musicMachine.ptrToMusicMachine->computer.computerName << ". The tone control knob material is: " << musicMachine.ptrToMusicMachine->toneControl.knobMaterial << std::endl;
    musicMachine.ptrToMusicMachine->printComputerNameAndKnobMaterial();

//Classroom methods
    auto classroom = ClassroomWrapper( new Classroom() );
    classroom.ptrToClassroom->hireTeacher(*teacher.ptrToTeacher);
    classroom.ptrToClassroom->fireTeacher();
    classroom.ptrToClassroom->chooseClassPresident("juanita");

    std::cout << "the classroom name is: " << classroom.ptrToClassroom->classroomName << std::endl;
    classroom.ptrToClassroom->printClassroomName();
    
    std::cout << "good to go!" << std::endl;
    
}
