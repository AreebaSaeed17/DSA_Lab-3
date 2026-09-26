#include<iostream>

// creating the class for queue description
class Queue {
public:
    struct node {
        int data;
        node *next = nullptr;
        node(int data) {
            this->data = data;
        }
    };

    // creating the 2 ptrs for a queue
    node *front = nullptr;
    node *rear = nullptr;

    // inserting element at end of queue
    void enqueue(int value) {
        node *newNode = new node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        std::cout << "\nEnqueued value: " << value << "\n";
    }

    // removing elemnt from front of the queue
    void dequeue() {
        if (front == nullptr) {
            std::cout << "\nQueue is empty. Nothing to dequeue.\n";
            return;
        }
        node *nodeToDelete = front;
        std::cout << "\nDequeued value: " << nodeToDelete->data << "\n";
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete nodeToDelete;
    }

    // return the element of the front ptr without removing that
    void peek() {
        if (front == nullptr) {
            std::cout << "\nQueue is empty.\n";
            return;
        }
        std::cout << "\nFront element is: " << front->data << "\n";
    }

    // tells whether the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // prints the queue elements
    void display() {
        node *temp = front;
        std::cout << "\nThe queue is: \n";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

// testing the code
int main(){
    Queue *q = new Queue();
    q->enqueue(10);
    q->enqueue(60);
    q->enqueue(56);

    q->display();
    q->isEmpty();

    q->dequeue();
    q->display();
}