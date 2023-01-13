#include<bits/stdc++.h>
using namespace std;

void palindromeSubString(string val){
    for(int i=0; i<val.length();i++){
        for(int j=1;j<=val.length()-i;j++){
            string sub = val.substr(i,j);
            int a = 0;
            int b = sub.length()-1;
            bool flag = true;
            while(a<=b){
                if(sub[a] != sub[b]){
                    flag = false;
                }
                a++;
                b--;
            }
            if(flag){
                cout<<sub<<endl;
            }
        }
    }
}

int main(){
    palindromeSubString("abccbc");
}