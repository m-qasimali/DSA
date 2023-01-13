#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> data){
    stack<int> s;
    vector<int> res;
    for(int i=0; i<data.size();i++){
        while(!s.empty() && data[s.top()] <= data[i]){
            s.pop();
        }
        if(s.empty()){
            res.push_back(i+1);
        }
        else if(data[s.top()] > data[i]){
            res.push_back(i-s.top());
        }

        s.push(i);
    }
    return res;
}

int main(){
    vector<int> data = {2,5,9,3,1,12,6,8,7};
    vector<int> res = stockSpan(data);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}