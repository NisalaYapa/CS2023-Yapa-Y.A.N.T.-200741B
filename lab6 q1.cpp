#include <iostream>
using namespace std;

#define MAX_SIZE 100 // maximum size of the stack

class Stack {
    int arr[MAX_SIZE]; // array to store the elements of the stack
    int top; // index of the top element of the stack

public:
    Stack() {
        top = -1; // initialize top index to -1 (stack is empty)
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) { // check if stack is full
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value; // increment top index and insert element
    }

    void pop() {
        if (top < 0) { // check if stack is empty
            cout << "Stack Underflow\n";
            return;
        }
        top--; // decrement top index to remove element
    }

    bool isEmpty() {
        return (top < 0); // stack is empty if top index is less than 0
    }

    bool isFull() {
        return (top >= MAX_SIZE - 1); // stack is full if top index is equal to or greater than MAX_SIZE - 1
    }

    int topElement() {
        if (top < 0) { // check if stack is empty
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top]; // return the top element of the stack
    }

    void display() {
        if (top < 0) { // check if stack is empty
            cout << "Stack is empty\n";
            return;
        }
        cout << "Elements in stack:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << "\n"; // print the elements in the stack from top to bottom
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

    cout << "Top element: " << s.topElement() << "\n";
    cout << "Is stack empty? " << s.isEmpty() << "\n";
    cout << "Is stack full? " << s.isFull() << "\n";

    return 0;
}
