#include<bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> data){

    // transpose vector
    for(int i=0;i<data.size(); i++){
        for(int j=i; j<data[0].size(); j++){
            swap(data[i][j], data[j][i]);
        }
    }

    for(int a=0; a<data.size();a++){
        int i = 0;
        int j  = data[a].size()-1;
        while(i<j){
            swap(data[a][i],data[a][j]);
            i++;
            j--;
        }
    }

    for(int i =0;i<data.size();i++){
        for(int j=0;j<data[0].size(); j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    vector<vector<int>> data = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(data);
}