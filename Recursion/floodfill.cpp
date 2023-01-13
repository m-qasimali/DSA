#include<bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>> data,int sr,int sc, string ans,vector<vector<bool>> visited){
    if(sr < 0 || sc < 0 || sr == data.size() || sc == data[0].size() || data[sr][sc] == 1 || visited[sr][sc] == true){
        return;
    }
    if(sr == data.size()-1 && sc == data[0].size()-1){
        cout<<ans<<endl;
        return;
    }
    visited[sr][sc] = true;
    floodFill(data,sr-1,sc,ans+"t",visited); // top movement
    floodFill(data,sr,sc-1,ans+"l",visited); // left movement
    floodFill(data,sr+1,sc,ans+"d",visited); // down movement
    floodFill(data,sr, sc+1,ans+"r",visited); // right movement
    visited[sr][sc] = false;
}

int main(){
    vector<vector<int>> data = {{0,1,0,0,0,0,0},{0,1,0,1,1,1,0},{0,0,0,0,0,0,0},{1,0,1,1,0,1,1},{1,0,1,1,0,1,1},{1,0,0,0,0,0,0}};
    vector<vector<bool>> visited;
    for(int i=0; i<data.size(); i++){
        vector<bool> a;
        for(int j=0;j<data[i].size();j++){
            a.push_back(false);
        }
        visited.push_back(a);
        a.clear();
    }

    floodFill(data,0,0,"",visited);
}