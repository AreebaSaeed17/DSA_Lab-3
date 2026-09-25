#include<iostream>
using namespace std;

class LinkedList{
    public:
    // defining struct for node of linkedlist
    struct node {
        private:
        int data;
        node *next = nullptr;

        public:
        node(int data){
            this-> data = data; 
        }
    };

    // creating the head and tail ptrs
    node * head = nullptr;
    node * tail = nullptr;

    // create a new node
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);

    if(head==nullptr){

    }



};