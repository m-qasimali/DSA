#include<bits/stdc++.h>
using namespace std;

int maxGoldPath(vector<vector<int>> data){
    int dp[data.size()][data[0].size()];
    for(int j=data[0].size()-1; j>=0; j--){
        for(int i=0; i<data.size(); i++){
            if(j == data[0].size()-1){
                dp[i][j] = data[i][j];
            }
            else if(i == 0){
                dp[i][j] = data[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            }
            else if(i == data.size()-1){
                dp[i][j] = data[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            }
            else{
                dp[i][j] = data[i][j] + max(max(dp[i-1][j+1], dp[i][j+1]), dp[i+1][j+1]);
            }
        }
    }
    for(int i=0; i<data.size(); i++){
        for(int j=0; j<data[i].size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int m = dp[0][0];
    for(int i = 1; i<data.size();i++){
        m = max(m, dp[i][0]);
    }
    return m;
}

int main(){
    vector<vector<int>> data = {
        {0,1,4,2,8,2},
        {4,3,6,5,0,4},
        {1,2,4,1,4,6},
        {2,0,7,3,2,2},
        {3,1,5,9,2,4},
        {2,7,0,8,5,1},
    };
    cout<<maxGoldPath(data);
}