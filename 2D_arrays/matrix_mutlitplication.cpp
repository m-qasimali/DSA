#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b){
    int r1  = a.size();
    int c1 = a[0].size();
    int r2 = b.size();
    int c2 = b[0].size();

    vector<vector<int>> c;
    vector<int> rows;
    int p = 0;
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2;j++){
            int temp = 0;
            for(int k=0;k<r2;k++){
                temp += (a[i][k]* b[k][j]);
            }
            rows.push_back(temp);
        }
        c.push_back(rows);
        rows.clear();
    }
    return c;
}

int main(){
    vector<vector<int>> a = {{10,0,0},{0,1,20}};
    vector<vector<int>> b = {{10,1,1,1},{20,1,1,1},{3,2,0,30}};
    vector<vector<int>> data =  multiply(a,b);
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}