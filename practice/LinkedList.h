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
                return;
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
                return;
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


};