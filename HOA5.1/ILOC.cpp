#include <iostream>
#include "Job.h"
#include "Printer.h"

int main() {
    Printer officePrinter;

    std::cout << "--- OFFICE PRINTER ---\n";

    // First employees to send files in the printer
    std::cout << "Submitting the first files:\n";
    officePrinter.addJob(Job(1, "Bien", 5));
    officePrinter.addJob(Job(2, "Jhum", 12));
    officePrinter.addJob(Job(3, "Dave", 3));

    officePrinter.displayQueue();

    //Processing the upcoming first job
    std::cout << "\nProcessing first job:\n";
    officePrinter.processNextJob();

    //New submissions while printer is busy
    std::cout << "\nSubmitting New Files:\n";
    officePrinter.addJob(Job(4, "Allen", 8));
    officePrinter.addJob(Job(5, "Jenuel", 15));
    officePrinter.addJob(Job(6, "Jayne", 4));

    officePrinter.displayQueue();

    //Completing all pending files
    std::cout << "\nProcessing current queue:\n";
    officePrinter.processAllJobs();

    //Late upcoming files 
    std::cout << "\nSubmitting Late Files:\n";
    officePrinter.addJob(Job(7, "Mia", 10));
    officePrinter.addJob(Job(8, "Drens", 2));
    officePrinter.addJob(Job(9, "Renz", 7));
    officePrinter.addJob(Job(10, "Ali", 6));

    officePrinter.processAllJobs();

    return 0;
}