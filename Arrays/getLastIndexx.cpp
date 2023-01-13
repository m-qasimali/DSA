#include<bits/stdc++.h>

using namespace std;

int getLast(vector<int> data,int target){
    int l = 0;
    int h = data.size()-1;
    int mid;
    int res = -1;
    while(l<=h){
        mid = l+(h-l)/2;
        if(target > data[mid]){
            l = mid+1;
        } 
        else if(target < data[mid]){
            h = mid-1;
        }
        else{
            res = mid;
            l = mid+1;
        }
    }
    return res;
}

int main(){
    vector<int> data = {1,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5};
    cout<<getLast(data,2);
}