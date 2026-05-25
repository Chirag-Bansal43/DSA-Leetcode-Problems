#include <bits/stdc++.h>
using namespace std;

int subarrayDivByK(vector<int>& nums,int k){
    unordered_map<int,int> PrefSumRem_Count; 
    PrefSumRem_Count[0] = 1;
    int Prefix_Sum = 0;
    int Prefix_Sum_remai = 0; // Prefix_Sum_remainder
    int total = 0;
    for(int i=0; i<nums.size(); i++){
        Prefix_Sum += nums[i];
        Prefix_Sum_remai = Prefix_Sum % k;

        if(Prefix_Sum_remai < 0){
            Prefix_Sum_remai += k;
        }

        if(PrefSumRem_Count.find(Prefix_Sum_remai) != PrefSumRem_Count.end()){
            total += PrefSumRem_Count[Prefix_Sum_remai];
        }

        PrefSumRem_Count[Prefix_Sum_remai]++;
    }

    return total;

}

int main(){
    vector<int> nums = {2,3,-8,-3,11,4,8,6,9,4};
    cout<< subarrayDivByK(nums,7);
    return 0;
}