#include<bits/stdc++.h>
using namespace std;

vector<int> NSELS(vector<int> data){
    vector<int> res;
    stack<int> s;
    for(int i=0; i<data.size();i++){
        while(!s.empty() && data[s.top()]>=data[i]){
            s.pop();
        }
        if(s.empty()){
            res.push_back(-1);
        }
        else if(data[s.top()]<data[i]){
            res.push_back(s.top());
        }
        s.push(i);
    }
    return res;
}


vector<int> NSERS(vector<int> data){
    vector<int> res;
    stack<int> s;
    for(int i=data.size()-1; i>=0;i--){
        while(!s.empty() && data[s.top()]>=data[i]){
            s.pop();
        }
        if(s.empty()){
            res.insert(res.begin(),data.size());
        }
        else if(data[s.top()]<data[i]){
            res.insert(res.begin(),s.top());
        }
        s.push(i);
    }
    return res;
}

int largestArea(vector<int> data){
    vector<int> lse = NSELS(data);
    vector<int> rse = NSERS(data);
    int maxArea = INT_MIN;
    for(int i=0; i<data.size();i++){
        int width = rse[i]-lse[i] - 1;
        int area = width*data[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}


int main(){
    vector<int> data = {6,2,5,4,5,1,6};
    cout<<largestArea(data);
}