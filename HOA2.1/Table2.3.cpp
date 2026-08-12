#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called." << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    void printDetails() {
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }
};

int main() {
    const size_t j = 5;
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    Student studentList[j];
    for (size_t i = 0; i < j; ++i) {
        studentList[i] = Student(namesList[i], ageList[i]);
    }
    Student studentCopyList[j] = {
        studentList[0], studentList[1], studentList[2], studentList[3], studentList[4]
    };
    for (size_t i = 0; i < j; ++i) {
        studentCopyList[i].printDetails();
    }

    return 0;
}