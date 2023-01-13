#include<bits/stdc++.h>

using namespace std;

void benjamin(int val){
    for(int i = 1;i*i<=val;i++){
        cout<<i*i<<endl;
    }
}

int main(){
    benjamin(10);
}