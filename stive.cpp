#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stiva este goală!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Stiva este goală!\n";
            return -1;
        }
        return top->data;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stiva este goală!\n";
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice;
    do {
        cout << "\n1. Adaugă element\n";
        cout << "2. Elimină element\n";
        cout << "3. Vizualizează elementul de sus\n";
        cout << "4. Afișează stiva\n";
        cout << "5. Ieșire\n";
        cout << "Alege o opțiune: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Introdu valoarea: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Elementul de sus: " << stack.peek() << endl;
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Ieșire...\n";
                break;
            default:
                cout << "Opțiune invalidă!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

