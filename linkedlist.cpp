#include<iostream>
using namespace std;

class LinkedList{
    public:
    // defining struct for node of linkedlist
    struct node {

        int data;
        node *next = nullptr;
    
        node(int data){
            this-> data = data; 
        }
    };

    // creating the head and tail ptrs
    node * head = nullptr;
    node * tail = nullptr;

   
    // function to create a new node
    void CreateNode(int data){
    
        node *newNode = new node(data);

        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

    }



};