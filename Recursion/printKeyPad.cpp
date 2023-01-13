#include<bits/stdc++.h>
using namespace std;

vector<string> codes = {".,","abc","def","ghi","jkl","mnop","qrs","tu","vwx","yz"};
void keyPad(string ques, string ans){
    if(ques.length() == 0){
        cout<<ans<<endl;
        return;
    }
    int a = int(ques.at(0)-'0');
    string q = ques.substr(1);
    string val = codes[a];
    for(int i=0; i<val.length();i++){
        keyPad(q,ans+val.substr(i,1));
    }
}

int main(){
    keyPad("673","");
}