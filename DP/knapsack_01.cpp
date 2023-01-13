#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wghts, vector<int> vals,int cap){
    int dp[wghts.size()+1][cap+1];
    int r = wghts.size()+1;
    int c = cap+1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i == 0 || j==0){
                dp[i][j] = 0;
            }
            else{
                if(j >= wghts[i-1]){
                    if(dp[i-1][j-wghts[i-1]] + vals[i-1] > dp[i-1][j]){
                        dp[i][j] = dp[i-1][j-wghts[i-1]] + vals[i-1];
                    }
                    else{
                        dp[i][j] = dp[i-1][j]; // if not bat
                    }
                }
                else{
                    dp[i][j] = dp[i-1][j]; // if not bat
                }
            }
        }
    }

    // for(int i=0; i<r;i++){
    //     for(int j=0; j<c;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[r-1][c-1];
}

int main(){
    vector<int> wgts = {2,5,1,3,4};
    vector<int> vals = {15,14,10,45,30};
    int capacity = 7;
    cout<<knapsack(wgts, vals, capacity);
}