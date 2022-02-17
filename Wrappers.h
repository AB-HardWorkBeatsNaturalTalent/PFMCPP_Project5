#pragma once
#include "MusicMachine.h"
#include "Computer.h"
#include "Teacher.h"
#include "ToneControl.h"
#include "Classroom.h"
/*struct Computer;
struct Teacher;
struct ToneControl;
struct Classroom;
struct MusicMachine;*/

struct ComputerWrapper
{   
    ComputerWrapper( Computer* ptr );
    ~ComputerWrapper();
    Computer* ptrToComputer = nullptr;
};

struct TeacherWrapper
{
    TeacherWrapper( Teacher* ptr );
    ~TeacherWrapper();
    Teacher* ptrToTeacher = nullptr;
};
struct ToneControlWrapper
{
    ToneControlWrapper( ToneControl* ptr );
    ~ToneControlWrapper();
    ToneControl* ptrToToneControl = nullptr;
};
struct ClassroomWrapper
{
    ClassroomWrapper( Classroom* ptr );
    ~ClassroomWrapper();
    Classroom* ptrToClassroom = nullptr;
};
struct MusicMachineWrapper
{
    MusicMachineWrapper( MusicMachine* ptr );
    ~MusicMachineWrapper();
    MusicMachine* ptrToMusicMachine = nullptr;
};


