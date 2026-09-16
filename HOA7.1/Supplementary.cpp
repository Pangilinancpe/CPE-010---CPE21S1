#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include "SortingAlgo.h"

std::vector<int> generateRandomValues() {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<int> values(101);
    for (int& num : values) {
        num = rand() % 5 + 1;
    }
    return values;
}
void displayArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::map<int, std::string> candidates;
    candidates[1] = "Bo Dalton Capistrano";
    candidates[2] = "Cornelius Raymon Agustin";
    candidates[3] = "Deja Jayla Banaga";
    candidates[4] = "Lalla Brielle Yabut";
    candidates[5] = "Franklin Relano Castro";

    auto numbers = generateRandomValues();
    const int maxSize = 100;

    int originalArr[maxSize];
    int workArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        originalArr[i] = numbers[i];
    }

    std::cout << "UNSORTED ARRAY:\n";
    displayArr(originalArr, maxSize);
    
    std::copy(originalArr, originalArr + maxSize, workArr);
    insertionSort(workArr, maxSize);

    std::cout << "\nSORTED ARRAY:\n";
    displayArr(workArr, maxSize);

    std::map<int, int> voteCounts;
    for (int i = 0; i < maxSize; i++) {
        voteCounts[workArr[i]]++;
    }

    int maxVotes = -1;
    int winnerID = -1;

    std::cout << "\nELECTION RESULTS:\n";
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Candidate " << i << " -" << " " << candidates[i] << ": "
                  << voteCounts[i] << " votes\n";

        if (voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winnerID = i;
        }
    }

    std::cout << "\nWINNER: Candidate " << winnerID << " - " << candidates[winnerID] << " with " << maxVotes << " votes!\n";
    return 0;
}