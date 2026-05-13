#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* frontNode;
    Node* rearNode;
    int size;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) dequeue();
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        size++;
        cout << value << " added to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) rearNode = nullptr;
        cout << temp->data << " removed from queue.\n";
        delete temp;
        size--;
    }

    void front() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        cout << "Front element is: " << frontNode->data << "\n";
    }

    void rear() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        cout << "Rear element is: " << rearNode->data << "\n";
    }

    bool isEmpty() { return frontNode == nullptr; }

    void display() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        cout << "Queue (front to rear): ";
        Node* current = frontNode;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue queue;
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Display\n6. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.front();
                break;
            case 4:
                queue.rear();
                break;
            case 5:
                queue.display();
                break;
            case 6:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
