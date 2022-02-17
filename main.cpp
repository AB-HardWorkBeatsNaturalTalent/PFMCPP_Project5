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
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include <iostream>
#include "Classroom.h"
#include "Computer.h"
#include "Teacher.h"
#include "ToneControl.h"
#include "MusicMachine.h"

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
