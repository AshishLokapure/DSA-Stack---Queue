#include<bits/stdc++.h>
using namespace std;

class ArrayQueue{
private:
    int rearIndex = -1;
    int frontIndex = -1;
    static const int n = 5;
    int q[n];

public : 
    void enqueue(int ele){
        if(rearIndex >= n - 1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(frontIndex == -1) frontIndex++;
        rearIndex++;
        q[rearIndex] = ele;
        cout<<ele<<" inserted successfully"<<endl;
    }
    void dequeue(){
        if(frontIndex == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Deleted element : "<<q[frontIndex]<<endl;
        frontIndex++;
        if(frontIndex > rearIndex) frontIndex = rearIndex = -1;
    }
    int front(){
        if(frontIndex == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return q[frontIndex];
    }
    int size(){
        if(frontIndex == -1) return 0;
        return rearIndex - frontIndex + 1;
    }
    bool isEmpty(){
        return frontIndex == -1;
    }
};

int main() {
    ArrayQueue q;

    int ch;
    int ele;

    while (true) {

        cout << "\n========== QUEUE MENU ==========" << endl;
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
                cout << "Queue size: " << q.size() << endl;
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