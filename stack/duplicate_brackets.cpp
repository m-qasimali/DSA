#include<bits/stdc++.h>
using namespace std;


bool isDuplicateBrackets(string data){
    stack<char> s;
    int i = 0;
    while(i < data.length()){
        if(data.at(i) == ')'){
            if(s.top() == '('){
                return true;
            }
            else{
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            }
        }
        else{
            s.push(data.at(i));
        }
        i++;
    }
    return false;
}

int main(){
    cout<<isDuplicateBrackets("(a+b)");
}