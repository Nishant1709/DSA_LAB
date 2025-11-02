#include <iostream>
using namespace std;

// Node class for both stack and queue
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Stack class
class MyStack {
public:
    Node* top;
    MyStack() {
        top = NULL;
    }
    void PUSHSTACK() {
        int data;
        cout << "Enter the data: " << endl;
        cin >> data;
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
    }
    void POPSTACK() {
        if (top == NULL) {
            cout << "The stack is empty, nothing to pop" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void PEEPSTACK() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Value of top: " << top->data << endl;
        }
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        cout << "Dequeued: " << value << endl;
    }
    int peek() {
        if (front == NULL) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    MyStack stack;
    Queue queue;
    int choice;

    do {
        cout << "\nSelect Operation:" << endl;
        cout << "1. Stack Push" << endl;
        cout << "2. Stack Pop" << endl;
        cout << "3. Stack Peek" << endl;
        cout << "4. Queue Enqueue" << endl;
        cout << "5. Queue Dequeue" << endl;
        cout << "6. Queue Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                stack.PUSHSTACK();
                break;
            case 2:
                stack.POPSTACK();
                break;
            case 3:
                stack.PEEPSTACK();
                break;
            case 4: {
                int val;
                cout << "Enter value to enqueue: ";
                cin >> val;
                queue.enqueue(val);
                break;
            }
            case 5:
                queue.dequeue();
                break;
            case 6:
                cout << "Front value: " << queue.peek() << endl;
                break;
            case 7:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 7);

    return 0;
}
