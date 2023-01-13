#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int front =-1, rear =-1;
        int capacity;
        int *data;
        int size = 0;
    
        Queue(int s){
            capacity = s;
            data = new int[capacity];
        }

        void enqueue(int val){
            if(size >= capacity){
                capacity = capacity*2;
                int *arr = new int[capacity];
                int j = front;
                for(int i=0;i<size;i++){
                    arr[i] =  data[j];
                    j = (j+1)%capacity;
                }
                data = arr;
                front = 0;
                rear = size;
                data[rear] = val;
                size++;
            }
            else{
                if(front == -1){
                    front++;
                }
                rear = (rear+1)%capacity;
                data[rear] = val;
                size++;
            }
        }

        int dequeue(){
            if(size == 0){
                return -1;
            }
            else{
                int val = data[front];
                front++;
                size--;
                return val;
            }
        }

        void display(){
            int j = front;
            for(int i=0;i<size;i++){
                cout<<data[j]<<" ";
                j = (j+1)%capacity;
            }
        }

};

int main(){
    Queue q(5);
    q.enqueue(1);
    // q.dequeue();
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();

}