#include<bits/stdc++.h>
using namespace std;

string PrefixToInfix(string s){
    int n = s.size() - 1;
    int i = n; 
    stack<string> st;

    while(i >= 0){
        if(s[i] == ' ') {
            i--;
            continue;
        }
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        } else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string newTop = '(' + top1 + s[i] + top2 + ')';
            st.push(newTop);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s = "* + P Q - M N";
    cout<<"Prefix : "<<s<<endl;
    string ans = PrefixToInfix(s);
    cout<<"Infix : "<<ans; 
}