#include<bits/stdc++.h>

using namespace std;

// void diagonal(vector<vector<int>> data){
//     for(int i=0; i<data[0].size();i++){
//         int a = 0;
//         int b = i;
//         for(int j=i;j<data[0].size();j++){
//             cout<<data[a][b]<<" ";
//             a++;
//             b++;
//         }
//     }
// }


void diagonal(vector<vector<int>> data){
    for(int g=0; g<data[0].size();g++){
        for(int i=0, j=g;j<data[0].size();i++,j++){
            cout<<data[i][j]<<" ";
        }
    }
}

int main(){
    vector<vector<int>> data = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    diagonal(data);
}