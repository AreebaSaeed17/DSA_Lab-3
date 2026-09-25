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

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        // if the node being added isnt the 1st node then create links
        else{
            tail->next = newNode;
            tail = newNode;
        }

        std::cout<<"A node has been created with the data: ";
        std::cout<<tail->data;
    }

    void DisplayLL(){

        node * temp = head;
        std::cout<< "\nThe linked list is: \n";
        while(temp!=nullptr){
            std::cout<< temp->data << " ";
        }
    }

};

int main(){

    // creating an object for the linkedlist class
    LinkedList *list = new LinkedList();

    // creating a node
    std::cout<<"What value do you want to give to the node? \n";
    int val;
    std::cin>>val;
    list->CreateNode(val);


}