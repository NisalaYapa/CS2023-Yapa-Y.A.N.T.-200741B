
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value); // create a new node
        newNode->next = top; // link the new node to the previous top node
        top = newNode; // update the top pointer to the new node
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top; // store the current top node in a temporary variable
        top = top->next; // update the top pointer to the next node
        delete temp; // free the memory allocated for the current top node
    }

    bool isEmpty() {
        return (top == NULL); // stack is empty if top pointer is NULL
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data; // return the data of the top node
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Elements in stack:" << endl;
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    cout << "Top element: " << s.stackTop() << endl;
    cout << "Is stack empty? " << s.isEmpty() << endl;

    return 0;
}