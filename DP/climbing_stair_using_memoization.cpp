#include<bits/stdc++.h>
using namespace std;

int countStairPaths(int n, vector<int> ques_bank){
    if(n<0){
        return 0 ;
    }
    else if(ques_bank[n] != -1){
        return ques_bank[n];
    }

    ques_bank[n] = countStairPaths(n-1,ques_bank) + countStairPaths(n-2,ques_bank) + countStairPaths(n-3,ques_bank);
    return ques_bank[n];
}

int countPath(int n){
    vector<int> ques_bank;
    for(int i=0;i<=n;i++){
        ques_bank.push_back(-1);
    }
    ques_bank[0] = 1;
    return countStairPaths(n, ques_bank);
}

int main(){
    
    cout<<countPath(6);
}