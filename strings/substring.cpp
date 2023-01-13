#include<bits/stdc++.h>
using namespace std;


void substring(string val){
    for(int i=0;i<val.length();i++){
        for(int j=1;j<=val.length()-i;j++){
            // cout<<i<<"--->"<<j<<endl;
            cout<<val.substr(i,j)<<endl;
        }
    }
}

int main(){
    substring("abc");
}