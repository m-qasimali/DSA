#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>> data){
    for(int i=0;i<data.size(); i++){
        for(int j=i; j<data[0].size(); j++){
            swap(data[i][j], data[j][i]);
        }
    }
    return data;
}

int main(){
    vector<vector<int>> data = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> res =  transpose(data);
    for(int i=0;i<data.size(); i++){
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}