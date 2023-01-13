#include<bits/stdc++.h>
using namespace std;

// int factorial(int n){
//     if(n == 0){
//         return 1;
//     }
//     return n*factorial(n-1);
// }

int factorial(int n){
    if(n == 0){
        return 1;
    }
    // int fa = factorial(n-1);
    // int f = n * fa;
    int f = n * factorial(n-1);
    return f;
}

int main(){
    cout<<factorial(5);
}