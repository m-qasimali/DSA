#include<bits/stdc++.h>
using namespace std;

void stairPath(int n, string path){
    if(n < 0){
        return;
    }
    else if(n == 0){
        cout<<path<<endl;
        return;
    } 
    stairPath(n-1,"1"+path);
    stairPath(n-2,"2"+path);
    stairPath(n-3,"3"+path);
    return;
}

int main(){
    stairPath(5,"");
}