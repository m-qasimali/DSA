#include<bits/stdc++.h>

using namespace std;


vector<int> fillOnedFromShell(vector<vector<int>> data, int s){
    int minr = s-1;
    int minc = s-1;
    int maxr = data.size()-s;
    int maxc = data[0].size()-s;
    int totalElements = 2 * ((maxr - minr + 1) + (maxc-minc+1)) -4;
    vector<int> res;
    int count = 0;

    while(count < totalElements){
        // left wall
        for(int i=minr, j=minc; i<=maxr; i++){
            res.push_back(data[i][j]);
            count++;
        }
        minc++;

        // down wall
        for(int i=minc, j=maxr; i<=maxc;i++){
            res.push_back(data[j][i]);
            count++;
        }
        maxr--;

        // right wall
        for(int i=maxr,j=maxc; i>=minr; i--){
            res.push_back(data[i][j]);
            count++;
        }
        maxc--;

        // upper wall 
        for(int i=maxc,j=minr; i>=minc; i--){
            res.push_back(data[j][i]);
            count++;
        }
        minr++;
    }
    return res;

}


vector<vector<int>> fillShellFromOned(vector<vector<int>> data, vector<int> rotated, int s){
    int minr = s-1;
    int minc = s-1;
    int maxr = data.size()-s;
    int maxc = data[0].size()-s;
    int totalElements = 2 * ((maxr - minr + 1) + (maxc-minc+1)) -4;
    vector<int> res;
    int count = 0;

    while(count < totalElements){
        // left wall
        for(int i=minr, j=minc; i<=maxr; i++){
            data[i][j] = rotated[count];
            count++;
        }
        minc++;

        // down wall
        for(int i=minc, j=maxr; i<=maxc;i++){
            data[j][i] = rotated[count];
            count++;
        }
        maxr--;

        // right wall
        for(int i=maxr,j=maxc; i>=minr; i--){
            data[i][j] = rotated[count];
            count++;
        }
        maxc--;

        // upper wall 
        for(int i=maxc,j=minr; i>=minc; i--){
            data[j][i] = rotated[count];
            count++;
        }
        minr++;
    }
    return data;

}

vector<int> rotate(vector<int> data, int k){
    k = k % data.size();
    if(k<0){
        k = k + data.size();
    }
    // For anticlosewise rotation
    // reverse(data.begin(), data.end()-k);
    // reverse(data.end()-k,data.end());
    // reverse(data.begin(), data.end());

    // For Clockwise rotation
    reverse(data.begin(), data.begin()+k);
    reverse(data.begin()+k,data.end());
    reverse(data.begin(), data.end());
    return data;
}

void shellRotation(vector<vector<int>> data,int s, int r){
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[0].size();j++){
            cout<<data[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    vector<int> oned =  fillOnedFromShell(data, s);
    vector<int> rotated = rotate(oned,r);
    data = fillShellFromOned(data, rotated,s);
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[0].size();j++){
            cout<<data[i][j]<<"\t";
        }
        cout<<endl;
    }
} 


int main(){
    vector<vector<int>> data = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36}};
    shellRotation(data,2,3);
    // for(int i=0;i<data.size();i++){
    //     for(int j=0;j<data[0].size();j++){
    //         cout<<data[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
}