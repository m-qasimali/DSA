#include<bits/stdc++.h>
using namespace std;

bool isRigtTriangle(int a,int b, int c){
    int H = max(a,b);
    int B = min(a,b);
    int P = min(H,c);
    H = max(H,c);
    return pow(H,2) == pow(B,2) + pow(P,2);
}

int main(){
    cout<<isRigtTriangle(1,2,3);
}