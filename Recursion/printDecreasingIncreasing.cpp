#include<bits/stdc++.h>
using namespace std;

void printDecreasingIncreasing(int n){
    if(n == 0){
        return;
    }
    cout<<n<<endl;
    printDecreasingIncreasing(n-1);
    if(n==1){
        return;
    }
    cout<<n<<endl;
}

int main(){
    printDecreasingIncreasing(5);
}