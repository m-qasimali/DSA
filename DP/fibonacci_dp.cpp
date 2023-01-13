#include<bits/stdc++.h>
using namespace std;

// -------------------  1   ---------------------

int fib(int n, vector<int> ques_bank){
    if(n == 0 || n == 1){
        return n;
    }
    else if(ques_bank[n] != 0){
        return ques_bank[n];
    }

    ques_bank[n] = fib(n-1,ques_bank) + fib(n-2,ques_bank);
    return ques_bank[n];
}

int fibonacci(int n){
    vector<int> ques_bank;
    for(int i=0;i<=n;i++){
        ques_bank.push_back(0);
    }
    return fib(n,ques_bank);
}

int main(){
    cout<<fibonacci(7);
}