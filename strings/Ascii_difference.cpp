#include<bits/stdc++.h>
using namespace std;

// string toggle(string data){
//     for(int i=0;i<data.size();i++){
//         if(data.at(i)<123 && data.at(i)>96){
//             data.at(i) =  data.at(i)-32;
//         }
//         else if(data.at(i)>64 && data.at(i)<91){
//             data.at(i) =  data.at(i)+32;
//         }
//     }
//     return data;
// }

string asciiDifference(string data){
    string res = "";
    res += data.at(0);
    for(int i=1;i<data.size();i++){
        res += to_string(data.at(i) - res.back());
        res += data.at(i);
    }
    return res;
}


int main(){
    string data = "acezz";
    cout<<asciiDifference(data);
}