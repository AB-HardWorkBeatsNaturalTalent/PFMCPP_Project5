#pragma once
#include "LeakedObjectDetector.h"
#include "Teacher.h"
struct Classroom
{
    Teacher teacher;
    std::string classroomName;

    Classroom();
    ~Classroom();

    void hireTeacher(const Teacher& teach);// TODO: check if you can pass by const-ref
    void fireTeacher();
    void chooseClassPresident(std::string nameOfPresident);
    void printClassroomName();
    JUCE_LEAK_DETECTOR(Classroom)
};
