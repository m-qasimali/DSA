#include<iostream>

using namespace std;

int GCD(int m,int n){
    int divisor = min(m,n);
    int dividend = max(m,n);

    while(divisor != 0){
        int temp = dividend % divisor;
        dividend = divisor;
        divisor = temp;
    }
    return dividend;
}

int main(){
    cout<<GCD(36,24);
}