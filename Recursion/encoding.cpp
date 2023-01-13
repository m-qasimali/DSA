#include<bits/stdc++.h>
using namespace std;

void encoding(string ques, string ans){
    if(ques.length() == 0){
        cout<<ans<<endl;
        return;
    }
    else if(ques.length() == 1){
        char ch = ques.at(0);
        if(ch == '0'){
            return;
        }
        else{
            char code = char('a' + int(ch - '0')-1);
            ans+=code;
            cout<<ans<<endl;
        }
    }
    else{
        char ch1 = ques.at(0);
        string roq = ques.substr(1);

        if(ch1 == '0'){
            return;
        }
        else{
            char code = char('a' + int(ch1 - '0')-1);
            encoding(roq,ans+code);
        }

        string ch12 = ques.substr(0,2);
        string ro1 = ques.substr(2);

        int ch12v = stoi(ch12);
        if(ch12v <= 26){
            char code = char('a' + ch12v -1);
            encoding(ro1,ans+code);
        }
    }
}

int main(){
    encoding("1256954","");
}