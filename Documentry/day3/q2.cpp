#include <iostream>
using namespace std;

int lastRemaining(int n) {
    int head = 1;       // First number in the remaining range
    int step = 1;       // Step size between numbers
    int remaining = n;  // Number of elements remaining
    bool left = true;   // Direction of elimination
    
    while (remaining > 1) {
        if (left || remaining % 2 == 1) {
            head += step; // Update head if left-to-right or odd remaining
        }
        step *= 2;          // Double the step size
        remaining /= 2;     // Halve the remaining numbers
        left = !left;       // Toggle direction
    }
    
    return head; // The last remaining number
}

int main() {
    int n = 9;
    cout << "Last remaining number: " << lastRemaining(n) << endl;
    return 0;
}
