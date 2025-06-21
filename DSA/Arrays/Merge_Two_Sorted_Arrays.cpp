#include <bits/stdc++.h>
using namespace std;


void Merge_Sorted_Arrays(vector<int>& nums1,vector<int>& nums2,int m,int n){
    // S.C = O(m+n)
    vector<int> merged;
    int i = 0,j=0;
    //T.C = O(m+n) + O(m+n) = O(2*(m+n))
    while(i<m && j<n){ //O(min(m,n))
        if(nums1[i]<=nums2[j]){
            merged.push_back(nums1[i]);
            i++;
        }
        else{
            merged.push_back(nums2[j]);
            j++;
        }
    }

    while(i<m){
        merged.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        merged.push_back(nums2[j]);
        j++;
    }
    
    for(int k=0;k<m+n;k++){ //O(m+n)
        nums1[k] = merged[k];
    }
}


void Input_Array(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
}

void printAns(vector<int>& ans){
    cout<<endl;
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums1;
    vector<int> nums2;
    int m,n;
    cout<<"Enter sizes of nums1 & nums2 : ";
    cin>>m>>n;

    // Taking input for nums1 & nums2 vector
    cout<<"Enter elements for nums1 ->"<<endl;
    Input_Array(nums1,m);
    // Adding n zeros at the end of nums1 so that size of nums1 is m+n
    for(int i=0;i<n;i++){
        nums1.push_back(0);
    }
    
    cout<<"Enter elements for nums2 ->"<<endl;
    Input_Array(nums2,n);

    // Merging both arrays in nums1
    Merge_Sorted_Arrays(nums1,nums2,m,n);

    //Print Array nums1
    printAns(nums1);

    return 0;
}