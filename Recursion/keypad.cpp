#include<bits/stdc++.h>

using namespace std;

vector<string> keyPad(vector<string> data, string key){
    if(key.size() == 0){
        vector<string> res;
        res.push_back("");
        return res;
    }

    int ch = int(key.at(0) - '0');
    string sub = key.substr(1);
    vector<string> res1 = keyPad(data,sub);
    vector<string> res2;
    for(int i=0;i<res1.size();i++){
        for(int j=0;j<data[ch].size();j++){
            res2.push_back(data[ch].at(j)+res1[i]);
        }
    }
    return res2;
}

int main(){
    vector<string> data = {".,","abc","def","ghi","jkl","mnop","qrs","tu","vwx","yz"};
    vector<string> res = keyPad(data,"573");
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}