#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

string InfixToPostfix(string s){
    int i = 0, n = s.size();
    string ans = "";
    stack<char> st;
    while(i < n){
        // Ignore spaces
        if(s[i] == ' '){
            i++;
            continue;
        }
        // Operand
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
            ans += ' ';
        }
        // Opening bracket
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // Closing bracket
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                ans += ' ';
                st.pop();
            }
            if(!st.empty()) st.pop();   // Remove '('
        }
        // Operator
        else{
            while (!st.empty() &&
                    (precedence(st.top()) > precedence(s[i]) ||
                    (precedence(st.top()) == precedence(s[i]) && s[i] != '^'))){
                ans += st.top();
                ans += ' ';
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    // Empty remaining stack
    while(!st.empty()){
        ans += st.top();
        ans += ' ';
        st.pop();
    }
    return ans;
}

int main(){
    string s = "A + B * ( C ^ D - E )";
    cout << "Infix : " << s << endl;
    string ans = InfixToPostfix(s);
    cout << "Postfix : " << ans << endl;
    return 0;
}