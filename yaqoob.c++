#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

long long calculateIterativeFactorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long calculateRecursiveFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * calculateRecursiveFactorial(n - 1);
}

template<typename Func>
double measureExecutionTime(Func func, int n) {
    auto start = chrono::high_resolution_clock::now();
    func(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

int main() {
    int n;
    cout << "Enter a number to calculate factorial: ";
    cin >> n;

    double iterativeTime = measureExecutionTime(calculateIterativeFactorial, n);
    cout << fixed << setprecision(6) << "Iterative factorial time: " << iterativeTime * 1000000 << " microseconds" << endl;

    double recursiveTime = measureExecutionTime(calculateRecursiveFactorial, n);
    cout << fixed << setprecision(6) << "Recursive factorial time: " << recursiveTime * 1000000 << " microseconds" << endl;

    return 0;
}

