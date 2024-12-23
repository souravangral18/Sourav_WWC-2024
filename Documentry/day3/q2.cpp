#include <iostream>
using namespace std;

int lastRemaining(int n) {
    int head = 1;      
    int step = 1;      
    int remaining = n; 
    bool left = true;  
    
    while (remaining > 1) {
        if (left || remaining % 2 == 1) {
            head += step; 
        }
        step *= 2;        
        remaining /= 2;   
        left = !left;     
    }
    
    return head; // The last remaining number
}

int main() {
    int n = 9;
    cout << "Last remaining number: " << lastRemaining(n) << endl;
    return 0;
}
