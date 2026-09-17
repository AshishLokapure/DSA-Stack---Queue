#include<bits/stdc++.h>
using namespace std;

class ArrayCircularQueue{
private :
    int frontIndex = -1;
    int rearIndex = -1;
    static const int size = 5;
    int q[size];
    int currSize = 0;

public :
    void enqueue(int ele){
        if(currSize == size){
            cout<<"Circular Queue Overflow"<<endl;
            return;
        }
        if(currSize == 0) frontIndex = rearIndex = 0;
        else rearIndex = (rearIndex + 1) % size;
        q[rearIndex] = ele;
        cout<<ele<<" Element inserted successfully"<<endl;
        currSize++;
    }
    void dequeue(){
        if(currSize == 0){
            cout<<"Circular Queue is underflow"<<endl;
            return;
        }
        int ele = q[frontIndex];
        if(currSize == 1) {
            frontIndex = rearIndex = -1;
            currSize--;
            cout<<ele<<" deleted successfully"<<endl;
            return;
        }
        cout<<ele<<" deleted successfully"<<endl;
        frontIndex = (frontIndex + 1) % size;
        currSize--;
    }
    int front(){
        if(currSize == 0){
            cout<<"Circular Queue is empty";
            return -1;
        }
        return q[frontIndex];
    }
    int sizeOfCQ(){
        return currSize;
    }
    bool isEmpty(){
        return currSize == 0;
    }
};

int main() {
    ArrayCircularQueue q;

    int ch;
    int ele;

    while (true) {

        cout << "\n========== CIRCULAR QUEUE MENU ==========" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Size" << endl;
        cout << "5. IsEmpty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> ch;

        switch (ch) {

            case 1:
                cout << "Enter element: ";
                cin >> ele;
                q.enqueue(ele);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << "Front element: " << q.front() << endl;
                break;

            case 4:
                cout << "Queue size: " << q.sizeOfCQ() << endl;
                break;

            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
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