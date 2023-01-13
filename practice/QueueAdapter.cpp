#include "LinkedList.h"

using namespace std;

class Queue{
    public:
        LinkedList list;

        void enqueue(int val){
            list.addLast(val);
        }

        void dequeue(){
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
    Queue que;
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.dequeue();
    que.enqueue(4);
    // que.display();
    cout<<que.top();
}