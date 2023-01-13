#include<bits/stdc++.h>

using namespace std;

// void saddlePoint(vector<vector<int>> data){
//     int ind1 = 0;
//     int ind2 = 0;
//     bool flag = false;
//     for(int i = 0; i<data.size(); i++){

//         ind1 = i;
//         ind2 = 0;
//         for(int j=0; j<data[i].size();j++){
//             if(data[i][j] < data[ind1][ind2]){
//                 ind1 = i;
//                 ind2 = j;
//             }
//         }

//         for(int j=0;j<data.size();j++){
//             if(data[ind1][ind2] < data[j][ind2]){
//                 break;
//             }
//             if(j == data.size()-1){
//                 flag = true;
//             }
//         }

//         if(flag){
//             break;
//         }
//     }
//     if(flag){
//         cout<<"saddle point is : "<<data[ind1][ind2]<<" exist at "<<"("<<ind1<<","<<ind2<<")";
//     }
//     else{
//         cout<<"Invalid input!..\n";
//     }
// }

void saddlePoint(vector<vector<int>> data){
    for(int i = 0; i<data.size(); i++){

        int svj = 0;
        for(int j=1; j<data[i].size();j++){
            if(data[i][j] < data[i][svj]){
                svj = j;
            }
        }

        bool flag = true;
        for(int j=0;j<data.size();j++){
            if(data[j][svj] > data[i][svj]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"saddle point is : "<<data[i][svj]<<" exist at "<<"("<<i<<","<<svj<<")";
            return;
        }
    }
    cout<<"Invalid input!..\n";
}

int main(){
    vector<vector<int>> data = {{1,2,3},{6,4,5},{9,9,9}};
    saddlePoint(data);
}