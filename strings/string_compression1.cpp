#include<bits/stdc++.h>

using namespace std;

string compress(string data){
    string res = "";
    res+=data.at(0);
    for(int i=1;i<data.length(); i++){

        if(res.back() != data.at(i)){
            res+= data.at(i);
        }
        
    }
    return res;
}

int main(){
    string data = "aaabbcddde";
    cout<<compress(data);
}