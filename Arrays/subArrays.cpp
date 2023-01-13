#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subArrays(vector<int> data){
    int s = 0 ;
    int e = data.size();
    vector<vector<int>> res;
    vector<int> temp;
    for(s=0; s<e;s++){
        for(int i = s; i<e; i++){
            for(int j=s; j<=i;j++){
                temp.push_back(data[j]);
            }
            res.push_back(temp);
            temp.clear();
        }
    }
    return res;
}

int main(){
    vector<int> data = {1,2,3,4};
    vector<vector<int>> res = subArrays(data);
    for(int i=0; i<res.size();i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}