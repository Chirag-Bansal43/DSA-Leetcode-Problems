#include <bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int>& arr,int st,int en,int target){ //O(logn)
    int s=st;
    int e=en;
    int mid = s+(e-s)/2;
    int first=-1;
    while(s<=e){
        if(arr[mid]==target){
            first = mid;
            e=mid-1;
        }
        else if(arr[mid]<target)    s=mid+1;
        else    e=mid-1;
        mid=s+(e-s)/2;
    }
    return first;
}

int getPivot(vector<int>& arr){ // O(log n)
    //Note that arr is a rotated sorted array
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0])    s = mid+1;
        else    e = mid;
        mid = s+(e-s)/2;
    }
    return mid;
}

// Optimal solution and more clean 
// T.C = O(2 * logn) , S.C = O(1)
/* Only Limitation of this Code : Not return first occurance of the last element in only increasing sorted array
--> [1,2,3,4,4,4] target = 4  # This code's output is 5 for this (returns the last index for target = last element of only increasing sorted array)
Otherwise, Works Well when the array have all distinct elements
*/
int search(vector<int>& arr, int target) {  
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
- For Finding first occurance of this target element we apply one more condition
If target second last element ke barabar ha in only increasing sorted array then apply B.S from 0 to pivot-1 for finding the first occurance of target else return pivot 
*/
int search_01(vector<int>& arr,int target){
    int pivot = getPivot(arr); // O(log n)
    if(target == arr[pivot]){// In only increasing array the pivot is always points to the last element and If target = last element in only increasing array then below Binary_Search from 0 to pivot-1 won't work
        // That's Why when target==arr[pivot] then always apply Binary_Search from pivot to n-1 (vvv Imp thing) or directly return pivot...
        if(arr.size() != 0 && target == arr[pivot-1]) // If target second last element ke barabar ha in only increasing sorted array then apply B.S from 0 to pivot-1 for finding the first occurance of target else return pivot 
            return Binary_Search(arr,0,pivot-1,target);
        else
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
    vector<int> arr = {7,7,8,9,9,10,1,2,2,3,3,4,5,7};
    vector<int> arr1 = {1,2,3,4};

    int target;
    cout<<"Enter target : ";
    cin>>target;

    cout<<"Pivot index of Rotated Sorted Array : "<<getPivot(arr)<<endl;
    cout<<"Index of First occurance of target element in rotated sorted array : "<<search(arr,target)<<endl;
    return 0;
}