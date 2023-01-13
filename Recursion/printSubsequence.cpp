#include<bits/stdc++.h>
using namespace std;

void printSubseq(string ques, string ans){
    if(ques.length() == 0){
        cout<<ans<<endl;
        return;
    }
    string a = ques.substr(0,1);
    string q = ques.substr(1);
    printSubseq(q,ans+a);
    printSubseq(q,ans+"");
}

int main(){
    printSubseq("abc","");
}