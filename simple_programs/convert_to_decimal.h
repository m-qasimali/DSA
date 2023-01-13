#include<bits/stdc++.h>
using namespace std;

int convertToDecimal(int val,int base){
    int digit = 0;
    int res = 0;
    int p = 1;
    while(val != 0){
        digit = val % 10;
        val = val / 10;
        res += digit*p;
        p *= base;
    }
    return res;
}