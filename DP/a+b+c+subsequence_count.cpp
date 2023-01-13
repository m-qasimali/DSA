#include<bits/stdc++.h>
using namespace std;

int countSubSequences(string data){
    int a = 0;
    int ab = 0;
    int abc = 0;
    
    for(int i=0; i<data.length(); i++){
        if(data.at(i) == 'a'){
            a = 2*a + 1;
        }
        else if(data.at(i) == 'b'){
            ab = 2*ab + a;
        }
        else if(data.at(i) == 'c'){
            abc = 2*abc + ab;
        }
    }
    return abc;
}

int main(){
    cout<<countSubSequences("abcabc");
}