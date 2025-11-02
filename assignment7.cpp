#include<iostream>
#include<fstream>
using namespace std;

struct Student {
    int roll;
    string name, division, address, dob, grade;
    float percent;
};

void createfile(){
    fstream file;
    file.open("student.txt",ios::out | ios::trunc);

    if(!file.is_open()){
cout<<"error while opening the file"<<endl;
    }
    else{
int n;
cout <<"enter the number of student those detail you want to add:";
cin>>n;
Student s;
for(int i=0;i<n;i++){
    cout<<"enter the roll number"<<endl;
    cin>>s.roll;

     cout<<"enter name of student"<<endl;
    cin>>s.name;

     cout<<"enter division of student"<<endl;
    cin>>s.division;

     cout<<"enter address of student"<<endl;
    cin>>s.address;

     cout<<"enter dob of student"<<endl;
    cin>>s.dob;

     cout<<"enter grade of student"<<endl;
    cin>>s.grade;

     cout<<"enter percent of student"<<endl;
    cin>>s.percent;


    file << s.roll << " "<< s.name <<" " << s.division << " "<< s.address <<" "<< s.dob <<" "<< s.grade <<" " << s.percent <<endl;
}
file.close();
cout <<"file created successfully";
}
}

void displayfile(){
 fstream file;
    file.open("student.txt", ios::in);

    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    int roll;
    string name, division, address, dob, grade;
    float percent;

    cout << "Student Records" << endl;

    while (file >> roll >> name >> division >> address >> dob >> percent >> grade) {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Division: " << division << endl;
        cout << "Address: " << address << endl;
        cout << "DOB: " << dob << endl;
        cout << "Percentage: " << percent << endl;
        cout << "Grade: " << grade << endl;
      
    }

    file.close();
}

void addnewrecords() {
    fstream file;
    file.open("student.txt", ios::app); // append mode

    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    int roll;
    string name, division, address, dob, grade;
    float percent;

    cout << "Enter student details:" << endl;
    cout << "Roll No: ";
    cin >> roll;
    cout << "Name: ";
    cin >> name;
    cout << "Division: ";
    cin >> division;
    cout << "Address: ";
    cin >> address;
    cout << "DOB: ";
    cin >> dob;
    cout << "Percentage: ";
    cin >> percent;
    cout << "Grade: ";
    cin >> grade;

    file << roll << " " << name << " " << division << " " << address
         << " " << dob << " " << percent << " " << grade << endl;  

    file.close();
    cout << "Record added successfully!" << endl;
}
void searchrecord() {
    fstream file;
    file.open("student.txt", ios::in);

    if (!file) {
        cout << "file not found" << endl;
        return;
    }

    int key;
    cout << "enter roll no to search: ";
    cin >> key;

    int roll;
    string name, division, address, dob, grade;
    float percent;
    bool found = false;

    while (file >> roll >> name >> division >> address >> dob >> percent >> grade) {
        if (roll == key) {
            cout << "roll: " << roll << endl;
            cout << "name: " << name << endl;
            cout << "division: " << division << endl;
            cout << "address: " << address << endl;
            cout << "dob: " << dob << endl;
            cout << "percent: " << percent << endl;
            cout << "grade: " << grade << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "record not found" << endl;
    }

    file.close();
}
void modifyrecord() {
    fstream file, temp;
    file.open("student.txt", ios::in);

    if (!file) {
        cout << "file not found" << endl;
        return;
    }

    temp.open("temp.txt", ios::out);

    int key;
    cout << "enter roll no to modify: ";
    cin >> key;

    int roll;
    string name, division, address, dob, grade;
    float percent;
    bool found = false;

    while (file >> roll >> name >> division >> address >> dob >> percent >> grade) {
        if (roll == key) {
            cout << "record found" << endl;

            cout << "enter new roll: ";
            cin >> roll;
            cout << "enter new name: ";
            cin >> name;
            cout << "enter new division: ";
            cin >> division;
            cout << "enter new address: ";
            cin >> address;
            cout << "enter new dob: ";
            cin >> dob;
            cout << "enter new percent: ";
            cin >> percent;
            cout << "enter new grade: ";
            cin >> grade;

            temp << roll << " " << name << " " << division << " " << address
                 << " " << dob << " " << percent << " " << grade << endl;

            found = true;
        }
        else {
            temp << roll << " " << name << " " << division << " " << address
                 << " " << dob << " " << percent << " " << grade << endl;
        }
    }

    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "record modified" << endl;
    else
        cout << "record not found" << endl;
}
void deleterecord() {
    fstream file, temp;
    file.open("student.txt", ios::in);

    if (!file) {
        cout << "file not found" << endl;
        return;
    }

    temp.open("temp.txt", ios::out);

    int key;
    cout << "enter roll no to delete: ";
    cin >> key;

    int roll;
    string name, division, address, dob, grade;
    float percent;
    bool deleted = false;

    while (file >> roll >> name >> division >> address >> dob >> percent >> grade) {
        if (roll == key) {
            deleted = true;
            continue;
        }
        temp << roll << " " << name << " " << division << " " << address
             << " " << dob << " " << percent << " " << grade << endl;
    }

    file.close();
    temp.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (deleted)
        cout << "record deleted" << endl;
    else
        cout << "record not found" << endl;
}

int main() {
    int ch;

    do {
        cout << "function you want to perform"<<endl;
        cout << "1. create file"<< endl;
        cout << "2. display file"<<endl;
        cout << "3. add new record"<<endl;
        cout << "4. search record"<<endl;
        cout << "5. modify record"<<endl;
        cout << "6. delete record"<<endl;
        cout << "enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                createfile();
                break;

            case 2:
                displayfile();
                break;

            case 3:
                addnewrecords();
                break;

            case 4:
                searchrecord();
                break;

            case 5:
                modifyrecord();
                break;

            case 6:
                deleterecord();
                break;

            default:
                cout << "wrong choice... program stopped";
                return 0; // end program if wrong choice
        }

    } while(ch !=7);

    return 0;
}
