#include<bits/stdc++.h>

using namespace std;

void PrimeFactors(int val){
    int i=2;
    for(int i=2; i<pow(val,0.5);i++){
        while(val%i == 0){
            val = val/i;
            cout<<i<<" ";
        }
    }
    if(val != 1){
        cout<<val<<" ";
    }
}

int main(){
    PrimeFactors(46);
}