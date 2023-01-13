#include<bits/stdc++.h>
using namespace std;

int factorial(int val){
    int res = 1;
    for(int i=val; i>1;i--){
        res *= i;
    }
    return res;
}



void permutation(string data){
    int len = data.size();
    int f = factorial(len);
    int j;
    for(int i=0;i<f;i++){
        j=len;
        string temp = data;
        string res = "";
        int t = i;
        for(j;j>=1;j--){
            res += temp.at(t%j);
            temp.erase(t%j,1);
            t = t/j;
        }
        cout<<res<<endl;
    }
}

// void permutation(string data,int r){
//     int n = data.size();
//     int f = factorial(n)/factorial(n-r);
//     int j;
//     for(int i=0;i<f;i++){
//         j=r;
//         string temp = data;
//         string res = "";
//         for(j;j>=1;j--){
//             res += temp.at(i%j);
//             temp.erase(i%j,1);
//         }
//         cout<<res<<endl;
//     }
// }

int main(){
    permutation("abc");
    // string data = "abc";
    // data.erase(0,1);
    // cout<<data;
}