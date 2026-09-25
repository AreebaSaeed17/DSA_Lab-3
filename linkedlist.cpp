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

    // function to add node specifically at 3rd position
    void insertNode_3rd_position(){

        if (checkNumberofNodes() < 2) {
            std::cout << "There are not enough nodes to insert at position 3.\n";
            return;
        }

        int data;
        std::cout<<"\nWhat value node do you wish to create? \n";
        std::cin>>data;


        node *newNode = new node(data);  

        node *temp = head;
        for(int i=1; i<(3-1); i++){
            temp = temp->next;
        }

        // standing at position 2
        newNode->next = temp->next;
        temp->next = newNode;

        std::cout<<"\nA node has been created with the data: ";
        std::cout<<temp->data;

    }

    void DeleteNode(){

        if (head == nullptr){
            std::cout<<"There is nothing to delete.\n";
            return;
        }

        int pos;
        int num_of_nodes = checkNumberofNodes();
        std::cout<<"\nCurrently there are " << num_of_nodes <<" nodes in the linkedlist.\n";
        std::cout<<"\nWhich node do you want to delete?\nKeep the position within range for proper deletion.\n";
        std::cin>>pos;

        // check if user entered valid position
        if (pos < 1 || pos > num_of_nodes){
        std::cout << "Invalid position.\n";
        return;
        }

        // code for deleting head 
        if (pos == 1){
        node *nodeToDelete = head;
        std::cout << "Deleting the head node storing data: " << nodeToDelete->data << "\n";
        head =  head->next;
        delete nodeToDelete; 
        return;
        }

        // general code to delete node at any position
        node *temp = head;
        // stopping one node before the node user wants to delete
        for (int i = 1; i < (pos - 1); i++){
        temp = temp->next;
        }

        // save that node
        node* nodeToDelete = temp->next;

        std::cout << "Deleting the node at position " << pos << "*storing data: "<< nodeToDelete->data << "\n";
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        }

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
  
    std::cout<<"1. Insertion of A Node at position number 3\n";
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
        list->insertNode_3rd_position();
        break;

        case 2:
        list->DeleteNode();
        break;

        case 3:
        std::cout<<"\nThe number of nodes in the linked list are "<< list->checkNumberofNodes()<<"\n";
        break;

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
   


}