/* "Efficient Data Management Using Linked Lists: Implementing Dynamic Operations for
Contact Management System"
Utilize Singly and Doubly Linked Lists to manage a Contact Management System.*/
#include <iostream>
using namespace std;

class node {
public:
    string name;
    string number;
    node* next;

    // making a node (store name & number)
    node(string n, string num) { 
        name = n;
        number = num;
        next = NULL; 
    }
};

class list {
    node* head;
    node* tail;

public:
    list() {
        head = tail = NULL;  // start with empty list
    }

    void insert_front() {
        string name, number;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        getline(cin, number);

        node* newnode = new node(name, number);

        // if list empty then new node is head + tail
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;  // add before first
            head = newnode;
        }
    }

    void insert_end() {
        string name, number;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        getline(cin, number);

        node* newnode = new node(name, number);

        // if empty then head & tail same
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;  // new tail now
    }

    void insert_position() {
        string name, number;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        getline(cin, number);

        int pos;
        cout << "enter the postion you want to insert:" << endl;
        cin >> pos;

        // wrong position check
        if (pos < 0) {
            cout << "invalid position" << endl;
            return;
        }

        // if inserting at front
        if (pos == 0) {
            cin.ignore();
            insert_front();
            return;
        }

        // go to position-1 node
        node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // if pos bigger than list
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }

        node* newnode = new node(name, number);
        newnode->next = temp->next;
        temp->next = newnode;

        // if inserted at end update tail
        if (temp == tail) {
            tail = newnode;
        }

        cin.ignore();
    }

    void delete_first() {
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {  
            tail = NULL;  // list became empty
        }
    }

    void delete_end() {
        // nothing to delete
        if (head == NULL) return;

        // only one node
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        // find second last node
        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void reverse_linklist() {
        // normal reverse logic
        node* prev = NULL;
        node* curr = head;
        node* next = NULL;

        tail = head; // old head becomes tail

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev; // prev is new head
    }

    void display_list() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        while (temp != NULL) {
            cout << "Name of the person is: " << temp->name << endl;
            cout << "Number of the person is: " << temp->number << endl;
            temp = temp->next;
        }
    }
};

int main() {
    list ll;

    // taking 2 contacts first
    ll.insert_front();
    ll.insert_front();
    
    int choice;
    cout << endl << "Choose an operation to perform:" << endl;
    cout <<"1.insert at the end:"<< endl;
    cout <<"2. insert at any position:"<< endl;
    cout <<"3.delete at the front :"<< endl;
    cout <<"4.delete  at the end:"<< endl;
    cout <<"5.reverse a linklist:"<< endl;
    cout <<"6.delete  at any position:"<< endl;

    cin >> choice;
    cin.ignore(); // remove enter key

    switch(choice) {
        case 1:
            ll.insert_end();
            break;
        case 2:
            ll.insert_position();
            break;
        case 3:
            ll.delete_first();
            break;
        case 4:
            ll.delete_end();
            break;
        case 5:
            ll.reverse_linklist();
            break;
        case 6:
            ll.delete_first(); // you wanted delete at pos, but your code didn't have it here
            break;
        default:
            cout << "wrong input" << endl;
    }

    cout << endl << "List after operation:" << endl;
    ll.display_list();
    return 0;
}
