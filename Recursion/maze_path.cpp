#include<bits/stdc++.h>
using namespace std;

vector<string> getMazePath(int sr, int sc, int dr, int dc){
    if(sc == dc && sr == dr){
        vector<string> paths;
        paths.push_back("");
        return paths;
    }

    vector<string> vpaths;
    vector<string> hpaths;
    if(sr < dr){
        vpaths =  getMazePath(sr+1,sc,dr,dc);
    }
    if(sc < dc){
        hpaths = getMazePath(sr,sc+1,dr,dc);
    }

    vector<string> paths;
    for(string vpath: vpaths){
        paths.push_back("v"+vpath);
    }
    for(string hpath: hpaths){
        paths.push_back("h"+hpath);
    }
    return paths;
}

int main(){
    vector<string> res = getMazePath(1,1,3,3);
    for(string path : res){
        cout<<path<<endl;
    }
}