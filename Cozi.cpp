#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Coada este goală!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Coada este goală!\n";
            return -1;
        }
        return front->data;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Coada este goală!\n";
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice;
    do {
        cout << "\n1. Adaugă element\n";
        cout << "2. Elimină element\n";
        cout << "3. Vizualizează elementul din față\n";
        cout << "4. Afișează coada\n";
        cout << "5. Ieșire\n";
        cout << "Alege o opțiune: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Introdu valoarea: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Elementul din față: " << queue.peek() << endl;
                break;
            case 4:
                queue.display();
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
