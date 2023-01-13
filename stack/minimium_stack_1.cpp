#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int max_capacity;
        int *data;
        int top;
        vector<int> minData;

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
            if(minData.size() == 0 || element <= minData[minData.size()-1]){
                minData.push_back(element);
            }
        }

        int min(){
            if(minData.size() == 0){
                return -1;
            }
            else{
                return minData[minData.size()-1];
            }
        }

        void pop(){
            if(top != -1){
                if(peek() == minData[minData.size()-1]){
                    minData.pop_back();
                }
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
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(14);
    s.push(19);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    // cout<<s.peek();
    cout<<s.min();
}