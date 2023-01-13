#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr, int ind){
    if(ind >= arr.size()){
        return;
    }
    cout<<arr[ind]<<" ";
    print(arr,ind+1);
} 

int main(){
    vector<int> a = {1,2,3,4,5};
    print(a,0);
}