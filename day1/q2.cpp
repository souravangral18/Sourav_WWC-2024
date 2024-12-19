#include <bits/stdc++.h>
using namespace std;


int main() {
    int n ;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n == 1) {
            cout << "is prime";
        }
        if(n % i == 0){
            count += 1;
        } 
    }
    
    if(count == 2) {
        cout << "is prime" ;
    } else if (count > 2) {
        cout << "is not prime" ;
    }
    return 0;
}