// Leetcode : 1283

#include <bits/stdc++.h>
using namespace std;

// T.C = O(n * log2 (max[array]) )
int SmallestDivisor(vector<int>& nums,int threshold){
    int n = nums.size();
    // Finding Maximum element in nums
    int maxEle = -1;
    for(int i=0;i<n;i++){   //O(n)
        if(nums[i]>maxEle)    maxEle=nums[i];
    }

    // Binary Search in Search Space [1 - max(array)]  
    int s = 1,e = maxEle;
    int ans = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += ceil( (double) nums[i] / (double) mid);
        }
        if(sum<=threshold){
            ans = mid;
            e = mid - 1;
        }
        else    s=mid+1;
    }
    return ans;
}


int main(){
    vector<int> nums;
    cout<<"Enter size of nums[] : ";
    int n;  cin>>n;
    // Taking input
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    int threshold;
    cout<<"Enter threshold : ";
    cin>>threshold;

    cout<<"Smallest Divisor which generate sum less than or equal to threshold is : "<<SmallestDivisor(nums,threshold)<<endl;
    return 0;
}