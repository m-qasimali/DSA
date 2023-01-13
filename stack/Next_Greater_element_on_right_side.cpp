#include<bits/stdc++.h>
using namespace std;

// vector<int> NGEGS(vector<int> data){
//     stack<int> s;
//     vector<int> res;
//     for(int i=data.size()-1; i>=0; i--){
//         while(s.size()>0 && data[i] >= s.top()){
//             s.pop();
//         }
//         if(s.empty()){
//             res.insert(res.begin(),-1);
//         }
//         else{
//             res.insert(res.begin(),s.top());
//         }
//         s.push(data[i]);
//     }
//     return res;
// }

// left to right traversal
vector<int> NGEGS(vector<int> data){
    stack<int> s;
    vector<int> res;
    for(int i = 0; i<data.size(); i++){
        res.push_back(0);
    }
    for(int i=0; i<data.size(); i++){
        while(!s.empty() && data[s.top()]<data[i]){
            res[s.top()] = data[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        res[s.top()] = -1;
        s.pop();
    }
    return res;
}

int main(){
    vector<int> data = {2,5,9,3,1,12,6,8,7};
    vector<int> res = NGEGS(data);
    for(int i=0; i<data.size(); i++){
        cout<<res[i]<<" ";
    }
}