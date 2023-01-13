#include<bits/stdc++.h>
#include "./convert_to_decimal.h"
#include "./decimal_to_any.h"
using namespace std;

int convert(int val, int b1, int b2){
    if(b1 == 10){
        return decimalToAny(val,b2);
    }
    else if(b2 == 10){
        return convertToDecimal(val,b1);
    }
    int res = convertToDecimal(val,b1);
    res = decimalToAny(res,b2);
    return res;
}

int main(){
    cout<<convert(172,8,2);
}