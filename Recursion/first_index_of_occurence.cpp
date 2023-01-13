#include<bits/stdc++.h>

using namespace std;


// input: {2,3,4,8,9,4,8} , 8
// output: 3

// int find(vector<int> arr, int ind, int target){
//     if(ind == arr.size()){
//         return -1;
//     }
//     int res = find(arr,ind+1,target);
//     if(arr[ind] == target){
//         return ind;
//     }    
//     return res;
// }


int find(vector<int> arr, int ind, int target){ // Expectations
    if(ind == arr.size()){ // base case ind at arr.size()
        return -1;
    }

    if(arr[ind] == target){ // check first index of target value
        return ind;
    }   

    int res = find(arr,ind+1,target); // faith
    return res;
}

int main(){
    vector<int> arr = {2,3,4,8,9,4,8};
    cout<<find(arr,0,8);
}