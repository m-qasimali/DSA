#include<bits/stdc++.h>

using namespace std;

bool isPrime(int val){
    int count = 0;
    for(int i=2; i<=pow(val,0.5);i++){
        if(val % i == 0){
            count++;
            break;
        }
    }
    if(count == 0){
        return true;
    }
    return false;
}

int main(){
    cout<<isPrime(10);
}