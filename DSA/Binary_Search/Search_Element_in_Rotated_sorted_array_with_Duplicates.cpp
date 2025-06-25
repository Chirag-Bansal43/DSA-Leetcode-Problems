#include <bits/stdc++.h>
using namespace std;

/* Optimal Solution
T.C = O(log2 n) -> in average case 
    = O(n/2) -> in edge case or worst case
S.C = O(1)
*/
bool search(vector<int>& arr, int target){
    int s = 0;
    int e = arr.size()-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(target == arr[mid])  return true;

        // Edge Case when arr[s] == arr[mid] == arr[e] occurs then we can't Identify which part of array is sorted either left or Right
        // So, we will skip the starting and ending elements untill this condition became not satisfied
        if(arr[mid]==arr[s] && arr[mid]==arr[e]){
            s++ , e--;
            continue;
        }

        // Identify the Sorted Part
        if(arr[s] <= arr[mid]){ // Implies Left Part from (s to mid) is sorted
            if(target>=arr[s] && target<arr[mid]) // If target is in the left part
                e = mid-1; // trim the right part
            else // target not present in left sorted part so trim the left sorted part
                s = mid+1;
        }
        else{   // Left part is not sorted implies Right Part from (mid to n-1) is sorted
            if(target>arr[mid] && target<=arr[e]) // Finding target in Right Sorted part
                s = mid+1; // If it is present in Right sorted part trim down the left part
            else
                e = mid-1; // else trim down the Right sorted part
        }
    }
    return false;
}

int main(){
    vector<int> arr = {7,7,8,8,10,1,2,5,5,7,7}; // with duplicates (average case)
    // Edge Cases : in these cases , programatically we can't say which part of array is sorted
    vector<int> arr1 = {2,2,2,3,2,2,2,2,2}; // -> here right part is sorted
    vector<int> arr2 = {2,2,2,2,2,2,3,2,2}; // -> here left part is sorted
    int target;
    cout<<"Enter target : ";
    cin>>target;

    cout<<"Target is present in array (T/F) : "<<search(arr,target)<<endl;
    return 0;
}