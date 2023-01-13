#include<iostream>

using namespace std;

int LCM(int m,int n){
    int divisor = min(m,n);
    int dividend = max(m,n);

    while(divisor != 0){
        int temp = dividend % divisor;
        dividend = divisor;
        divisor = temp;
    }
    int gcd = dividend;
    int lcm = (m*n)/gcd;
    return lcm;
}

int main(){
    cout<<LCM(36,24);
}