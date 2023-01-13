#include<bits/stdc++.h>

using namespace std;

int base_addition(int b, int div1, int div2){
    int digit1 = 0;
    int digit2 = 0;
    int p = 1;
    int res = 0;
    int rem = 0;
    int q = 0;
    while( div1 != 0 || div2 != 0 || q != 0){
        digit1 = div1%10;
        div1 = div1/10;
        digit2 = div2%10;
        div2 = div2/10;
        rem = (digit1 + digit2 + q)%b;
        q = (digit1+digit2+q)/b;
        res += rem*p;
        p*=10;
    }
    return res;
}

int main(){
    cout<<base_addition(2,110,11000);
}