#include<bits/stdc++.h>
using namespace std;

// // O(n)
// int power(int n,int r){
//     if(r == 0){
//         return 1;
//     }
//     return n*power(n,r-1); 
// }

// O(log(n))
int power(int x,int n){
    if(n == 0){
        return 1;
    }
    int xpnby2 = power(x,n/2);
    int a = xpnby2 * xpnby2;
    if(n%2 == 1){
        a *= x;
    }
    return a; 
}

int main(){
    cout<<power(4, 9);
}