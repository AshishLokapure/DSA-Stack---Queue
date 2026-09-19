#include<bits/stdc++.h>
using namespace std;

string PrefixToPostfix(string s){
    int n = s.size() - 1, i = n;
    stack<string> st;

    while(i >= 0){
        if(s[i] == ' '){
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
            st.push(top1 + top2 + s[i]);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s = "/ - A B * + D E F";
    cout<<"Prefix : "<<s<<endl;
    string ans = PrefixToPostfix(s);
    cout<<"Postfix : "<<ans<<endl;
}