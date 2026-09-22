#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> nums, int n){
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] < nums[i]) {
                ans[i] = nums[j];
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";  
    }
}

void optimal(vector<int> nums, int n){
    vector<int> ans(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= nums[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(nums[i]);
    }

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";  
    }
}

int main(){
    vector<int> nums = {5, 7, 9, 6, 7, 4, 5, 1, 3, 7};
    int n = nums.size();
    cout<<"Array : ";
    for(int i = 0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    cout<<"Next smaller element {Brute force} : ";
    bruteForce(nums, n);
    cout<<endl;

    cout<<"Next smaller element {optimal} : ";
    optimal(nums, n);
    cout<<endl;
}