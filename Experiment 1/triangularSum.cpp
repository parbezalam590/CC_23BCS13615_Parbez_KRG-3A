#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    
    while(nums.size() > 1) {
        vector<int> temp;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            temp.push_back((nums[i] + nums[i+1]) % 10);
        }
        
        nums = temp; // update array
    }
    
    return nums[0];
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << triangularSum(nums);
    return 0;
}