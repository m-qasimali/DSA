#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wghts, vector<int> vals,int cap){
    int dp[cap+1];
    int c = cap+1;
    for(int i=0; i<c;i++){
        dp[i] = 0;
    }
    for(int bagc=1; bagc<c; bagc++){
        int m = 0;
        for(int i=0;i<wghts.size();i++){
            if(bagc >= wghts[i]){
                m = max(dp[bagc-wghts[i]] + vals[i],m);
            }
        }
        dp[bagc] = m;
    }

    // for(int i=0; i<c;i++){
    //     cout<<dp[i]<<" ";
    // }
    return dp[c-1];
}

int main(){
    vector<int> wgts = {2,5,1,3,4};
    vector<int> vals = {15,14,10,45,30};
    int capacity = 7;
    cout<<knapsack(wgts, vals, capacity);
}