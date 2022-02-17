
#include "Teacher.h"

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
void Teacher::printStudentsRating()
{
    std::cout << "the students rate you: " << this->ratingByStudents << std::endl;
}
