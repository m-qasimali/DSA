#include<bits/stdc++.h>

using namespace std;


bool search(vector<vector<int>> data, int val){
    int rows = data.size();
    int cols = data[0].size();

    int i = 0; // right up corner
    int j = cols-1; // right up corner
    while(j>=0 && i<rows){
        if(data[i][j] == val){ // value found
            return true;
        }
        else if(val < data[i][j]){ // if target value less then move left 
            j--;
        }
        else if(val > data[i][j]){ // if target value greater then move down
            i++;
        }
    }
    return false; // value not found
}

int main(){
    vector<vector<int>> data = {{10,11,15,19},{22,26,29,31},{33,36,38,43}};
    cout<<search(data,-99);
}