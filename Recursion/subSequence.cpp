#include<bits/stdc++.h>

using namespace std;

vector<string> getss(string data){
    if(data.size() == 0){
        vector<string> res;
        res.push_back("-");
        return res;
    }

    string ch = data.substr(0,1);
    string sub = data.substr(1);
    vector<string> res = getss(sub);

    vector<string> myss;
    // add empty string at the front of subsequence
    for(int i=0;i<res.size(); i++){
        myss.push_back("-"+res[i]);
    }
    // add first char at the front of subsequence
    for(int i=0;i<res.size(); i++){
        myss.push_back(ch+res[i]);
    }
    return myss;

}

int main(){
    vector<string> res = getss("abc");
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}