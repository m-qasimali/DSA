#include<bits/stdc++.h>
using namespace std;

class DoubleStack{
    public:
        int top1;
        int top2;
        int *data;
        int capacity;

        DoubleStack(int capacity){
            top1 = -1;
            top2 = capacity;
            data = new int[capacity];
            this->capacity = capacity;
        }

        void push1(int val){
            if(top1+1 == top2){
                cout<<"Stack1 overflow\n";
            }
            else{
                top1++;
                data[top1] = val;
            }
        }

        void push2(int val){
            if(top1+1 == top2){
                cout<<"Stack1 overflow\n";
            }
            else{
                top2--;
                data[top2] = val;
            }
        }

        int size1(){
            return top1 + 1;
        }

        int size2(){
            return this->capacity-top2;
        }

        void pop1(){
            if(size1() == 0){
                cout<<"Stack1 underflow\n";
            }
            else{
                top1--;
            }
        }

        void pop2(){
            if(size2() == 0){
                cout<<"Stack2 underflow\n";
            }
            else{
                top2++;
            }
        }

        int peek1(){
            if(size1() == 0){
                cout<<"Stack1 underflow";
                return -1;
            }
            else{
                return data[top1];
            }
        }

        int peek2(){
            if(size2() == 0){
                cout<<"Stack2 underflow";
                return -1;
            }
            else{
                return data[top2];
            }
        }

        void display1(){
            for(int i=size1()-1; i>=0; i--){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }

        void display2(){
            for(int i=top2; i<capacity; i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    DoubleStack s(5);
    s.push2(1);
    s.push2(2);
    s.push2(3);
    s.push2(4);
    s.push2(5);
    s.pop2();
    s.pop1();
    // s.display1();
    // s.display2();
    cout<<s.peek1()<<endl;
    cout<<s.peek2()<<endl;
}