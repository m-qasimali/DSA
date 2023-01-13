#include<bits/stdc++.h>

using namespace std;

vector<int> reverseArray(vector<int> data){
    int i = 0;
    int j  = data.size()-1;
    while(i<j){
        swap(data[i],data[j]);
        i++;
        j--;
    }
    return data;
}