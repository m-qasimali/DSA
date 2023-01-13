#include<bits/stdc++.h>
using namespace std;

void printIncreasing(int n){
    if(n == 0){
        return;
    }
    printIncreasing(n-1);
    cout<<n<<endl;
}

int main(){
    printIncreasing(5);
}