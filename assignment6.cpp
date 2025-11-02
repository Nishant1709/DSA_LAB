#include <iostream>
using namespace std;

class node {
public:
    int roll;
    string name;
    long pass;
    node *next;

    node(int r, string n, long p) {
        roll = r;
        name = n;
        pass = p;
        next = NULL;
    }
};

class student {
    int size;
    node **tab;

    int hashf(int r) {
        return r % size;
    }

public:
    student(int s) {
        size = s;
        tab = new node*[size];
        for (int i = 0; i < size; i++) {
            tab[i] = NULL;
        }
    }

    void insertdata(int r, string n, long p) {
        int i = hashf(r);
        node *t = new node(r, n, p);
        t->next = tab[i];
        tab[i] = t;
        cout << "added roll " << r << " at index " << i << endl;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << "index " << i << ": ";
            node *t = tab[i];
            if (t == NULL) {
                cout << "empty";
            } else {
                while (t != NULL) {
                    cout << t->roll << " " << t->name << " " << t->pass << " -> ";
                    t = t->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "enter size: ";
    cin >> n;

    student s(n);
    int ch, r;
    string nm;
    long pw;

    do {
        cout << "\n1 insert\n2 display\n3 exit\n";
        cout << "choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "roll: ";
                cin >> r;
                cout << "name: ";
                cin >> nm;
                cout << "pass: ";
                cin >> pw;
                s.insertdata(r, nm, pw);
                break;

            case 2:
                s.show();
                break;

            case 3:
                cout << "bye"<<endl;
                break;

            default:
                cout << "wrong"<< endl;
        }
    } while (ch != 3);

    return 0;
}
