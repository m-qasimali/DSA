#include<bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> chess){
    int r = chess.size();
    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printKnightsTour(vector<vector<int>> chess, int r, int c ,int move){
    //if we reach out of the baord or we reach an already visited block
    if (r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] > 0)
    {
      return;
    }
    //if we have reached the last move
    else if (move == chess.size() * chess.size())
    {
      chess[r][c] = move;
      displayBoard(chess);
      chess[r][c] = 0;
      return;
    }

    //Code based on High Level Thinking

    chess[r][c] = move; //Fill the chess[r][c] will the move number

    //Apply recursive calls on the basis of faith
    printKnightsTour(chess, r - 2, c + 1, move + 1);
    printKnightsTour(chess, r - 1, c + 2, move + 1);
    printKnightsTour(chess, r + 1, c + 2, move + 1);
    printKnightsTour(chess, r + 2, c + 1, move + 1);
    printKnightsTour(chess, r + 2, c - 1, move + 1);
    printKnightsTour(chess, r + 1, c - 2, move + 1);
    printKnightsTour(chess, r - 1, c - 2, move + 1);
    printKnightsTour(chess, r - 2, c - 1, move + 1);

    //Follow the Backtracking principle
    chess[r][c] = 0;
}

int main(){
    vector<vector<int>> chess;
    int n = 5;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            temp.push_back(0);
        }
        chess.push_back(temp);
        temp.clear();
    }
    printKnightsTour(chess,2,0,1);
}