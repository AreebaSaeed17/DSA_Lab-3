#include<iostream>
using namespace std;

int main(){

    class node{

        public:
        int data;
        node* next;

        // constructor
        public:
        node(int data){
            this->data = data;
            next = nullptr;
        }
    };

    // creation of nodes
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);

    // linking the nodes

    node *head = nullptr;
    node *tail = nullptr;


    // make the head node
    if(head == nullptr){
        head = n1;
        head->next = n2;
    }

    // link n2 to n3
    tail = n2;
    tail->next = n3;

    tail = n3;
    tail->next = nullptr;

    // insertion at user reuested position
    cout<< "At what position do you want to insert a new node?";
    int pos;
    cin>>pos;

    cout<< "What value do you want to give to the new node?";
    int val;
    cin>>val;

    node *NewNode = new node(val);

    node *temp = head;
    
    for (int i=1; i<(pos-1); i++){
        temp = temp->next;
    }
    // after this loop we've arrived at the point after which i want to add the node

    NewNode->next = temp->next;
    temp ->next = NewNode;

    node * printing = head;
    while(printing!=nullptr){
        cout<< printing->data <<endl;
        printing = printing->next;
    }
    

}