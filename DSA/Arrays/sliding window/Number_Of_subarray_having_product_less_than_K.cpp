#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    
    long long product = 1LL;
    int start = 0;
    int end = 0;
    int total = 0;
    
    while(end<nums.size()){
        product *= nums[end];
        while(product >= k && start<=end){
            product /= nums[start];
            start++;
        }
        
        total += end-start + 1;
        end++;
    }

    return total;
}

int main(){
    vector<int> nums = {2,5,10,8,100,1000,5,15};
    cout << numSubarrayProductLessThanK(nums,999);

    return 0;
}