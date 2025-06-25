#include <bits/stdc++.h>
using namespace std;
/* Leetcode 33. Search in Rotated Sorted Array 
Question is to return index of the target element in Rotated Sorted Array with no duplicate elements*/

/* Method - 1 : solving this problem without using pivot
Step1 : Identify Sorted part 
There are two parts one is left from (s to mid) and other is right from (mid to e)
If arr[s] <= arr[mid] -> that means left part is sorted 
And if arr[mid] <= arr[e] -> that means Right part is sorted
 - Note that one of the part must be sorted either left or right so, if left part is not sorted then right part must be sorted

Step2 : After identifying sorted part you check Does target is present in that sorted part or not
If the target is present in sorted part trim down the other part and find the target in sorted part 
and if it not present in sorted part trim down the sorted part and find the target in the other part using same procedure
*/
// Optimal solution 
// T.C = O(log2 n) , S.C = O(1)
int search(vector<int>& arr, int target){
    int s = 0;
    int e = arr.size()-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(target == arr[mid])  return mid;

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
    return -1;
}


// Method - 2 : solving this problem using pivot
int Binary_Search(vector<int>& arr,int st,int en,int target){ //O(logn)
    int s=st;
    int e=en;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target)    s=mid+1;
        else    e=mid-1;
        mid=s+(e-s)/2;
    }
    return -1;
}

int getPivot(vector<int>& arr){ // O(log n)
    // Note that Pivot can only be found when we have all unique elements in rotated sorted array
    // For Duplicates in Rotated sorted array we can't find Pivot
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0])    s = mid+1;
        else    e = mid;
        mid = s+(e-s)/2;
    }
    return s;
}

// Optimal solution and more clean 
// T.C = O(2 * logn) , S.C = O(1)
int search_02(vector<int>& arr, int target) {  
    int pivot = getPivot(arr); // O(log n)
    int n = arr.size();
    if(target>=arr[pivot] && target<=arr[n-1]){ // First check the second line in graph of rotated sorted array that if  arr[pivot]<=target<=arr[n-1] -> then the target is present in second line so, apply binary search from pivot to n-1
        return Binary_Search(arr,pivot,n-1,target);// This will cover the edge cases when array is only increasing array
    }
    else{
        return Binary_Search(arr,0,pivot-1,target);
    }
}

/* Optimal but it is so Messy and chances of doing mistake (i.e missing edge casses) is very high
// T.C = O(2 * logn) , S.C = O(1)
Whenever Rotation of array = 0 (means we have only increasing array) -> In this case Pivot is always points to last element
and If our target is equal to the last element of only increasing array then Binary_Search from 0 to pivot-1 won't find the target element
** Like in examples->
--> [1,2,3,4] , target = 4
--> [1] , target = 1
In both case our code fails because both are only increasing arrays so, pivot == n-1 and our target is also the last element of only increasing array which is >= arr[0] so, from our previous logic it will apply Binary_Search from 0 to pivot-1 but out target is at pivot so that's why this logic won't work

So, We make a general idea that whenever our target == arr[pivot] -> directly return pivot or you can also apply Binary_Search from pivot to n-1... Both will work  (vvvvvvvv Imp)

- For Duplicate elements we can't return index of the target using Binary Search. We can only return true if it is in the array otherwise false
For returning index we need to apply Linear Search (Binary Search won't work)
*/
int search_01(vector<int>& arr,int target){
    int pivot = getPivot(arr); // O(log n)
    if(target == arr[pivot]){// In only increasing array the pivot is always points to the last element and If target == last element in only increasing array then below Binary_Search from 0 to pivot-1 won't work
        // That's Why when target==arr[pivot] then always apply Binary_Search from pivot to n-1 (vvv Imp thing) or directly return pivot...
            return pivot;
    }
    if(target>=arr[0]){
        return Binary_Search(arr,0,pivot-1,target); // O(log n)
    }
    else{
        return Binary_Search(arr,pivot,arr.size()-1,target); // O(log n)
    }
}

int main(){
    // Rotated Sorted Array
    vector<int> arr = {7,8,10,1,2,3,4}; // without duplicates
    vector<int> arr1 = {1,2,3,4}; // only increasing array

    int target;
    cout<<"Enter target : ";
    cin>>target;

    //cout<<"Pivot index of Rotated Sorted Array : "<<getPivot(arr)<<endl;
    cout<<"Index of target element in rotated sorted array : "<<search(arr,target)<<endl;
    return 0;
}