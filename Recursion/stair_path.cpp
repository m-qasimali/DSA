#include<bits/stdc++.h>

using namespace std;

vector<string> getPaths(int n){
    if(n==0){
        vector<string> a;
        a.push_back("");
        return a;
    }
    else if(n < 0){
        vector<string> a;
        return a;
    }

    vector<string> paths1 = getPaths(n-1);
    vector<string> paths2 = getPaths(n-2);
    vector<string> paths3 = getPaths(n-3);
    vector<string> paths;

    for(string path : paths1){
        paths.push_back("1"+path);
    }
    for(string path : paths2){
        paths.push_back("2"+path);
    }
    for(string path : paths3){
        paths.push_back("3"+path);
    }
    return paths;
}

int main(){
    vector<string> paths = getPaths(4);
    for(int i=0;i<paths.size();i++){
        cout<<paths[i]<<endl;
    }
}