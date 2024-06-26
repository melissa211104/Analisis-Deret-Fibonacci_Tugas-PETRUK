#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

// Fungsi untuk menghitung Fibonacci secara rekursif dengan memoization
long long fibonacci_memo(int n, unordered_map<int, long long>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    memo[n] = fibonacci_memo(n-1, memo) + fibonacci_memo(n-2, memo);
    return memo[n];
}

// Fungsi pembungkus untuk memulai memoization
long long fibonacci_recursive_with_memo(int n) {
    unordered_map<int, long long> memo;
    return fibonacci_memo(n, memo);
}

// Fungsi untuk menghitung Fibonacci dengan dynamic programming
long long fibonacci_dp(int n) {
    if (n <= 1) {
        return n;
    }
    vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    vector<int> test_values = {10, 25, 30, 40, 50};

    cout << "Fibonacci Recursive with Memoization:\n";
    for (int n : test_values) {
        auto start = high_resolution_clock::now();
        long long result = fibonacci_recursive_with_memo(n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Fib(" << n << ") = " << result << "\n";
        cout << "Time taken: " << duration.count() << " microseconds\n";
    }

    cout << "\nFibonacci Dynamic Programming:\n";
    for (int n : test_values) {
        auto start = high_resolution_clock::now();
        long long result = fibonacci_dp(n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Fib(" << n << ") = " << result << "\n";
        cout << "Time taken: " << duration.count() << " microseconds\n";
    }

    return 0;
}
