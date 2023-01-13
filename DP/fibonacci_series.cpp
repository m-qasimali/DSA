#include<bits/stdc++.h>
using namespace std;

// -------------------  1   ---------------------
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+ fibonacci(n-2);
}

int main(){
    cout<<fibonacci(0);
}