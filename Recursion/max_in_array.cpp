#include<bits/stdc++.h>
using namespace std;

int max(vector<int> arr, int ind){
    if(ind == arr.size()-1){
        return arr[ind];
    }
    int res = max(arr,ind+1);
    res = max(res,arr[ind]);
    return res;
}

int main(){
    vector<int> arr = {1,2,3,4,5,-2};
    cout<<max(arr,0);
}