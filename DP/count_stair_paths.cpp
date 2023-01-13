#include<bits/stdc++.h>
using namespace std;

int countStairPaths(int n){
    if(n == 0){
        return 1;
    }
    else if(n<0){
        return 0 ;
    }
    return countStairPaths(n-1)  + countStairPaths(n-2) + countStairPaths(n-3);
}


int main(){
    cout<<countStairPaths(6);
}