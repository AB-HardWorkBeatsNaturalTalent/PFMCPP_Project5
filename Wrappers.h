#pragma once
#include "MusicMachine.h"
#include "Computer.h"
#include "Teacher.h"
#include "ToneControl.h"
#include "Classroom.h"
/*#include "Teacher.h"
#include "ToneControl.h"
#include "MusicMachine.h"
#include "Classroom.h"*/

struct ComputerWrapper
{
    ComputerWrapper( Computer* ptr ) : ptrToComputer( ptr ) { }
    ~ComputerWrapper() 
    {
        delete ptrToComputer;
    }
    Computer* ptrToComputer = nullptr;
};

struct TeacherWrapper
{
    TeacherWrapper( Teacher* ptr ) : ptrToTeacher(ptr) { }
    ~TeacherWrapper()
    {
        delete ptrToTeacher;
    }
    Teacher* ptrToTeacher = nullptr;
};
struct ToneControlWrapper
{
    ToneControlWrapper( ToneControl* ptr ) : ptrToToneControl(ptr) { }
    ~ToneControlWrapper()
    {
        delete ptrToToneControl;
    }
    ToneControl* ptrToToneControl = nullptr;
};
struct ClassroomWrapper
{
    ClassroomWrapper( Classroom* ptr ) : ptrToClassroom(ptr) { }
    ~ClassroomWrapper()
    {
        delete ptrToClassroom;
    }
    Classroom* ptrToClassroom = nullptr;
};
struct MusicMachineWrapper
{
    MusicMachineWrapper( MusicMachine* ptr ) : ptrToMusicMachine(ptr) { }
    ~MusicMachineWrapper()
    {
        delete ptrToMusicMachine;
    }
    MusicMachine* ptrToMusicMachine = nullptr;
};


