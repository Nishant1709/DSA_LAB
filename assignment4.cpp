#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

// Operator Check
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

//  Precedence 
int precedence(char c) {
    if (c == '^') 
    {
        return 3;
    }
    else if (c == '*' || c == '/') {
    return 2;
    }
    else if (c == '+' || c == '-'){
         return 1;
    }
    else 
    {
           return -1;
    }
}

//  Infix to Postfix 
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isalnum(ch)) postfix += ch;
        else if (ch == '(') st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(ch)) {
            while (!st.empty() && precedence(st.top()) >= precedence(ch) && ch != '^') {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

//  Evaluate Postfix
int evaluatePostfix(string postfix) {
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isdigit(ch)) st.push(ch - '0');
        else if (isOperator(ch)) {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(op1 + op2);
                 break;
                case '-': st.push(op1 - op2);
                 break;
                case '*': st.push(op1 * op2);
                 break;
                case '/': st.push(op1 / op2);
                 break;
                case '^': st.push(pow(op1, op2));
                 break;
            }
        }
    }
    return st.top();
}

//  Infix to Prefix 
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

//  Evaluate Prefix 
int evaluatePrefix(string prefix) {
    stack<int> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch)) st.push(ch - '0');
        else if (isOperator(ch)) {
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(op1 + op2); 
                break;
                case '-': st.push(op1 - op2); 
                break;
                case '*': st.push(op1 * op2);
                 break;
                case '/': st.push(op1 / op2); 
                break;
                case '^': st.push(pow(op1, op2)); 
                break;
            }
        }
    }
    return st.top();
}

//  Main 
int main() {
    string infix, postfix, prefix;
    int choice;

    cout << "1. Infix to Postfix" << endl;
    cout << "2. Evaluate Postfix" << endl;
    cout << "3. Infix to Prefix" << endl;
    cout << "4. Evaluate Prefix" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter expression: ";
    if (choice == 1 || choice == 3) cin >> infix;
    else cin >> postfix;

    switch (choice) {
        case 1:
            cout << "Postfix: " << infixToPostfix(infix) << endl;
            break;

        case 2:
            cout << "Value: " << evaluatePostfix(postfix) << endl;
            break;

        case 3:
            cout << "Prefix: " << infixToPrefix(infix) << endl;
            break;

        case 4:
            cout << "Value: " << evaluatePrefix(postfix) << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    return 0;
}
