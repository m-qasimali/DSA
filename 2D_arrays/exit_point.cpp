#include<bits/stdc++.h>

using namespace std;

void exitPoint(vector<vector<int>> data){
    int dir = 0; // e->0 , s->1 , w->2, n->3
    int row = 0;
    int col = 0;
    while(true){
        if(data[row][col] == 1){ // if 1 occur direction changes
            dir++;
        }
        dir = dir%4;
        
        if(dir == 0){ // east direction movement
            col++;
        }
        else if(dir == 1){ // south movement
            row++;
        }
        else if(dir == 2){ // west movement
            col--;
        }
        else if(dir == 3){ // north movement
            row--;
        }

        // exit points
        if(row < 0){ // out from upper wall
            row++;
            break;
        }
        else if(row >= data.size()){ // out from down wall
            row--;
            break;
        }
        else if(col < 0){ // out from left wall
            col++;
            break;
        }
        else if(col >= data[0].size()){ // out from right wall
            col--;
            break;
        }
    }

    cout<<"Exit Point -->  ("<<row<<", "<<col<<")\n";
}

int main(){
    vector<vector<int>> data = {{0,0,1,0},{1,0,0,1},{0,0,0,1},{1,0,1,0}};
    exitPoint(data);
}