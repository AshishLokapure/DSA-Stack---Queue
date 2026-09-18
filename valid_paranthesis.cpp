#include<bits/stdc++.h>
using namespace std;

bool validParanthesis(string s){
    stack<int> st;
    for(int i = 0; i < s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        } else if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')){
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    return st.empty();
}

int main(){
    string s = "()[{[]}()]";
    cout<<"string : "<<s<<endl;
    cout<<"Valid Patanthesis : "<<validParanthesis(s);
}