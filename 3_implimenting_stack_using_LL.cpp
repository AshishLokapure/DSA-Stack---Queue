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

class LLStack{
private :
    Node* top;
    int size = 0;
public : 
    void push(int ele){
        Node* temp = new Node(ele);
        temp->next = top;
        top = temp;
        size++;
    }
    void pop(){
        if(top == NULL){
            cout<<"Stack underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete(temp);
        size--;
    }
    int topElement(){
        if(top == NULL){
            cout<<"Stack is empty";
            return -1;
        }
        return top->data;
    }
    int sizeOfLLS(){
        return size;
    }
    bool isEmpty(){
        return top == NULL;
    }
};

int main() {
    LLStack llst;

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
                llst.push(ele);
                break;

            case 2:
                llst.pop();
                break;

            case 3:
                cout << "Top element: " << llst.topElement() << endl;
                break;

            case 4:
                cout << "Stack size: " << llst.sizeOfLLS() << endl;
                break;

            case 5:
                if (llst.isEmpty())
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