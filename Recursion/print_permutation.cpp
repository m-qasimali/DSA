#include<bits/stdc++.h>
using namespace std;

void permutations(string ques,string ans){
    if(ques.length() == 0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<ques.length(); i++){
        permutations(ques.substr(0,i)+ques.substr(i+1),ans+ques.substr(i,1));
    }
}

int main(){
    permutations("abc","");
}