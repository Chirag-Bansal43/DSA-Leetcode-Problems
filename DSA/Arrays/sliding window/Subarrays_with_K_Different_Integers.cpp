#include <bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int>& nums, int k) {
        // finding subarray with at least k different integers
        
        // storing number and its count present in window
        unordered_map<int,int> m;
        
        int start = 0;
        int end = 0;
        int different = 0;

        int AtLeastK = 0;
        int AtLeastKplusOne = 0;

        while(end<nums.size()){
            m[nums[end]]++;
            if(m[nums[end]] == 1)   different++;

            while(different == k){
                AtLeastK += nums.size()-end;
                m[nums[start]]--;
                if(m[nums[start]] == 0) different--;
                start++;
            }

            end++;
        }

        start = 0;
        end = 0;
        different = 0;
        //or use 
        m.clear();
        // for(auto &i:m){ // here i is the reference variable of the pair in map and it changes the original map pairs
        //     i.second = 0;
        // }

        while(end<nums.size()){
            m[nums[end]]++;
            if(m[nums[end]] == 1)   different++;

            while(different == k+1){
                AtLeastKplusOne += nums.size()-end;
                m[nums[start]]--;
                if(m[nums[start]] == 0) different--;
                start++;
            }

            end++;
        }

        return AtLeastK - AtLeastKplusOne;
    }

int main(){
    vector<int> nums = {1,2,1,2,3};
    cout<<subarraysWithKDistinct(nums,2);
    return 0;
}