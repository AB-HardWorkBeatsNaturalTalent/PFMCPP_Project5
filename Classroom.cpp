#include "Classroom.h"
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
