#include<bits/stdc++.h>
using namespace std;

vector<string> getMazePath(int sr,int sc,int dr,int dc){
    if(sr==dr && sc==dc){
        vector<string> paths;
        paths.push_back("");
        return paths;
    }

    vector<string> paths;

    // horizontal movement
    
    for(int ms=1;ms<=dc-sc;ms++){
        vector<string> hpaths = getMazePath(sr,sc+ms,dr,dc);
        for(string hpath: hpaths){
            paths.push_back("h" + to_string(ms) + hpath);
        }
    }

    // vertical movement
    for(int ms=1;ms<=dr-sr;ms++){
        vector<string> vpaths = getMazePath(sr+ms,sc,dr,dc);
        for(string vpath: vpaths){
            paths.push_back("v"+to_string(ms)+vpath);
        }
    }

    // diagonal movement
    for(int ms=1;ms<=dr-sr && ms<dc-sc;ms++){
        vector<string> dpaths = getMazePath(sr+ms,sc+ms,dr,dc);
        for(string dpath: dpaths){
            paths.push_back("d"+to_string(ms)+dpath);
        }
    }

    return paths;
}

int main(){
    vector<string> res = getMazePath(1,1,3,3);
    for(string path : res){
        cout<<path<<endl;
    }
}