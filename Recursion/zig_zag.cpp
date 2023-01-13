#include<bits/stdc++.h>
using namespace std;
// input: 1
// output: 1 1 1  
// input: 2
// output: 2 1 1 1 2 1 1 1 2 
// input: 3
// output: 3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3 

void zigZag(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" "; //pre
    zigZag(n-1); //left call
    cout<<n<<" "; // inner
    zigZag(n-1); // right call
    cout<<n<<" "; // post
}

int main(){
    zigZag(2);
}