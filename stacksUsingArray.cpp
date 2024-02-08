#include <iostream>

using namespace std;

class TwoStacks {
private:
    int* arr;
    int capacity;
    int top1;
    int top2;

public:
    TwoStacks(int size) {
        capacity = size;
        arr = new int[capacity];
        top1 = -1;
        top2 = capacity;
    }

    ~TwoStacks() {
        delete[] arr;
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == capacity;
    }

    bool isFull() {
        return top1 + 1 == top2;
    }

    void push1(int value) {
        if (isFull() || top1 + 1 == top2) {
            cout << "Error: Stack 1 is full!" << endl;
            return;
        }
        arr[++top1] = value;
    }

    void push2(int value) {
        if (isFull() || top2 - 1 == top1 || top2 == capacity / 2) {
            cout << "Error: Stack 2 is full!" << endl;
            return;
        }
        arr[--top2] = value;
    }

    int pop1() {
        if (isEmpty1()) {
            cout << "Error: Stack 1 is empty!" << endl;
            return -1;
        }
        return arr[top1--];
    }

    int pop2() {
        if (isEmpty2()) {
            cout << "Error: Stack 2 is empty!" << endl;
            return -1;
        }
        return arr[top2++];
    }
};

int main() {
    int capacity;
    cout << "Enter the total capacity of the two stacks: ";
    cin >> capacity;

    TwoStacks ts(capacity);

    int choice;
    int value;
    while (true) {
        cout << "\n1. Push to stack 1\n2. Push to stack 2\n3. Pop from stack 1\n4. Pop from stack 2\n5. Quit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push onto stack 1: ";
                cin >> value;
                ts.push1(value);
                break;
            case 2:
                cout << "Enter value to push onto stack 2: ";
                cin >> value;
                ts.push2(value);
                break;
            case 3:
                cout << "Popping from stack 1: " << ts.pop1() << endl;
                break;
            case 4:
                cout << "Popping from stack 2: " << ts.pop2() << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}

