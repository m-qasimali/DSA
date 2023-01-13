#include<bits/stdc++.h>

using namespace std;

int decimalToAny(int val,int base){
    int rem = 0; 
    int res = 0;
    int i = 1;
    while(val >= 1 ){
        rem = val%base;
        val = val/base;
        res += rem * i;
        i = i*10;
    }
    return res;
}