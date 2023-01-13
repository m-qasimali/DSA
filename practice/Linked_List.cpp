#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(){}

        Node(int val){
            data = val;
            next = NULL;
        }
};

class LinkedList{
    public:
        Node *tail;
        Node *head;
        int size;
    
        LinkedList(){
            tail = NULL;
            head = NULL;
            size = 0;
        }

        void addLast(int val){
            Node *node = new Node(val);
            if(size == 0){
                head = tail = node;
            }
            else{
                tail->next = node;
                tail = node;
            }
            size++;
        }

        void addFirst(int val){
            Node *node = new Node(val);
            if(size == 0){
                head = tail = node;
            }
            else{
                node->next = head;
                head = node;
            } 
            size++;
        }

        void addAt(int index,int val){
            if(index < 0 && index>getSize()){
                cout<<"Invalid index";
            }
            else if(index == 0){
                addFirst(val);
            }
            else if(index == getSize()){
                addLast(val);
            }
            else{
                Node *node = new Node(val);
                Node *temp = head;
                while(index>1){
                    temp = temp->next;
                    index--;
                }
                node->next = temp->next;
                temp->next = node;
                size++;
            }
        }

        Node* getFirst(){
            if(size!=0){
                return head;
            }
            return NULL;
        }

        Node* getLast(){
            if(size != 0){
                return tail;
            }
            return NULL;
        }

        int getSize(){
            return size;
        }

        void removeFirst(){
            if(size == 0){
                cout<<"Linked List is empty..."<<endl;
            }
            else if(size == 1){
                delete head;
                head = tail = NULL;
                size--;
            }
            else{
                Node *temp = head;
                head = head->next;
                free(temp);
                size--;
            }
        }

        Node *getAt(int index){
            if(index < 0 && index>size){
                cout<<"Invalid index";
            }
            else if(index == 0){
                return getFirst();
            }
            else if(index == size-1){
                return getLast();
            }
            else{
                Node *temp = head;
                while(index>0){
                    temp = temp->next;
                    index--;
                }
                return temp;
            }
        }

        void removeAt(int index){
            if(index < 0 && index>size){
                cout<<"Invalid index";
            }
            else if(index == 0){
                removeFirst();
            }
            else if(index == size-1){
                removeLast();
            }
            else{
                Node *temp = head;
                while(index>1){
                    temp = temp->next;
                    index--;
                }
                Node *removedNode = temp->next;
                temp->next = removedNode->next;
                free(removedNode);
            }
        }

        void removeLast(){
            if(size == 0){
                cout<<"Linked List is empty..."<<endl;
            }
            else if(size == 1){
                free(head);
                head = tail = NULL;
                size--;
            }
            else{
                Node *temp = head;
                while(temp->next->next != NULL){
                    temp = temp->next;
                }
                temp->next = NULL;
                free(tail);
                tail = temp;
                size--;
            }
        }

        Node* mid(Node *head, Node *tail){
            if(head != NULL){
                Node *slow = head;
                Node *fast = head;
                while(fast !=tail && fast->next!=tail){
                    slow = slow->next;
                    fast = fast->next->next;
                }
                return slow;
            }
            return NULL;
        }

        void removeNode(Node *node){
            if(node == head){
                removeFirst();
            }
            else if(node == tail){
                removeLast();
            }
            else{
                Node *temp = head;
                Node *previousNode = NULL;
                while(temp != node){
                    previousNode = temp;
                    temp = temp->next;
                }
                if(temp == node){
                    previousNode->next = previousNode->next->next;
                }
                delete temp;
            }
        }

        void reverseDI(){
            int i=0;
            int j = size-1;
            while(i<j){
                swap(getAt(i)->data,getAt(j)->data);
                i++;
                j--;
            }
        }

        void reversePI(){
            Node *previous = NULL;
            Node *cur = head;
            Node *nextNode = head;
            tail = head;
            while(cur!=NULL){
                nextNode = cur->next;
                cur->next = previous;
                previous = cur;
                cur = nextNode;
            }
            head = previous;
        }

        LinkedList* mergeSortedLists(LinkedList *list1, LinkedList *list2){
            Node *a = list1->head;
            Node *b = list2->head;
            LinkedList *newList = new LinkedList();
            while(a!=NULL && b!=NULL){
                if(a->data < b->data){
                    newList->addLast(a->data);
                    a = a->next;
                }
                else{
                    newList->addLast(b->data);
                    b = b->next;
                }
            }
            while(a!=NULL){
                newList->addLast(a->data);
                a = a->next;
            }
            while(b!=NULL){
                newList->addLast(b->data);
                b = b->next;
            }
            return newList;
        }

        void removeDuplicates(){
            LinkedList *sortedList = mergeSort(this->head, this->tail);
            LinkedList *res = new LinkedList(); 
            Node *temp = sortedList->head;
            while(temp!=NULL){
                if(res->size == 0 || res->getLast()->data < temp->data){
                    res->addLast(temp->data);
                }
                temp = temp->next;
            }
            this->head = res->head;
            this->tail = res->tail;
            this->size = res->size;
        }

        LinkedList* mergeSort(Node *head, Node *tail){
            if(head == tail){
                LinkedList *br = new LinkedList();
                br->addLast(head->data);
                return br;
            }
            Node *mid = this->mid(head,tail);
            LinkedList *fsh = mergeSort(head,mid);
            LinkedList *ssh = mergeSort(mid->next,tail);
            LinkedList *c1 = this->mergeSortedLists(fsh, ssh);
            return c1;
        }

        void display(){
            Node *temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        // return the kth term from end without using size() method directly or indirectly
        int getFromEnd(int k){
            Node *slow = head;
            Node *fast = head;
            // keep the k differnce between slow and fast pointer
            while(fast!=NULL && k!=0){
                fast = fast->next;
                k--;
            }

            while(fast!=NULL && fast!=tail){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == NULL){
                return -1;
            }
            return slow->data;
        }

        void segregrateEvenOdd(){
            int odd = -1;
            LinkedList newList;
            Node *temp = head;
            while(temp != NULL){
                if(temp->data%2==0){
                    newList.addLast(temp->data);
                }
                else{
                    ++odd;
                    newList.addAt(odd,temp->data);
                }
                temp = temp->next;
                this->removeFirst();
            }
            this->head = newList.head;
            this->tail = newList.tail;
            this->size = newList.getSize();
        }

        // K- reverse
        void kReverse(int k){
            for(int i=0; i<this->getSize(); i=i+k){
                int l = i;
                int r;
                if(l+k > this->getSize()){
                    r = this->getSize()-1;
                }
                else{
                    r = i+k-1;
                }
                while(l<r){
                    swap(this->getAt(l)->data,this->getAt(r)->data);
                    l++;
                    r--;
                }
            }
        }

};

int main(){
    LinkedList list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);
    list.addLast(6);
    list.addLast(7);
    list.addLast(8);
    list.addLast(9);
    list.addLast(10);
    list.addLast(11);
    list.addLast(12);
    list.addLast(13);
    list.addLast(14);
    list.display();
    // list.segregrateEvenOdd();
    list.kReverse(5);
    // list.addAt(11,88);
    // list.addAt(list.getSize(),99);
    // list.addAt(1,765);
    // cout<<list.getFromEnd(10)<<endl;
    // list.removeDuplicates();
    // list.reversePI();
    // cout<<endl;
    // list.removeNode(list.head->next);
    list.display();
    // list.mergeSort(list.head, list.tail)->display();
    // cout<<list.mid(list.head,list.tail)->data;
    // list.removeFirst();
    // list.removeLast();
    // list.display();
    // cout<<list.getFirst();
    // cout<<list.getLast();


    // LinkedList list1;
    // list1.addLast(1);
    // list1.addLast(3);
    // list1.addLast(5);
    // list1.addLast(90);
    // list.addLast(5);
    // list.addLast(6);

    // LinkedList list2;
    // list2.addLast(2);
    // list2.addLast(4);
    // list2.addLast(6);
    // list.addLast(4);
    // list.addLast(5);
    // list.addLast(6);
    // list1.mergeSortedLists(&list1,&list2)->display();
}