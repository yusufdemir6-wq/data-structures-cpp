#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* topNode;
    int size;

public:
    Stack() : topNode(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) pop();
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        size++;
        cout << value << " pushed to stack.\n";
    }

    void pop() {
        if (isEmpty()) { cout << "Stack is empty!\n"; return; }
        Node* temp = topNode;
        topNode = topNode->next;
        cout << temp->data << " popped from stack.\n";
        delete temp;
        size--;
    }

    void peek() {
        if (isEmpty()) { cout << "Stack is empty!\n"; return; }
        cout << "Top element is: " << topNode->data << "\n";
    }

    bool isEmpty() { return topNode == nullptr; }

    void display() {
        if (isEmpty()) { cout << "Stack is empty!\n"; return; }
        cout << "Stack (top to bottom): ";
        Node* current = topNode;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack stack;
    int choice, value;


    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
