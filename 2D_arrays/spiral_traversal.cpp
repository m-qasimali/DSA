#include<bits/stdc++.h>

using namespace std;

// void spiral(vector<vector<int>> data){
//     int a = 0;
//     int b = data.size()-1;
//     int c = data[0].size()-1;
//     int d = 0;

//     for(int i=a; i<=c;i++){
//         for(int j = a; j<=b;j++){
//             cout<<data[j][i]<<" ";
//         }
//         a++;

//         for(int k=a;k<=c;k++){
//             cout<<data[b][k]<<" ";
//         }
//         b--;

//         for(int l=b; l>=d;l--){
//             cout<<data[l][c]<<" ";
//         }
//         c--;

//         for(int m=c;m>=a;m--){
//             cout<<data[d][m]<<" ";
//         }
//         d++;
//     }
// }


void spiral(vector<vector<int>> data){
    int minr = 0;
    int minc = 0;
    int maxr = data.size()-1;
    int maxc = data[0].size()- 1;
    int totalElements = data.size() * data[0].size();
    int count = 0;

    while(count < totalElements){
        // left wall
        for(int i=minr,j=minc;i<=maxr;i++){
            cout<<data[i][j]<<" ";
            count++;
        }
        minc++;
        // down wall
        for(int i=minc,j=maxr;i<=maxc;i++){
            cout<<data[j][i]<<" ";
            count++;
        }
        maxr--;
        // Right wall
        for(int i=maxr,j=maxc;i>=minr;i--){
            cout<<data[i][j]<<" ";
            count++;
        }
        maxc--;
        // Up wall
        for(int i=maxc,j=minr;i>=minc;i--){
            cout<<data[j][i]<<" ";
            count++;
        }
        minr++;
    }
}

int main(){
    vector<vector<int>> data = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    spiral(data);
}