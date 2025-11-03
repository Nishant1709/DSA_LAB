/*Implementation of a Priority Queue
• Develop a priority queue where elements are dequeued based on priority rather than
insertion order.
• Support operations such as insertion, deletion, and display.
Implementation of a Double-Ended Queue (Deque)
• Implement a double-ended queue where insertion and deletion can happen from both ends.
• Support operations such as enqueue front, enqueue rear, deque front, dequeue rear. */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

class MyQueue {
private:
    Node* front;  

public:
    // Constructor to start with empty queue
    MyQueue() {
        front = NULL;
    }

    // Add new data with priority
    void push() {
        int d, p;
        cout << "Enter data: ";
        cin >> d;
        cout << "Enter priority: ";
        cin >> p;

        Node* newNode = new Node(d, p);

        // If empty queue, newNode is front
        if (front == NULL) {
            front = newNode;
            return;
        }

        // If newNode has higher priority than front put it at front
        if (newNode->priority > front->priority) {
            newNode->next = front;
            front = newNode;
            return;
        }

        //  find correct spot to insert newNode
        Node* temp = front;
        while (temp->next != NULL && temp->next->priority >= newNode->priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    Node* extract_max() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return NULL;
    }
    Node* maxNode = front;    // Step 1: store max
    front = front->next;      // Step 2: remove max by shifting front pointer
    return maxNode;           // Step 3: return max node
}

    // Show the highest priority node
    void peek() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Highest Priority Data: " << front->data << " Priority: " << front->priority << endl;
    } 
};

int main() {
    MyQueue q;
    int choice;

    do {
        cout << "Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: ";
        cin >> choice;

        if (choice == 1) {
            q.push();
        }
        else if (choice == 2) {
            q.peek();
        }
        else if (choice == 3) {
            Node* removedNode = q.extract_max();
            if (removedNode != NULL) {
                cout << "Deleted data: " << removedNode->data << " with priority: " << removedNode->priority << endl;
                delete removedNode;  // free memory
            }
        }
        else if (choice != 0) {
            cout << "Invalid input. Try again." << endl;
        }
    } while (choice != 0);

    cout << "Program ended." << endl;
    return 0;
}

//output
/*PS C:\Users\Nishant Sarwa\OneDrive\Documents\Nishant Sarwa\DSA> g++ assignment5.cpp
PS C:\Users\Nishant Sarwa\OneDrive\Documents\Nishant Sarwa\DSA> ./a.exe
Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: 
1
Enter data: 23
Enter priority: 1
Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: 1
Enter data: 33
Enter priority: 2
Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: 1
Enter data: 44
Enter priority: 3
Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: 2
Highest Priority Data: 44 Priority: 3
Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: 3
Deleted data: 44 with priority: 3
Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: 1
Enter data: 55
Enter priority: 5
Enter 1 to add, 2 to see highest priority, 3 to delete highest priority, 0 to exit: 0
Program ended.*/