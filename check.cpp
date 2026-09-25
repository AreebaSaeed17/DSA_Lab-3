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
    void CreateLL(int data){
    
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

        std::cout<<"\nA node has been created with the data: \n";
        std::cout<<tail->data;
    }

    int checkNumberofNodes(node* head){
        node* traversal = head;
        int count = 0;
        while(traversal != nullptr){
            count++;
            traversal = traversal->next;
        }
        return count;
    }
    void AddNode_LL(node*head, int pos, int data){
        // first check if we that many nodes are even present after which we are adding new node
        if(pos >= checkNumberofNodes(head)){
            CreateLL(data);
            
        }
    }

    void DisplayLL(node*head){

        node * temp = head;
        std::cout<< "\nThe linked list is: \n";
        while(temp!=nullptr){
            std::cout<< temp->data << " ";
            temp = temp->next;
        }  
    }

};

int main(){

    // creating an object for the linkedlist class
    LinkedList *list = new LinkedList();

    // create a LL
    cree

    // displaying the linkedlist
    list -> DisplayLL();



}