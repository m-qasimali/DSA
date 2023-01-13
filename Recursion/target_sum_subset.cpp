#include<bits/stdc++.h>
using namespace std;

// void targetSum(vector<int> ques, vector<int> ans){
//     if(ques.size() == 0){
//         int sum = 0;
//         for(int i=0;i<ans.size();i++){
//             sum+=ans[i];
//         }
//         if(sum == 60){
//             for(int i=0;i<ans.size();i++){
//                 cout<<ans[i]<<" ";
//             }
//             cout<<endl;
//         }
//         return;
//     }
//     int a1 = ques[0];
//     vector<int> q1;
//     for(int i=1;i<ques.size();i++){
//         q1.push_back(ques[i]);
//     }
//     targetSum(q1,ans);
//     ans.push_back(a1);
//     targetSum(q1,ans);
// }

void printTargetSumSubsets(vector<int> data, int idx,string set, int sos,int tar){
    if(sos == tar){
        cout<<set<<endl;
        return;
    }
    if(idx == data.size()){
        return;
    }

    int ans = data[idx];
    printTargetSumSubsets(data,idx+1,set,sos+0,tar);
    printTargetSumSubsets(data,idx+1,set+" "+to_string(ans),sos+ans,tar);


}

int main(){
    vector<int> data = {10,20,30,40,50,6};
    vector<int> ans;
    // targetSum(data,ans);

    printTargetSumSubsets(data,0,"",0,60);
}