#include<bits/stdc++.h>
using namespace std;

void mazePath(int sr, int sc, int dr, int dc, string ans){
    if(sr == dr && sc == dc){
        cout<<ans<<endl;
        return;
    }

    for(int ms=1; ms<=dc-sc; ms++){
        mazePath(sr,sc+ms,dr,dc,ans+"h"+to_string(ms));
    }
    for(int ms=1; ms<=dr-sr; ms++){
        mazePath(sr+ms,sc,dr,dc,ans+"v"+to_string(ms));
    }
    for(int ms=1; ms<=dc-sc && ms<=dr-sr; ms++){
        mazePath(sr+ms,sc+ms,dr,dc,ans+"d"+to_string(ms));
    }
}

int main(){
    mazePath(1,1,5,5,"");
}