#include<bits/stdc++.h>
using namespace std;

int minPath(vector<vector<int>> data){
    int dp[data.size()][data[0].size()];
    for(int i=data.size()-1; i>=0; i--){
        for(int j=data[i].size()-1; j>=0; j--){
            if(i==data.size()-1 && j==data[i].size()-1){
                dp[i][j] = data[i][j];
            }
            else if(j==data[i].size()-1){
                dp[i][j] = dp[i+1][j] + data[i][j];
            }
            else if(i == data.size()-1){
                dp[i][j] = dp[i][j+1] + data[i][j];
            }
            else{
                int m = min(dp[i][j+1],dp[i+1][j]);
                dp[i][j] = m + data[i][j];
            }
        }
    }
    // for(int i=0; i<data.size(); i++){
    //     for(int j=0; j<data[i].size(); j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[0][0];
}

int main(){
    vector<vector<int>> data = {
        {2,8,4,1,6,4,2},
        {6,0,9,5,3,8,5},
        {1,4,3,4,0,6,5},
        {6,4,7,2,4,6,1},
        {1,0,3,7,1,2,7},
        {1,5,3,2,3,0,9},
        {2,2,5,1,9,8,2}
    };
    cout<<minPath(data);
}