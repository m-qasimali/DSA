#include<bits/stdc++.h>
using namespace std;

void mazePath(int sr,int sc,int dr,int dc,string ans){
    if(sr>dr || sc>dc){
        return;
    }
    if(sr == dr && sc == dc){
        cout<<ans<<endl;
        return;
    }
    mazePath(sr+1,sc,dr,dc,ans+"v");
    mazePath(sr,sc+1,dr,dc,ans+"h");
}

int main(){
    mazePath(1,1,3,3,"");
}