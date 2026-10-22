#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> memo;
void memoAssign(int size, int value) {
    memo.assign(size, value);
}

int getMinSteps(int n) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];
    int r = 1 + getMinSteps(n - 1);
    if (n % 2 == 0) r = min(r, 1 + getMinSteps(n / 2));
    if (n % 3 == 0) r = min(r, 1 + getMinSteps(n / 3));
    memo[n] = r;
    return r;
}

int main() {
    int tests[] = {1, 4, 7, 10};
    for (int n : tests) {
        memoAssign(n + 1, -1);
        cout << "n: " << n << " -> minimum steps: " << getMinSteps(n) << endl;
    }
    return 0;
}