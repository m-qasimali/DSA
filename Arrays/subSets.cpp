#include<bits/stdc++.h>
using namespace std;

vector<int> getBinary(int n){
    vector<int> res;
    while(n!=0){
        res.insert(res.begin(),n%2);
        n = n/2;
    }
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;
    return res;
}

vector<vector<int>> subSets(vector<int> data){
    vector<vector<int>> res;
    int size = pow(2,data.size());
    for(int i=0;i<size;i++){
        vector<int> a = getBinary(i);
        vector<int> temp;
        int k=data.size()-1; 
        for(int x = a.size()-1; x>=0;x--){
            // cout<<a[x];
            if(a[x] != 0){
                temp.insert(temp.begin() ,data[k]);
            }
            k--;
        }
        res.push_back(temp);
        temp.clear();
        a.clear();
    }


    return res;
}

int main(){
    vector<int> data = {1,2,3};
    vector<vector<int>> res = subSets(data);
    for(int i=0; i<res.size();i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}