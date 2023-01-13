#include<bits/stdc++.h>

using namespace std;

bool isPrime(int val){
    int count = 0;
    for(int i=2;i*i <= val;i++){
        if(val%i == 0){
            return false;
        }
    }
    return true;
}

// vector<int> removePrime(vector<int> data){
//     for(int i=0;i<data.size();i++){
//         if(isPrime(data[i])){
//             data.erase(data.begin()+i);
//             i--;
//         }
//     }
//     return data;
// }

// best techniue is to traverse the vector reversely G-->S
vector<int> removePrime(vector<int> data){
    for(int i=data.size()-1;i>=0;i--){
        if(isPrime(data[i])){
            data.erase(data.begin()+i);
        }
    }
    return data;
}

int main(){
    vector<int> data = {3,12,13,17,10,16,19,29,23,24};
    data = removePrime(data);
    for(int i=0;i<data.size();i++){
        cout<<data[i]<<" ";
    }
}