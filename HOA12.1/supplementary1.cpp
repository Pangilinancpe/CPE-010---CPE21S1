#include <iostream>
using namespace std;
int matrix[4][4] = {
    {4, 7, 1, 6},
    {6, 7, 3, 9},
    {3, 8, 1, 2},
    {7, 1, 7, 3}
};
int countPaths(int row, int col, int cost){
    if (row >= 4 || col >= 4 || cost < 0) return 0;
    cost -= matrix[row][col];
    if (row == 3 && col == 3){
        if (cost == 0) return 1;
        else return 0;
    }
    return countPaths(row + 1, col, cost) + countPaths(row, col + 1, cost);
}
int main()
{
    int cost = 25;
    cout << "Number of paths with cost 25: "
    << countPaths(0, 0, cost) << endl;
    return 0;
}