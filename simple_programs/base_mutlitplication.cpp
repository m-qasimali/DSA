#include<bits/stdc++.h>
#include "baseAddition.h"
using namespace std;

int multiplication(int b, int div1, int div2){
    int digit1 = 0;
    int finalResult = 0;
    int digit2 = 0;
    int d = 0;
    int rem = 0;
    int q = 0;
    int p2 = 1;
    while(div2 != 0){
        digit2 = div2%10;
        div2 = div2/10;
        int p = 1;
        int res = 0;
        int temp = div1;
        while(temp != 0 || q!=0){
            digit1 = temp % 10;
            temp = temp / 10;
            d = (digit1 * digit2) + q;
            rem = d%b;
            q =d/b;
            res += p*rem;
            p *= 10;
        }
        res *= p2;
        p2 *= 10;
        finalResult = addition(b,finalResult,res);
    }
    return finalResult;
}

int main(){
    cout<<multiplication(8,234,76);
}