#include "Wrappers.h"

ComputerWrapper::ComputerWrapper( Computer* ptr ) : ptrToComputer( ptr ){}
ComputerWrapper::~ComputerWrapper() 
{
    delete ptrToComputer;
}

TeacherWrapper::TeacherWrapper( Teacher* ptr ) : ptrToTeacher(ptr) {}
TeacherWrapper::~TeacherWrapper()
{
    delete ptrToTeacher;
}

ToneControlWrapper::ToneControlWrapper( ToneControl* ptr ) : ptrToToneControl(ptr) {}
ToneControlWrapper::~ToneControlWrapper()
{
    delete ptrToToneControl;
}

ClassroomWrapper::ClassroomWrapper( Classroom* ptr ) : ptrToClassroom(ptr) {}
ClassroomWrapper::~ClassroomWrapper()
{
    delete ptrToClassroom;
}

MusicMachineWrapper::MusicMachineWrapper( MusicMachine* ptr ) : ptrToMusicMachine(ptr) {}
MusicMachineWrapper::~MusicMachineWrapper()
{
    delete ptrToMusicMachine;
}
