#include<bits/stdc++.h>

using namespace std;

string compress(string data){
    string res = "";
    if(data == ""){
        return "data is empty!..";
    }
    res+=data.at(0);
    int count = 1;
    for(int i=1;i<data.length(); i++){

        if(res.back() == data.at(i)){
            count++;
        }else if(res.back() != data.at(i)){
            if(count>1){
                res+=to_string(count);
            }
            count = 1;
            res+=data.at(i);
        }

    }

    if(count>1){
        res+=to_string(count);
    }
    return res;
}

int main(){
    string data = "abbbccdd";
    cout<<compress(data);
}