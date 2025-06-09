#include <iostream>
#include <chrono>
#include <iomanip>

// Function to perform the calculations
double calculate(int iterations, int param1, int param2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        int j = i * param1 - param2;
        result -= (1.0 / j);
        j = i * param1 + param2;
        result += (1.0 / j);
    }
    return result;
}

int main() {
    // Start timing
    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform calculations
    double result = calculate(100000000, 4, 1) * 4;

    // End timing
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate execution time
    std::chrono::duration<double> elapsed = end_time - start_time;

    // Output results
    std::cout << "Result: " << std::setprecision(12) << std::fixed << result << std::endl;
    std::cout << "Execution Time: " << std::setprecision(6) << std::fixed << elapsed.count() << " seconds" << std::endl;

    return 0;
}
