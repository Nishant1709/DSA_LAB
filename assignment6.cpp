/*Develop a hashing-based system for securely storing user credentials, where usernames act as keys
and hashed passwords as values. Implement and demonstrate collision handling using:
• Chaining (Array-based collision resolution)
• Open Addressing (Linear or Quadratic Probing without chaining)*/
#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll;
};

const int SIZE = 10;
Student table[SIZE];

// insert function
void insertStudent() {
    string name;
    int roll;

    cout << endl << "Enter student name: ";
    cin >> name;
    cout << "Enter roll number: ";
    cin >> roll;

    int index = roll % SIZE;

    // linear probing if space not empty
    while (table[index].roll != 0) {
        index = (index + 1) % SIZE;
    }

    table[index].name = name;
    table[index].roll = roll;

    cout << "Student inserted successfully." << endl;
}

// display function
void display() {
    cout << endl << "Hash Table Data:" << endl;
    for(int i = 0; i < SIZE; i++) {
        if(table[i].roll != 0) {
            cout << "Index " << i << " : " << table[i].name 
                 << " (Roll: " << table[i].roll << ")" << endl;
        } else {
            cout << "Index " << i << " : empty" << endl;
        }
    }
}

int main() {
    // initialize table
    for(int i = 0; i < SIZE; i++) {
        table[i].roll = 0;
    }

    int choice;

    while(1) {
        cout << endl << "--- MENU ---" << endl;
        cout << "1. Insert student" << endl;
        cout << "2. Display hash table" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            insertStudent();
        }
        else if(choice == 2) {
            display();
        }
        else if(choice == 3) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
//output
/*PS C:\Users\Nishant Sarwa\OneDrive\Documents\Nishant Sarwa\DSA> g++ assignment6.cpp
PS C:\Users\Nishant Sarwa\OneDrive\Documents\Nishant Sarwa\DSA> ./a.exe
enter size: 10

1 insert
2 display
3 exit
choice: 1
roll: 23331
name: nishant
pass: 13332
added roll 23331 at index 1

1 insert
2 display
3 exit
choice: 1
roll: 23330
name: rohan
pass: 03332
added roll 23330 at index 0

1 insert
2 display
3 exit
choice: 2
index 0: 23330 rohan 3332 -> NULL
index 1: 23331 nishant 13332 -> NULL
index 2: empty
index 3: empty
index 4: empty
index 5: empty
index 6: empty
index 7: empty
index 8: empty
index 9: empty

1 insert
2 display
3 exit
choice:*/