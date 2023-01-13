#include<bits/stdc++.h>
using namespace std;

// void wave(vector<vector<int>> data){
//     int flag = true;
//     int k = -1;
//     for(int i=0; i<data.size();i++){
//         for(int j=0;j<data[0].size();j++){
//             if(flag){
//                 k++;
//             }
//             cout<<data[k][i]<<" ";
//             if(!flag){
//                 k--;
//             }
//         }
//         if(flag){
//             flag = false;
//         }
//         else{
//             flag = true;
//         }
//     }
// }

void wave(vector<vector<int>> data){
    for(int i=0; i<data.size();i++){
        if(i%2 == 0){
            for(int j=0; j<data[0].size();j++){
                cout<<data[j][i]<<" ";
            }
        }
        else{
            for(int j=data[0].size()-1; j>=0;j--){
                cout<<data[j][i]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    wave(a);
}