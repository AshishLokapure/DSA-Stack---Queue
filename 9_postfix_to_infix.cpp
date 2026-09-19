#include<bits/stdc++.h>
using namespace std;

string PostfixToInfix(string s){
    int i = 0, n = s.size();
    stack<string> st;

    while(i < n){
        if(s[i] == ' ') {
            i++;
            continue;
        }
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        } else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string newTop = '(' + top2 + s[i] + top1 + ')';
            st.push(newTop);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s = "A B - D E + F * /";
    cout<<"Postfix : "<<s<<endl;
    string ans = PostfixToInfix(s);
    cout<<"Infix : "<<ans;
}