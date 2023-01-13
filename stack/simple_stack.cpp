#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int max_capacity;
        int *data;
        int top;

        Stack(int s){
            max_capacity = s;
            data = new int[s];
            top = -1;
        }

        int size(){
            return top+1;
        }

        void push(int element){
            if(size()<max_capacity){
                top++;
                data[top] = element;
            }
            else{
                cout<<"Stack overflow\n";
            }
        }

        void pop(){
            if(top != -1){
                top--;
            }
        }

        int peek(){
            if(top == -1){
                return -1;
            }
            else{
                return data[top];
            }
        }
};

int main(){
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.pop();
    cout<<s.peek();
}