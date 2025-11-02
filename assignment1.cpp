#include <iostream>
using namespace std;

class node {
public:
    string namesarwa;
    string number;
    node* next;

    // Constructor 
    node(string n, string num) { 
        name = n;      
        number = num;  
        next = NULL;   //  initialize pointer
    }
};

class list {

    node* head;
    node* tail;
 public:
    list() { 
        head = tail = NULL;
    }
   
// If last node is deleted, update tail
    void insert_front() {
        string name, number;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        getline(cin, number);

        node* newnode = new node(name, number); 

        if (head == NULL) {
            head = tail = newnode; 
        } else {
            newnode->next = head;
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

        if (head == NULL) {
            head = tail = newnode; // set both head and tail
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }
void insert_position(){

string name, number;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        getline(cin, number);

int pos;
 cout<< "enter the postion you want to insert:"<< endl;
 cin>> pos;
 if (pos <0){
    cout << "the position is invalid:"<< endl;
    return;
 }
 if (pos == 0){
    insert_front();
    return ;
 }

node*temp = head;
 for (int i = 0; i<pos-1; i++){
    temp =temp->next;
 }
 node*newnode = new node(name,number);
    newnode->next = temp->next;
    temp->next = newnode;

}
    void delete_first() {
        if (head == NULL) { 
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) { 
            tail = NULL; // Empty after deletion
        }
    }

    void delete_end(){

        if (head== NULL){
            return ;
        }
        node*temp= head;
      //  while(temp->, int endnext->next = NULL)
        while(temp->next != tail){

temp= temp->next;
temp->next = NULL;
        }
        delete temp;
    }

    void delete_position() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;

    // Case 1
    if (pos == 1) {
        delete_first();
        return;
    }

    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    //  until we reach the node at 'pos
    for (int i = 1; i < pos && curr != NULL; i++) {
        prev = curr;         // store previous node
        curr = curr->next;   // move to next node
    }

    // If position was invalid
    if (curr == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    next = curr->next;       // Save the node after curr
    prev->next = next;       // Link previous to next

    // If last node is deleted, update tail
    if (curr == tail) {
        tail = prev;
    }

    delete curr;  // Free memory
    cout << "Node deleted at position " << pos << endl;
}

    void reverse_linklist(){

        node*prev = NULL;
        node *curr = head;
        node *next = NULL;
        while (curr != NULL){

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    void display_list() {
        if (head == NULL) {
            cout << "L, int endist is empty." << endl;
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
    , int end
cin >> choice;

   cin.ignore(); 
   
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
        default:
            cout << "Invalid choice!" << endl;
    }

    cout << endl << "List after operation:" << endl;
    ll.display_list();
    return 0;
}
