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

string toggle(string data){
    for(int i=0;i<data.size();i++){
        if(data.at(i)<='z' && data.at(i)>='a'){
            data.at(i) =  data.at(i)-32;
        }
        else if(data.at(i)>='A' && data.at(i)<='Z'){
            data.at(i) =  data.at(i)+32;
        }
    }
    return data;
}


int main(){
    string data = "aPPle";
    cout<<toggle(data);
}