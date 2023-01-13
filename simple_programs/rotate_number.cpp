#include<bits/stdc++.h>

using namespace std;

// int rotate(int val, int k){
//     int size = 0;
//     int temp = val;
//     while(temp != 0){ // getting the length of the number.
//         size++;
//         temp = temp/10;
//     }
//     k = k%size;
//     if(k<0){
//         k = k+size;
//     }
//     int divisor = 1;
//     while(k!=0){
//         divisor *= 10;
//         k--; 
//     }
//     int a = val%divisor;
//     int b = val/divisor;
//     temp = b;
//     while(temp!=0){
//         temp = temp/10;
//         a *= 10;
//     }
//     return a+b;
// }

int rotate(int val, int k){
    int size = 0;
    int temp = val;
    while(temp != 0){ // getting the length of the number.
        size++;
        temp = temp/10;
    }
    k = k%size;
    if(k<0){
        k = k+size;
    }
    int divisor = 1;
    int multiplier = 1;
    for(int i=1;i<=size;i++){
        if(i<=k){
            divisor *= 10;
        }
        else{
            multiplier *= 10;
        }
    }
    int a = val%divisor;
    int b = val/divisor;
    return (multiplier * a)+b;
}

int main(){
    cout<<rotate(162735,-2);
}