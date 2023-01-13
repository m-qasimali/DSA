#include<bits/stdc++.h>
using namespace std;


// int variableJumps(int n,int* jumps){
//     int dp[n+1];
//     dp[n] = 1;
//     for(int i=n-1;i>=0;i--){
//         int a = 0;
//         for(int j=1;j<=jumps[i] && i+j <= n;j++){
//             a += dp[i+j];
//         }
//         dp[i] = a;
//     }
//     return dp[0];
// }


// using recursion
// int variableJumps(int s,int e,int* jumps){
//     if(s == e){
//         return 1;
//     }
//     else if(s > e){
//         return 0;
//     }
//     int count = 0;
//     for(int i=1; i<=jumps[s];i++){
//         count += variableJumps(s+i, e, jumps);
//     }
//     return count;
// }



// using memoization
int variableJumps(int s,int e,int* jumps,vector<int> question_bank){
    if(s > e){
        return 0;
    }
    else if(question_bank[s] != -1){
        return question_bank[s];
    }
    int count = 0;
    for(int i=1; i<=jumps[s];i++){
        count += variableJumps(s+i, e, jumps,question_bank);
    }
    question_bank[s] = count;
    return question_bank[s];
}

int countPath(int s, int e, int* jumps){
    vector<int> ques_bank;
    for(int i=0;i<=e;i++){
        ques_bank.push_back(-1);
    }
    ques_bank[e] = 1;
    return variableJumps(s,e,jumps, ques_bank);
}

int main(){
    int jumps[] = {3,3,0,2,2,3,5};
    // cout<<variableJumps(0,7,jumps);


    // using memoization
    cout<<countPath(0,7,jumps);

}