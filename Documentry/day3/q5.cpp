#include <iostream>
using namespace std;

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2; 
    }
    return result;
}

int minNonZeroProduct(int p) {
    const long long MOD = 1e9 + 7;
    long long maxVal = (1LL << p) - 1; 
    long long secondMaxVal = maxVal - 1; 
    long long count = (1LL << (p - 1)) - 1;
    
    // Compute result using modular arithmetic
    long long product = modExp(secondMaxVal, count, MOD);
    product = (product * maxVal) % MOD;
    
    return product;
}

int main() {
    int p = 3;
    cout << "Minimum Non-Zero Product: " << minNonZeroProduct(p) << endl;
    return 0;
}
