#ifndef HOA5_1_PRINTER_H
#define HOA5_1_PRINTER_H

#include <iostream>
#include "Job.h"

// Fixed capacity for the printer buffer
const int MAX_QUEUE_SIZE = 10;

class Printer {
private:
    Job queue[MAX_QUEUE_SIZE]; // Array-based storage for jobs
    int front;
    int rear;
    int count;

public:
    // Initialize circular queue pointers
    Printer() : front(0), rear(-1), count(0) {}

    bool isFull() const {
        return count == MAX_QUEUE_SIZE;
    }

    bool isEmpty() const {
        return count == 0;
    }

    // Add a new job
    bool addJob(const Job& job) {
        if (isFull()) {
            std::cout << "[ERROR!] Queue Full! Rejected Job #" << job.getId()
                      << " from " << job.getUserName() << ".\n";
            return false;
        }

        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = job;
        count++;

        std::cout << "(ADDED) ";
        job.display();
        std::cout << " added to print queue.\n";
        return true;
    }

    // Process the next job
    bool processNextJob() {
        if (isEmpty()) {
            std::cout << "[NOTICE] No pending jobs to process.\n";
            return false;
        }

        Job currentJob = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        count--;

        std::cout << "[PRINTING] Currently processing: ";
        currentJob.display();
        std::cout << " ... Finished!\n";
        return true;
    }

    // Process all  jobs in order
    void processAllJobs() {
        std::cout << "\n--- Starting Batch Print Processing ---\n";
        if (isEmpty()) {
            std::cout << "No jobs in queue.\n";
            return;
        }
        while (!isEmpty()) {
            processNextJob();
        }
        std::cout << "--- All jobs completed. ---\n";
    }

    // Display teh current status
    void displayQueue() const {
        if (isEmpty()) {
            std::cout << "[STATUS] Printer queue is empty.\n";
            return;
        }

        std::cout << "(STATUS) Pending Jobs in Queue (" << count << "/" << MAX_QUEUE_SIZE << "):\n";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_QUEUE_SIZE;
            std::cout << "  " << i + 1 << ". ";
            queue[index].display();
            std::cout << "\n";
        }
    }
};

#endif //HOA5_1_PRINTER_H
