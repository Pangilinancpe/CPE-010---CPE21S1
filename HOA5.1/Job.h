#ifndef HOA5_1_JOB_H
#define HOA5_1_JOB_H

#include <iostream>
#include <string>

class Job {
private:
    int id;
    std::string userName;
    int pages;

public:
    Job() : id(0), userName(""), pages(0) {}
    
    Job(int jobId, const std::string& name, int numPages)
        : id(jobId), userName(name), pages(numPages) {}

    int getId() const { return id; }
    std::string getUserName() const { return userName; }
    int getPages() const { return pages; }

    void display() const {
        std::cout << "[Job ID: " << id << " | User: " << userName << " | Pages: " << pages << "]";
    }
};

#endif //HOA5_1_JOB_H
