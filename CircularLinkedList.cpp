#include<iostream>

// define the ciruclar linkedlist
class CircularLinkedList {
public:
    struct node {
        int data;
        node *next = nullptr;
        // constructor
        node(int data) {
            this->data = data;
        }
    };

    node *last = nullptr;

    // function to insert element at end
    void insertAtEnd(int data) {
        node *newNode = new node(data);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        std::cout << "\nInserted " << data << " at the end.\n";
    }

    // delete the front element
    void deleteFromFront() {
        if (last == nullptr) {
            std::cout << "\nList is empty. Nothing to delete.\n";
            return;
        }
        node *firstNode = last->next;
        std::cout << "\nDeleting front node with data: " << firstNode->data << "\n";
        
        if (last == firstNode) {
            last = nullptr;
        } else {
            last->next = firstNode->next;
        }
        delete firstNode;
    }

    // print the linkedlist
    void display() {
        if (last == nullptr) {
            std::cout << "\nThe list is empty.\n";
            return;
        }
        node *temp = last->next;
        std::cout << "\nThe circular linked list is: \n";
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        std::cout << "\n";
    }
};


int main(){
    // creating an object
    CircularLinkedList *circular = new CircularLinkedList();
    // testing out the functions
    // adding nodes at the end
    circular->insertAtEnd(120);
    circular->insertAtEnd(980);
    circular->insertAtEnd(07);

    circular->display();
    circular->deleteFromFront();
    circular->display();
}