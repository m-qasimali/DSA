#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string data){
    stack<char> s;
    int i=0;
    while(i != data.length()){
        char ch = data.at(i);
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else if(ch == ')'){
            if(s.size() == 0){
                return false;
            }
            else{
                if(s.top() != '('){
                    return false;
                }
                s.pop();
            }
        }
        else if(ch == '}'){
            if(s.size() == 0){
                return false;
            }
            else{
                if(s.top() != '{'){
                    return false;
                }
                s.pop();
            }
        }
        else if(ch == ']'){
            if(s.size() == 0){
                return false;
            }
            else{
                if(s.top() != '['){
                    return false;
                }
                s.pop();
            }
        }
        i++;
    }
    return s.size() == 0;
}

int main(){
    cout<<isBalanced("[(a+b)+{(c+d)*(e/f)]}");
}