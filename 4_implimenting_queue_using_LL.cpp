#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    int data;
    Node* next;

    public : 
    Node(int data1){
        data = data1;
        next = NULL;
    }
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

class LLQueue{
private :
    Node* front = NULL;
    Node* rear = NULL;
    int size = 0;
public :
    void push(int ele){
        Node* newNode = new Node(ele);
        if(front == NULL){
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = rear->next;
        }
        cout<<ele<<" inserted Successfully"<<endl;
        size++;
    }
    void pop(){
        if(front == NULL){
            cout<<"Stack underflow"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        cout<<temp->data<<" deleted successfully"<<endl;
        delete(temp);
        if(front == NULL) rear = NULL;
        size--;
    }
    int top(){
        if(front == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    int sizeOfLLQ(){
        return size;
    }
    bool isEmpty(){
        return front == NULL;
    }
};

int main() {
    LLQueue llq;

    int ch;
    int ele;

    while (true) {

        cout << "\n========== QUEUE MENU ==========" << endl;
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
                llq.push(ele);
                break;

            case 2:
                llq.pop();
                break;

            case 3:
                cout << "Top element: " << llq.top() << endl;
                break;

            case 4:
                cout << "queue size: " << llq.sizeOfLLQ() << endl;
                break;

            case 5:
                if (llq.isEmpty())
                    cout << "queue is empty." << endl;
                else
                    cout << "queue is not empty." << endl;
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