#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 1) return 1;
    else return n * factorial(n-1);
}

int B(int n, int r){
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main() {
    cout << "5 C 2 = " << B(5, 2) << endl;
    cout << "8 C 5 = " << B(8, 5) << endl;
    return 0;
}