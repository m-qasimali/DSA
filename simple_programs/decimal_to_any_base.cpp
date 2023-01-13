#include<bits/stdc++.h>

using namespace std;

int power(int base, int exp){
    int res = 1;
    while(exp != 0){
        res *= base;
        exp--;
    }
    return res;
}

// int convert(int val,int base){
//     int rem = 0; 
//     int res = 0;
//     int i = 0;
//     while(val >= 1 ){
//         rem = val%base;
//         val = val/base;
//         res += rem * power(10,i);
//         i++;
//     }
//     return res;
// }

// OR

int convert(int val,int base){
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

int main(){
    cout<<convert(634,8);
}