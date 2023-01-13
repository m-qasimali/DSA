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

vector<string> subSets(vector<int> data){
    vector<string> res;
    int size = pow(2,data.size());
    for(int i=0;i<size;i++){
        string temp = "";
        int k = i;
        for(int j=data.size()-1; j>=0; j--){
            int v = k%2;
            k = k/2;
            
            if(v == 0){
                temp = "- "+temp;
            }
            else{
                temp = to_string(data[j])+" " + temp;
            }
        }
        res.push_back(temp);
    }


    return res;
}

int main(){
    vector<int> data = {1,2,3};
    vector<string> res = subSets(data);
    for(int i=0; i<res.size();i++){
        cout<<res[i]<<endl;
    }
}