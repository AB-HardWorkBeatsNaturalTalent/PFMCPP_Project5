#pragma once
#include "LeakedObjectDetector.h"
#include "Teacher.h"
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
