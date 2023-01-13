#include "LinkedList.h"

using namespace std;

class Stack{
    public:
        LinkedList list;

        void push(int val){
            list.addFirst(val);
        }

        void pop(){
            list.removeFirst();
        }

        int top(){
            return list.getFirst()->data;
        }

        int size(){
            return list.getSize();
        }

        void display(){
            for(int i=0;i<size();i++){
                cout<<list.getAt(i)->data<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Stack s;
    s.push(1); 
    s.push(2); 
    // s.pop();
    s.push(3); 
    s.push(4); 
    s.display(); 
}