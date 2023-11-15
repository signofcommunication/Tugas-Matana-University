#include <iostream>
using namespace std;

int main() {
    const int arraySize = 10;
    int numbers[arraySize];

    // Input phase
    cout << "Enter 10 integer values:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Initialize min and max with the first element
    int min = numbers[0];
    int max = numbers[0];
    int sum = numbers[0];

    // Find min, max, and calculate sum
    for (int i = 1; i < arraySize; ++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
        sum += numbers[i];
    }

    // Calculate average
    double average = static_cast<double>(sum) / arraySize;

    // Output phase
    cout << "\nResults:" << endl;
    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;
    cout << "Average value: " << average << endl;

    return 0;
}

