#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int max_capacity;
    int64_t *data;
    int tp;
    int64_t minData;
    
    Stack() {
        max_capacity = 5;
        data = new int64_t[max_capacity];
        tp = -1;
    }
    
    int size(){
        return tp+1;
    }
    
    void push(int64_t element) {
        if(size()>=max_capacity){
            max_capacity = 2*max_capacity;
            int64_t *arr = new int64_t[max_capacity];
            for(int i=0;i<=tp;i++){
                arr[i] = data[i];
            }
            data = arr;
            delete arr;
        }
        if(tp == -1){
            minData = element;
            tp++;
            data[tp] = element; 
        }
        else if(element <= minData){
            tp++;
            data[tp] = element + element - minData;
            minData = element;
        }
        else{
            tp++;
            data[tp] = element;
        }
    }
    
    void pop() {
        if(tp != -1){
            if(data[tp] < minData){
                minData = 2 * minData - data[tp];
            }
            tp--;
        }
    }
    
    int top() {
        if(tp == -1){
            return -1;
        }
        else{
            if(data[tp] < minData){
                return minData;
            }
            return data[tp];
        }
    }
    
    int getMin() {
        if(tp == -1){
            return -1;
        }
        else{
            return minData;
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(9);
    s.push(8);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.peek();
    cout<<s.getMin();
}