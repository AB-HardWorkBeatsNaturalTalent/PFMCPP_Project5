/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() 
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
/*
 copied UDT 1:Computer
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
    bool updateGraphicsDriver(GraphicsAccelerator graphicsAccelerator);
    //input the graphics accelerator to update drivers for
    //returns true if driver updated successfully;

    double analyzeEnergyConsumption(int numberOfSecondsPoweredOn);
    std::string memoryTopologyBlocksPerCore();

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

void Computer::runMultipleProcesses()
{
    //imagine running in parallel
}
void Computer::runMemtest()
{    
    std::cout << "memtest running on " << memoryInGB << "GB" << std::endl;
}
bool Computer::updateGraphicsDriver(GraphicsAccelerator gA)
{
    std::string throwAway = gA.outputCUDAVersionAndCores();  
    return true;
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

    void sayMeaninglessNumbers(int startingWith);
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
};

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

    void powerOnComputer(Computer computer1);
    void adjustToneControl(ToneControl toneControl1);
    void powerOffComputer(Computer computer1);
    void endComputing(Computer computer);
};

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
void MusicMachine::powerOnComputer(Computer comp)
{
    comp.runMemtest();
    std::cout << "powering on" << std::endl;
}
void MusicMachine::adjustToneControl(ToneControl toneControl1)
{
    toneControl1.autoAdjust();
}
void MusicMachine::powerOffComputer(Computer computer11)
{    
    computer11.updateGraphicsDriver(computer11.graphicsAccelerator);
    std::cout << "updating graphics and powering off" << std::endl;
}
void MusicMachine::endComputing(Computer computerA)
{
    computerA.runMultipleProcesses();
    std::cout << "computing has ended on computer with" << computerA.motherboardType << " and " << computerA.memoryInGB << "GB of RAM" << std::endl;
}

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

    void hireTeacher(Teacher teach);
    void fireTeacher();
    void chooseClassPresident(std::string nameOfPresident);
};

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
void Classroom::hireTeacher(Teacher teacherToHire)
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

//Computer methods
    auto computer = Computer("doopy");
    std::cout << "updated graphics: " << computer.updateGraphicsDriver(computerGraphicsAccelerator) << std::endl;
    computer.runMemtest();
    computer.runMultipleProcesses();

    std::cout << computer.memoryInGB << " GB of RAM in this model" << std::endl;

//Teacher methods
    auto teacher = Teacher();
    teacher.assignHomework("lesson 2");
    teacher.giveLecture();    
    std::cout << "money made: " << teacher.privateTutoring(50.00f) << std::endl;

    std::cout << "the students rate you: " << teacher.ratingByStudents << std::endl;

//ToneControl methods
    auto toneControl = ToneControl("boopy");  
    toneControl.setToneLevel(3.9f, 2.0f);
    toneControl.requireRepair();
    std::cout << "auto adjusted tone: "  << toneControl.autoAdjust() << std::endl;

    std::cout << "knob color is " << toneControl.knobColor << std::endl;

//ToneAlgorithm methods
    auto toneAlgorithm = ToneControl::ToneAlgorithm();
    toneAlgorithm.setUpperLimit(1.09f);
    toneAlgorithm.setToneColors(1, 2, 3);
    std::cout << "lower limit set to:" << toneAlgorithm.setLowerLimit(.02f) << std::endl;

    

//MusicMachine methods
    auto musicMachine = MusicMachine();
    musicMachine.powerOnComputer(computer);
    musicMachine.adjustToneControl(toneControl);
    musicMachine.powerOffComputer(computer);
    musicMachine.endComputing(computer);

//Classroom methods
    auto classroom = Classroom();
    classroom.hireTeacher(teacher);
    classroom.fireTeacher();
    classroom.chooseClassPresident("juanita");

    std::cout << "good to go!" << std::endl;
}
