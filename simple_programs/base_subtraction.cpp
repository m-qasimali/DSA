#include<bits/stdc++.h>

using namespace std;

int base_subtraction(int b, int div1, int div2){
    int digit1 = 0;
    int digit2 = 0;
    int p = 1;
    int res = 0;
    int c = 0;
    while( div1 != 0 || div2 != 0){
        digit1 = div1%10;
        div1 = div1/10;
        digit2 = div2%10;
        div2 = div2/10;
        digit1 += c;
        c = 0;
        if(digit1 < digit2){
            c = -1;
            digit1 += b;
        }
        res += p*((digit1 - digit2)%b);
        p*=10;
    }
    return res;
}

int main(){
    cout<<base_subtraction(8,1212,256);
}