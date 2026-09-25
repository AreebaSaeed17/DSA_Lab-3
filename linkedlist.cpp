#include<iostream>

class LinkedList{

    public:
    // defining struct for node of linkedlist
    // making it public to access these throughout the program
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


    // function to create the initial linkedlist
    void InsertNode_atHead(int data){
    
        node *newNode = new node(data);

        if(head == nullptr){
            head = newNode;
        }
        
        // if the linkedlist already exists, add the new node such that it replaces the head
        else{
            newNode-> next = head;      // whatever head was pointing to becomes 2nd to this new node
                                        // so we store that in its *nexts
            head = newNode;
        }
    }


    // function to insert a node at a specific position
    void insertNode(){

        int data, pos;
        int num_of_nodes = checkNumberofNodes();
        std::cout<<"\nCurrently there are " << num_of_nodes <<" nodes in the linkedlist.\n";
        std::cout<<"\nAt what position do you wish to add a new node?\nKeep the position within range for proper creation.\n";
        std::cin>>pos;

        std::cout<<"What value node do you wish to create? \n";
        std::cin>>data;

        node *newNode = new node(data);     // creating node with value user gave
       
        node * temp_ptr = head;
        
        // run a loop and stop at the node behind the position we have to insert
        for (int i = 1; i<(pos-1); i++){
            temp_ptr = temp_ptr ->next;             // keep moving the ptr forward
        }
        
        // Now insert that node we just made
        // link the node with its next node
        newNode->next = temp_ptr;
        temp_ptr = newNode;     // connect the link from behind

        std::cout<<"\nA node has been created with the data: \n";
        std::cout<<temp_ptr->data;
    }

    void DeleteNode(){
        int pos;

        int num_of_nodes = checkNumberofNodes();
        std::cout<<"\nCurrently there are " << num_of_nodes <<" nodes in the linkedlist.\n";
        std::cout<<"\nWhich node do you want to delete?\nKeep the position within range for proper deletion.\n";
        std::cin>>pos;

        node *temp = head;
    
        // reach one node behind the position at which i want to delete the node
        for (int i = 1; i<(pos-1); i++){
            temp = temp ->next;             // keep moving the ptr forward
        }
        
        temp ->next = temp->next->next;      // make it point to the next to next node

        temp = temp->next;                  // bring temp to the actual node i want to delete
        std::cout<<"Deleting the node at position " << pos << " storing data: " << temp->data <<" \n";
        delete temp;                        // delete that node 
    }

    // function to check number of nodes in the list
    int checkNumberofNodes(){
        node* traversal = head;
        int count = 0;
        while(traversal != nullptr){
            count++;
            traversal = traversal->next;
        }
        return count;
    }
    
    // print out the linkedlist
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
    list->InsertNode_atHead(0);
    list->InsertNode_atHead(10);
    list->InsertNode_atHead(20);
    list->InsertNode_atHead(30);

    std::cout<<"\nChoose one of the following operations to perform: \n";
    std::cout<<"1. Insertion of A Node at any position\n";
    std::cout<<"2. Deletion of A Node\n";
    std::cout<<"3. Check number of nodes\n";
    std::cout<<"4. Display the linkedlist\n";
    std::cout<<"5. Quit the program (Enter -1)\n";


    std::cout<<"\nEnter your choice: ";
    int choice;
    std::cin>>choice;

    do {

         switch (choice){
        case 1:
        list->insertNode();
        break;

        case 2:
        list->DeleteNode();

        case 3:
        list->checkNumberofNodes();

        case 4:
        list->DisplayLL();
        break;

        case -1:
        std::cout<<"______Quitting the program______\n";
        break;

        default:
        std::cout<<"You have entered an invalid number.\nCouldn't be processed...\n";
        }
    } 
    while(choice != -1);
   

    // displaying the linkedlist
    //list -> DisplayLL();

    // inserting nodes
    //list ->insertNode();

     
    //std::cout<< "The number of nodes in the current linkedlist are "<< list -> checkNumberofNodes() << std::endl;



}