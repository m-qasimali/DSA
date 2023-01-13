#include<bits/stdc++.h>
using namespace std;

bool isItSafeForQueen(vector<vector<bool>> chess,int row,int col){
    // checking in column
    for(int i=row-1, j =col; i>=0;i--){
        if(chess[i][j]){
            return false;
        }
    }

    // checking in major diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0;i--,j--){
        if(chess[i][j]){
            return false;
        }
    }

    // checking in minor diagonal
    for(int i=row-1, j=col+1; i>=0 && j<chess.size();i--,j++){
        if(chess[i][j]){
            return false;
        }
    }

    return true;


}

void placeNQueens(vector<vector<bool>> chess, string qsf, int row){
    if(row == chess.size()){
        cout<<qsf<<endl;
        return;
    }
    for(int col = 0; col<chess.size();col++){
        if(isItSafeForQueen(chess,row,col)){
            chess[row][col] = true;
            placeNQueens(chess,qsf+to_string(row)+"-"+to_string(col)+",", row+1);
            chess[row][col] = false;
        }
    }
}

int main(){
    vector<vector<bool>> chess;
    for(int i=0;i<4;i++){
        vector<bool> a;
        for(int j = 0; j<4;j++){
            a.push_back(false);
        }
        chess.push_back(a);
        a.clear();
    }
    placeNQueens(chess,"", 0);
}