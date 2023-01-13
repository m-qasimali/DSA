#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins,int amt){
    int dp[amt+1];
    for(int i=1; i<=amt; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int amount=1; amount<=amt; amount++){
        for(int coin:coins){
            if(coin <= amount){
                dp[amount] += dp[amount-coin];
            }
        }
    }
    return dp[amt];
}

int main(){
    vector<int> data = {2,3,5,6};
    int amt = 20;
    cout<<coinChange(data,amt);
}