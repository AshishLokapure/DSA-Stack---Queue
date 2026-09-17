#include<bits/stdc++.h>
using namespace std;

class myStack{
private:
    queue<int> q;

public:

    void push(int ele){
        q.push(ele);
        int s = q.size();
        for(int i = 0; i < s - 1; i++){
            q.push(q.front());
            q.pop();
        }
        cout << ele << " inserted successfully" << endl;
    }

    int pop(){
        if(q.empty()){
            cout << "Stack underflow" << endl;
            return -1;
        }
        int ele = q.front();
        q.pop();
        cout << ele << " deleted successfully" << endl;
        return ele;
    }

    int top(){
        if(q.empty()){
            cout << "Stack underflow" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main(){
    myStack mystack;
    int ch;
    int ele;
    while(true){

        cout << "\n========== STACK MENU ==========" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. IsEmpty" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";

        cin >> ch;

        switch(ch){

            case 1:

                cout << "Enter element: ";
                cin >> ele;

                mystack.push(ele);

                break;


            case 2:

                mystack.pop();

                break;


            case 3:

                cout << "Top element: "
                     << mystack.top() << endl;

                break;


            case 4:

                if(mystack.empty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;

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