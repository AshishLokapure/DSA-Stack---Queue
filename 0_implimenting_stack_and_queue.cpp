#include<bits/stdc++.h>
using namespace std;

void implimentingStack(){
    stack<int> st;
    st.push(1);
    st.push(3);
    st.push(5);
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.top()<<endl;
    st.push(10);
    cout<<st.top()<<endl;
    cout<<st.size();
}

void implimentingQueue(){
    queue<int> qe;
    qe.push(1);
    qe.push(3);
    qe.push(5); 
    qe.push(7);
    qe.pop();
    qe.pop();
    cout<<qe.front()<<endl;
    cout<<qe.back()<<endl;
    qe.push(10);
    cout<<qe.front()<<endl;
    cout<<qe.size();
}

int main(){
    cout<<"Stack : "<<endl;
    implimentingStack();
    cout<<endl;
    cout<<"Queue : "<<endl;
    implimentingQueue();
}