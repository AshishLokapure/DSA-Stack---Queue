#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
private:
    int topIndex = -1;
    static const int n = 10;
    int st[n];

public:
    void push(int ele) {
        if (topIndex >= n - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        st[++topIndex] = ele;
        cout << ele << " pushed into stack." << endl;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << st[topIndex] << " popped from stack." << endl;
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return st[topIndex];
    }

    int size() {
        return topIndex + 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    ArrayStack arrSt;

    int ch;
    int ele;

    while (true) {

        cout << "\n========== STACK MENU ==========" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Size" << endl;
        cout << "5. IsEmpty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> ch;

        switch (ch) {

            case 1:
                cout << "Enter element: ";
                cin >> ele;
                arrSt.push(ele);
                break;

            case 2:
                arrSt.pop();
                break;

            case 3:
                cout << "Top element: " << arrSt.top() << endl;
                break;

            case 4:
                cout << "Stack size: " << arrSt.size() << endl;
                break;

            case 5:
                if (arrSt.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}