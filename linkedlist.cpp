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

    // function to insert a node at a specific position
    void insertNode(){

        int data, pos;

        std::cout<<"Currently there are "<<checkNumberofNodes<<" nodes in the linkedlist.\n";
        std::cout<<"At what position do you wish to add a new node?\n Keep the position within range for proper creation.\n";
        std::cin>>pos;

        std::cout<<"What value node do you wish to create? ";
        std::cin>>data;

        node *newNode = new node(data);     // creating node with value user gave
       
        node * temp_ptr = head;
        
        // run a loop and stop at the node behind the position we have to insert
        for (int i = 0; i<(pos-1); i++){
            temp_ptr = temp_ptr ->next;             // keep moving the ptr forward
        }
        
        // Now insert that node we just made
        // link the node with its next node
        newNode->next = temp_ptr;
        temp_ptr = newNode;     // connect the link from behind

            
        

        std::cout<<"\nA node has been created with the data: \n";
        std::cout<<tail->data;
    }

    int checkNumberofNodes(){
        node* traversal = head;
        int count = 0;
        while(traversal != nullptr){
            count++;
            traversal = traversal->next;
        }
        return count;
    }
    /*void AddNode_LL(node*head, int pos, int data){
        // first check if we that many nodes are even present after which we are adding new node
        if(pos >= checkNumberofNodes(head)){
            CreateLL(data);

        }
    }*/

    // WORKS
    void DisplayLL(){

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

    // I am creating a linkedlist first by calling the function
    // this linkedlist has 4 nodes
    list->CreateLL(0);
    list->CreateLL(10);
    list->CreateLL(20);
    list->CreateLL(30);

    // displaying the linkedlist
    list -> DisplayLL();

    std::cout<< "The number of nodes in teh current linkedlist are "<< list -> checkNumberofNodes() << std::endl;


}