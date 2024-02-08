```
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* front;
    Node* last;

public:
    CircularLinkedList() : front(nullptr), last(nullptr) {}

    void reverse() {
        if (front == nullptr || front->next == nullptr) {
            return;
        }

        Node* prev = last;
        Node* current = front;
        Node* nextNode;

        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != front);

        front = prev;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (front == nullptr) {
            front = newNode;
            last = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = front;
            front = newNode;
            last->next = newNode;
        }
    }

    void insertAfter(int position, int val) {
        if (front == nullptr) {
            cout << "List is empty. Cannot perform insertion." << endl;
            return;
        }

        Node* newNode = new Node(val);
        Node* current = front;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
            if (current == front) {
                cout << "Invalid position." << endl;
                delete newNode;
                return;
            }
        }

        newNode->next = current->next;
        current->next = newNode;
        if (current == last) {
            last = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (front == nullptr) {
            front = newNode;
            last = newNode;
            newNode->next = newNode;
        } else {
            last->next = newNode;
            last = newNode;
            last->next = front;
        }
    }

    void deleteAfter(int position) {
        if (front == nullptr) {
            cout << "List is empty. Cannot perform deletion." << endl;
            return;
        }

        Node* current = front;
        for (int i = 0; i < position; ++i) {
            current = current->next;
            if (current == front) {
                cout << "Invalid position." << endl;
                return;
            }
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        if (current->next == front) {
            last = current;
        }
    }

    void deleteLast() {
        if (front == nullptr) {
            cout << "List is empty. Cannot perform deletion." << endl;
            return;
        }

        if (front == last) {
            delete front;
            front = nullptr;
            last = nullptr;
            return;
        }

        Node* current = front;
        while (current->next != last) {
            current = current->next;
        }
        current->next = front;
        delete last;
        last = current;
    }

    void printList() {
        if (front == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = front;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != front);
        cout << " (Circular)" << endl;
    }
};

int main() {
    CircularLinkedList list;

    int choice;
    cout << "Enter choice of operation:" << endl;
    cout << "1. Insert at Beginning" << endl;
    cout << "2. Insert After Position" << endl;
    cout << "3. Insert at End" << endl;
    cout << "4. Delete After Position" << endl;
    cout << "5. Delete Last" << endl;
    cout << "6. Reverse List" << endl;
    cout << "7. Print List" << endl;
    cout << "0. Exit" << endl;

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            }
            case 2: {
                int position, val;
                cout << "Enter position after which to insert: ";
                cin >> position;
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAfter(position, val);
                break;
            }
            case 3: {
                int val;
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            }
            case 4: {
                int position;
                cout << "Enter position after which to delete: ";
                cin >> position;
                list.deleteAfter(position);
                break;
            }
            case 5:
                list.deleteLast();
                break;
            case 6:
                list.reverse();
                break;
            case 7:
                list.printList();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
```
![image](https://github.com/jsamiksha1/ADSA-lab-/assets/101424133/576b97f8-1da6-4a10-bafe-a631224743db)

