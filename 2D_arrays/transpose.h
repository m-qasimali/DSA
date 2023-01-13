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