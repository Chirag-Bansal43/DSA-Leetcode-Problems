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

// T.C = O(2 * logn) , S.C = O(1)
int search(vector<int>& arr,int target){
    int pivot = getPivot(arr); // O(log n)
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

    int target;
    cout<<"Enter target : ";
    cin>>target;

    cout<<"Pivot index of Rotated Sorted Array : "<<getPivot(arr)<<endl;
    cout<<"Index of First occurance of target element in rotated sorted array : "<<search(arr,target)<<endl;
    return 0;
}