#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    // Default / Parameterized Constructor
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    // Copy Constructor
    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called." << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    // Display Attributes
    void printDetails() {
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }
};

int main() {
    const size_t j = 5;
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    Student studentList[j];
    Student* ptr = studentList;
    for (size_t i = 0; i < j; ++i) {
        *ptr = Student(namesList[i], ageList[i]);
        ptr++;
    }
    Student studentCopyList[j] = {
        studentList[0], studentList[1], studentList[2], studentList[3], studentList[4]
    };
    Student* copyPtr = studentCopyList;
    for (size_t i = 0; i < j; ++i) {
        copyPtr->printDetails();
        copyPtr++;
    }

    return 0;
}