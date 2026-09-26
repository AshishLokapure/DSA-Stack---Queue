#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<int>& nums, int n){
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    prefixMax[0] = nums[0];
    for(int i = 1; i < n; i++) prefixMax[i] = max(nums[i], prefixMax[i - 1]);
    suffixMax[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; i--) suffixMax[i] = max(nums[i], suffixMax[i + 1]);

    int ans = 0;

    for(int i = 0; i < n; i++){
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if(leftMax > nums[i] && rightMax > nums[i]){
            ans += min(leftMax, rightMax) - nums[i];
        }
    }
    cout<<ans;
}

void better(vector<int>& nums, int n){
    vector<int> suffixMax(n);

    suffixMax[n - 1] = nums[n - 1];
    for(int i = n - 2; i >= 0; i--) suffixMax[i] = max(nums[i], suffixMax[i + 1]);

    int ans = 0;
    int leftMax = INT_MIN;

    for(int i = 0; i < n; i++){
        leftMax = max(leftMax, nums[i]);
        int rightMax = suffixMax[i];
        if(leftMax > nums[i] && rightMax > nums[i]){
            ans += min(leftMax, rightMax) - nums[i];
        }
    }
    cout<<ans;
}

void optimal1(vector<int>& nums, int n){
    int lmax = 0;
    int rmax = 0;
    int total = 0;
    int l = 0;
    int r = n - 1;
    while(l < r){
        if(nums[l] <= nums[r]){
            if(lmax > nums[l]) total += lmax - nums[l];
            else lmax = nums[l];
            l++;
        } else {
            if(rmax > nums[r]) total += rmax - nums[r];
            else rmax = nums[r];
            r--;
        }
    }
    cout<<total;
}

void optimal2(vector<int>& nums, int n){
    int lmax = 0;
    int rmax = 0;
    int total = 0;
    int l = 0;
    int r = n - 1;
    while(l < r){
        lmax = max(lmax, nums[l]);
        rmax = max(rmax, nums[r]);
        if(lmax < rmax){
            total += (lmax - nums[l]);
            l++;
        } else {
            total += (rmax - nums[r]);
            r--;
        }
    }
    cout<<total;
}


int main(){
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = nums.size();

    cout<<"Nums : ";
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl;

    cout<<"Brute Force : ";
    bruteForce(nums, n);
    cout<<endl;

    cout<<"Better : ";
    better(nums, n);
    cout<<endl;

    cout<<"optimal 1 : ";
    optimal1(nums, n);
    cout<<endl;

    cout<<"optimal 2 : ";
    optimal2(nums, n);
    cout<<endl;
}