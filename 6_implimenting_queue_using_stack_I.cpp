#include<bits/stdc++.h>
using namespace std;

class myQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void enqueue(int ele){
        // Move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        // Insert new element
        s1.push(ele);
        // Move everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        cout << ele << " inserted successfully" << endl;
    }

    int dequeue(){
        if(s1.empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ele = s1.top();
        s1.pop();
        cout << ele << " deleted successfully" << endl;
        return ele;
    }

    int front(){
        if(s1.empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};


int main(){

    myQueue myqueue;
    int ch;
    int ele;
    while(true){
        cout << "\n========== QUEUE MENU ==========" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. IsEmpty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Enter element: ";
                cin >> ele;
                myqueue.enqueue(ele);
                break;

            case 2:
                myqueue.dequeue();
                break;

            case 3:
                cout << "Front element: "<< myqueue.front() << endl;
                break;

            case 4:
                if(myqueue.empty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}