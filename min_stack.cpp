#include<bits/stdc++.h>
using namespace std;

class bruteForceMinStack{
private:
    stack<pair<int, int>> st;
public:
    void push(int ele){
        if(st.empty()) st.push({ele, ele});
        else st.push({ele, min(ele, st.top().second)});
        cout << ele << " inserted successfully" << endl;
    }

    int pop(){
        if(st.empty()){
            cout << "Stack underflow" << endl;
            return -1;
        }
        int ele = st.top().first;
        st.pop();
        cout << ele << " deleted successfully" << endl;
        return ele;
    }

    int top(){
        if(st.empty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return st.top().first;
    }

    int getMin(){
        if(st.empty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return st.top().second;
    }

    bool empty(){
        return st.empty();
    }
};

int main(){
    bruteForceMinStack st;
    int ch;
    int ele;
    while(true){
        cout << "\n========== MIN STACK MENU ==========" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Get Minimum" << endl;
        cout << "5. IsEmpty" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch){
            case 1:
                cout << "Enter element: ";
                cin >> ele;
                st.push(ele);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                cout << "Top element: " << st.top() << endl;
                break;

            case 4:
                cout << "Minimum element: "  << st.getMin() << endl;
                break;

            case 5:
                if(st.empty()) cout << "Stack is empty." << endl;
                else cout << "Stack is not empty." << endl;
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