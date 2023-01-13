#include<bits/stdc++.h>
using namespace std;

int targetSum(vector<int> data,int target){
    int r = data.size()+1;
    int c = target+1;
    bool dp[r][c];
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else{
                if(dp[i-1][j]){
                    dp[i][j] = true;
                }
                else{
                    int val = data[i-1];
                    if(j >= val){
                        if(dp[i-1][j-val]){
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j] = false;
                        }
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
    }

    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[r-1][c-1];
}

int main(){
    vector<int> data = {4,2,7,1,3};
    cout<<targetSum(data,10);
}