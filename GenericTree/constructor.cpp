#include "bits/stdc++.h"
using namespace std;



class Node{
    public:
        int val;
        vector<Node> *children;
    
        Node(int val){
            this->val = val;
        }
};

class GenericTree{
    public:
        vector<int> data;
        Node *head;
    
        GenericTree(vector<int> data){
            this->data = data;
            head = NULL;
        }

        void createTree(){
            stack<Node> s;
            for(int i=0; i<data.size(); i++){
                if(data.at(i) == -1){
                    s.pop();
                }
                else{
                    Node *node = new Node(data.at(i));
                    if(s.size() > 0){
                        s.top().children->push_back(*node);
                    }
                    else{
                        head = node;
                    }
                    s.push(*node);
                }
            }
        }


        void display(){
            cout<<head->val;
        }

};


int main(){
    vector<int> data = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,10,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    GenericTree gt(data);
    gt.createTree();
    gt.display();
}