#include <iostream>
using namespace std;

struct student {
    int roll_no;
    string name;
    float sgpa;
};

// Function to create the database
void create_database(student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the details of student " << i + 1 << ":" << endl;
        cout << "Roll number of the student: ";
        cin >> s[i].roll_no;

        cin.ignore(); // clear newline
        cout << "Enter the name of the student: ";
        getline(cin, s[i].name);

        cout << "SGPA of the student: ";
        cin >> s[i].sgpa;
    }
}

// Function to display the database
void display(student s[], int n) {
    cout << "Record(s) of the student(s):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Roll number: " << s[i].roll_no << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "SGPA: " << s[i].sgpa << endl;
    }
}

// Partition function for Quick Sort (Descending by SGPA)
int partition(student s[], int l, int h) {
    float pivot = s[l].sgpa; 
    int i = l;
    int j = h;

    while (i < j) {
        while (i <= h && s[i].sgpa >= pivot) {
            i++;
        }

        while (s[j].sgpa < pivot) {
            j--;
        }

        if (i < j) {
            swap(s[i], s[j]);
        }
    }

    swap(s[l], s[j]);
    return j; // Return pivot index
}

// Quick Sort function (Descending by SGPA)
void quicksort(student s[], int l, int h) {
    if (l < h) {
        int p = partition(s, l, h);  // Partition index
        quicksort(s, l, p - 1);      // Sort left partition
        quicksort(s, p + 1, h);      // Sort right partition
    }
}

// Bubble Sort by roll_no in ascending order
void BubbleSort(student s[], int n) {
    for (int pass = 1; pass < n; pass++) {
        for (int i = 0; i < n - pass; i++) {
            if (s[i].roll_no > s[i + 1].roll_no) {
                student temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
            }
        }
    }
}

// Linear search by sgpa and print matching students
void Linear_search(student s[], int n, float key) {
    int flag = 0;
    cout << "\nSearching for students with SGPA = " << key << endl;
    for (int i = 0; i < n; i++) {
        if (s[i].sgpa == key) {
            cout << "Roll No: " << s[i].roll_no 
                 << ", Name: " << s[i].name <<endl;
            flag = 1;
        }
    }    
    if (flag == 0) {
        cout << "No student found with SGPA = " << key << endl;
    }
}

void insert_sort(student s[], int n) {
    for (int i = 1; i < n; i++) {
        student key = s[i];
        int j = i - 1;

        while (j >= 0 && (s[j].name > key.name) ) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

int Binary_search(student s[] ,int n ,float key){
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (s[mid].sgpa == key) {
            return mid;
        } else if (s[mid].sgpa < key) {
            end = mid - 1; // since array sorted descending by sgpa
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of students whose details you want to add: ";
    cin >> n;

    student s[n];
    create_database(s, n);
    display(s, n);

    cout << "functions that we want to perform" << endl;
    cout << "1. Bubble Sort " << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "4. Linear Search" << endl;
    cout << "5. Binary Search" << endl;

    int choice;
    do{
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            BubbleSort(s, n);
            cout << "After Bubble Sort:" << endl;
            display(s, n);
            break;

        case 2:
            insert_sort(s, n);
            cout << "After Insertion Sort:" << endl;
            display(s, n);
            break;

        case 3:
            quicksort(s, 0, n - 1);
            cout << "After Quick Sort:" << endl;
            display(s, n);
            break;

        case 4: {
            float key;
            cout << "Enter SGPA to search: ";
            cin >> key;
            Linear_search(s, n, key);
            break;
        }

        case 5: {
            float key;
            cout << "Enter SGPA to search: ";
            cin >> key;
            int pos = Binary_search(s, n, key);
            if (pos != -1) {
                cout << "Found student:" << endl;
                cout << "Roll No: " << s[pos].roll_no
                     << ", Name: " << s[pos].name
                     << ", SGPA: " << s[pos].sgpa << endl;
            } else {
                cout << "No student found with SGPA = " << key << endl;
            }
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }
    }while(choice != 0);
    return 0;
}