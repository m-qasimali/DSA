#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int max_capacity;
        int *data;
        int top;

        Stack(){
            max_capacity = 5;
            data = new int[max_capacity];
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
                max_capacity = 2*max_capacity;
                int *arr = new int[max_capacity];
                for(int i=0;i<=top;i++){
                    arr[i] = data[i];
                }
                top++;
                arr[top] = element;
                data = arr;
                delete arr;
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
    Stack s;
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
    cout<<s.peek();
}