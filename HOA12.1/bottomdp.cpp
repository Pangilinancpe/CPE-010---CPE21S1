#include <iostream>
#include <algorithm>
using namespace std;
int getMinSteps(int n)
{
    int dp[n + 1], i;
    dp[1] = 0;
    for (i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) dp[i] = min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
    return dp[n];
}
int main()
{
    int numbers[] = {1, 3, 4, 6};
    for (int i = 0; i < 4; i++)
    {
        cout << "n: " << numbers[i] << " -> minimum steps: "
        << getMinSteps(numbers[i]) << endl;
    }
    return 0;
}