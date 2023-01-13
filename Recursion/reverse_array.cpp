#include<bits/stdc++.h>
using namespace std;

void print_reverse(vector<int> arr, int ind){
    if(arr.size() == ind){
        return;
    }
    print_reverse(arr,ind+1);
    cout<<arr[ind]<<" ";
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    print_reverse(arr,0);
}