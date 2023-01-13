#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins,int amt){
    int dp[amt+1];
    for(int i=1; i<=amt; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i=0; i<coins.size();i++){
        for(int j=coins[i]; j<=amt; j++){
            dp[j] += dp[j-coins[i]];
        }
    }
    return dp[amt];
}

int main(){
    vector<int> data = {2,3,5};
    int amt = 7;
    cout<<coinChange(data,amt);
}