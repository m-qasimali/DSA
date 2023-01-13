#include<bits/stdc++.h>
using namespace std;

void findCeilAndFloor(vector<int> data,int d){
    int l = 0;
    int h = data.size()-1;
    int mid;
    int ceil = data[h];
    int floor = data[l];
    while(l<=h){
        mid = ((h-l)/2)+l;
        if(d>data[mid]){
            l = mid+1;
            floor = data[mid];
        }
        else if(d<data[mid]){
            h = mid-1;
            ceil = data[mid];
        }
        else{
            ceil = data[mid];
            floor = data[mid];
        }
    }
    cout<<"floor value : "<<floor<<endl;
    cout<<"ceil value : "<<ceil<<endl;
}

int main(){
    vector<int> data = {10,20,30,40,50,60,70,80,90,100};
    findCeilAndFloor(data,95);
}