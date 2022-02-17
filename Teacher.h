#pragma once
#include "LeakedObjectDetector.h"
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
