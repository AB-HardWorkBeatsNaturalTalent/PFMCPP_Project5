/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>
/*
 copied UDT 1:Compputer
 */
struct Computer
{ 
    struct GraphicsAccelerator
    {
        //number of cuda cores
        int numberOfCUDACores = 1200;
        //model name 
        std::string modelName = "default GPU";
        //is gsync capable
        bool isGSyncCapable = true;
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
    };

    //1) number of processor cores (int)
    int numberOfProcessorCores  = 4;
    //2) memory In GB (int)
    int memoryInGB = 16;
    //3) graphics accelerator (std::string)
    GraphicsAccelerator graphicsAccelerator;
    //4) motherboard type (std::string)
    std::string motherboardType = "ATX";
    //5) audio interface name (std::string)
    std::string audioInterfaceName = "Apogee";

    Computer();
    ~Computer();
    //1) run multiple processes 
    void runMultipleProcesses();
    //2) run memtest
    void runMemtest();
    //3) update Graphics Driver
    //return true on connection success
    bool updateGraphicsDriver(GraphicsAccelerator graphicsAccelerator);
    //input the graphics accelerator to update drivers for
    //returns true if driver updated successfully;

};
Computer::~Computer()
{
    std::cout <<"Computer destructor" << std::endl;
}
Computer::GraphicsAccelerator::~GraphicsAccelerator()
{
    std::cout <<"GraphicsAccelerator destructor" << std::endl;
}
Computer::Computer()
{
    std::cout <<"Computer being constructed" << std::endl;
}
Computer::GraphicsAccelerator::GraphicsAccelerator()
{
    std::cout <<"GraphicsAccelerator being constructed "<< std::endl;
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
    std::cout << "memtest running" << std::endl;
}
bool Computer::updateGraphicsDriver(GraphicsAccelerator gA)
{
    std::string throwAway = gA.outputCUDAVersionAndCores();  
    return true;
}
/*
 copied UDT 2: Teacher
 */
struct Teacher
{

    //1) credential type (std::string)
    std::string credentialType = "no credential";
    //2) domain expertise (std::string)
    std::string domainExpertise= "philosophy";
    //3) number of classes taught (int)
    int numberOfClassesTaught = 6;
    //4) years of tenure (float)
    float yearsOfTenure = 1;
    //5) rating by students (char)
    char ratingByStudents  = 'A';

    Teacher();
    //1) give lecture
    void giveLecture();

    //2) private tutoring
    // returns the amount of money made from private tutoring
    float privateTutoring(float hourlyRate, int numberOfHours = 1); //input hourly rate and number of hours
    //3) assign homework
    void assignHomework(std::string homeworkAssignment);//input a string representation of the homework
};

Teacher::Teacher()
{
    std::cout << "Teacher being constructed" << std::endl;
}
void Teacher::giveLecture()
{

}
float Teacher::privateTutoring(float hourlyRate, int numberOfHours)
{
    return hourlyRate * numberOfHours;
}
void Teacher::assignHomework(std::string homeworkAssignment)
{
    std::cout << homeworkAssignment << " assigned to class" << std::endl;
}
/*
 copied UDT 3: ToneControl
 */
struct ToneControl
{
    struct ToneAlgorithm
    {
        //1 tone color 1
        int color1 = 10;
        //2 tone color 2
        int color2 = 12;
        //3 tone color 3
        int color3 = 14;
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

    ToneControl();
    ~ToneControl();
    //1) set tone level
    float setToneLevel(float inputLevel, float adjustment); //apply adjustment to the inputlevel
    //return the adjusted tone level

    //2) require repair
    bool requireRepair();//returns true if the tone control requires repair
    //3) auto adjust
    bool autoAdjust();//returns true if autoAdjust is turned on; else false 

};
ToneControl::~ToneControl()
{
    std::cout <<"ToneControl destructor" << std::endl;
}
ToneControl::ToneControl()
{
    std::cout << "ToneControl being constructed" << std::endl;
}
ToneControl::ToneAlgorithm::ToneAlgorithm()
{
    std::cout << "ToneAlgorithm constructing" << std::endl;
}
ToneControl::ToneAlgorithm::~ToneAlgorithm()
{
    std::cout << "ToneAlgorithm destructing" << std::endl;
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
/*
 new UDT 4: MusicMachine
 with 2 member functions
 */
struct MusicMachine
{
    Computer computer = Computer();
    ToneControl toneControl = ToneControl();

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
    this->endComputing(this->computer);
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

    Classroom();
    ~Classroom();

    void hireTeacher(Teacher teach);
    void fireTeacher();
    void chooseClassPresident(std::string nameOfPresident);
};

Classroom::Classroom()
{
    std::cout << " Constructing Classroom " << std::endl;
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

//Computer methods
    auto computer = Computer();
    std::cout << "updated graphics: " << computer.updateGraphicsDriver(computerGraphicsAccelerator) << std::endl;
    computer.runMemtest();
    computer.runMultipleProcesses();

//Teacher methods
    auto teacher = Teacher();
    teacher.assignHomework("lesson 2");
    teacher.giveLecture();    
    std::cout << "money made: " << teacher.privateTutoring(50.00f) << std::endl;

//ToneControl methods
    auto toneControl = ToneControl();  
    toneControl.setToneLevel(3.9f, 2.0f);
    toneControl.requireRepair();
    std::cout << "auto adjusted tone: "  << toneControl.autoAdjust() << std::endl;

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
