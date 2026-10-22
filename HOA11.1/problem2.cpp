#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;
long long calls = 0; // counts recursive calls (theoretical operation count)
// Algorithm rpower: O(n)
long long rpower(long long x, int n) {
    calls++;
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}
// Algorithm brpower: O(log n)
long long brpower(long long x, int n) {
    calls++;
    if (n == 0) return 1;
    if (n % 2 == 1) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}
int main() {
    // x = 1 so large exponents don't overflow; call counts and timing are unaffected.
    int sizes[] = {10, 100, 1000, 5000, 10000};
    const int REPS = 1000; // repeat to get measurable time
    cout << left << setw(8) << "n" << setw(16) << "rpower calls"
    << setw(16) << "brpower calls" << setw(18) << "rpower time(ns)"
    << "brpower time(ns)" << "\n";
    for (int n : sizes) {
        calls = 0; rpower(1, n); long long c1 = calls;
        calls = 0; brpower(1, n); long long c2 = calls;
        volatile long long sink;
        auto b1 = steady_clock::now();
        for (int r = 0; r < REPS; r++) sink = rpower(1, n);
        auto e1 = steady_clock::now();
        auto b2 = steady_clock::now();
        for (int r = 0; r < REPS; r++) sink = brpower(1, n);
        auto e2 = steady_clock::now();
        cout << left << setw(8) << n << setw(16) << c1 << setw(16) << c2
        << setw(18) << duration_cast<nanoseconds>(e1 - b1).count() / REPS
        << duration_cast<nanoseconds>(e2 - b2).count() / REPS << "\n";
    }
    return 0;
}