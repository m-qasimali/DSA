#include<bits/stdc++.h>
using namespace std;


int totalWays(string data){
    int dp[data.length()];
    dp[0] = 1;
    for(int i=1; i<data.length(); i++){
        if(data.at(i-1) == '0' && data.at(i) == '0'){
            dp[i] = 0;
        }
        else if(data.at(i-1) == '0' && data.at(i) != '0'){
            dp[i] = dp[i-1];
        }
        else if(data.at(i-1) != '0' && data.at(i) == '0'){
            if(data.at(i-1) == '1' || data.at(i-1) == '2'){
                dp[i] = (i>=2)? dp[i-2] : 1;
            }
            else{
                dp[i] = 0;
            }
        }
        else{
            if(stoi(data.substr(i-1,2)) <=26){
                int a = (i>=2)?dp[i-2]:1;
                dp[i] = dp[i-1] + a;
            }
            else{
                dp[i] = dp[i-2];
            }
        }
    }
    for(int i=0; i<data.length();i++){
        cout<<dp[i]<<" ";
    }
    return dp[data.length()-1];
}


int main(){
    cout<<totalWays("231011");
}