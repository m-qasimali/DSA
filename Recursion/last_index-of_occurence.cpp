#include<bits/stdc++.h>

using namespace std;

int lastIndex(vector<int> arr, int ind, int target){
    if(ind == arr.size()){
        return -1;
    }
    int res = lastIndex(arr,ind+1,target);
    if(res == -1 && arr[ind] == target){
        return ind;
    }    
    return res;
}

int main(){
    vector<int> data = {1,8,9,0,4,8,5,12};
    cout<<lastIndex(data,0,8);
}