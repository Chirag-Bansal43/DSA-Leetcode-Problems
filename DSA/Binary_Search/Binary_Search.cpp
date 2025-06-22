#include <bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> arr,int key){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(key == arr[mid])
            return mid;
        else if(key > arr[mid])
            s = mid+1;
        else
            e = mid-1;
        
        mid = s + (e-s)/2;
    }
    return -1;
}

// In Optimal Approach we have to independently find the index of first and last occurance of the target element
// T.C = O(2 * logn) , S.C = O(1)
int firstOccurance(vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s+(e-s)/2;
    int first = -1;
    while(s<=e){
        if(target == arr[mid]){
            first = mid;
            e = mid-1;
        }    
        else if(target > arr[mid])
            s = mid+1;
        else
            e = mid-1;
        
        mid = s + (e-s)/2;
    }
    return first;
}

int lastOccurance(vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s+(e-s)/2;
    int last = -1;
    while(s<=e){
        if(target == arr[mid]){
            last = mid;
            s = mid + 1;
        }    
        else if(target > arr[mid])
            s = mid+1;
        else
            e = mid-1;
        
        mid = s + (e-s)/2;
    }
    return last;
}

vector<int> searchRange(vector<int>& arr, int target){
    int first = firstOccurance(arr,target);
    int last = lastOccurance(arr,target);
    return {first,last};
}

//-------------------------------------------------------------------------------------------------------
// Brute Force approach
// T.C = O(2n) , S.C = O(1)
vector<int> searchRange_01(vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s+(e-s)/2;
    int first = -1,last = -1;
    while(s<=e){
        if(target == arr[mid]){
            for(int i = mid;arr[i]==target;i--){
                first = i;
            }
            for(int i = mid;arr[i]==target;i++){
                last = i;
            }
            return {first,last};
        }    
        else if(target > arr[mid])
            s = mid+1;
        else
            e = mid-1;
        
        mid = s + (e-s)/2;
    }
    return {-1,-1};
}


int main(){
    vector<int> odd = {1,3,5,7,9,11};
    vector<int> even = {2,4,6,8,10};
    vector<int> arr = {1,2,4,4,4,4,5,5,6,6,6,7,7};

    int target;
    cout<<"Enter target : ";
    cin>>target;
    
    //cout<<"\nBinary_Search in array : "<<Binary_Search(even,key)<<endl;
    vector<int> ans = searchRange(arr,target);
    cout<<"Range of a target element in the array : "<<ans[0]<<' '<<ans[1]<<endl;

    return 0;
}