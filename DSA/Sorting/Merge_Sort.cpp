#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int low,int mid , int high){
    // Merge two sorted parts of array into complete sorted array

    int left = low; // index or pointer to left sorted part 
    int right = mid+1; // index or pointer to right sorted part
    vector<int> temp;
    while(left<=mid && right<=high){ // Jab tak dono mein se koi part khatam nahi ho jata tab tak loop ko chalana
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& arr,int low,int high){
    // Base Case
    if(low==high){
        return;
    }

    int mid = low+(high-low)/2;  // s+(e-s)/2
    // Two Parts:-
    // [low -> mid] --> left part of array
    // [mid+1 -> high] --> right part of array
    // So, our algo. is simple which says that you have to sort complete array... So, first call mergeSort(low,mid) to sort left part of array and
    // then call mergeSort(mid+1,high) to sort right part of array and then call merge(low,high) function to merge these two sorted parts of array to form a complete sorted array
    mergeSort(arr,low,mid); //--> to sort left part of array
    mergeSort(arr,mid+1,high); //--> to sort right part of array
    merge(arr,low, mid,high); // --> merge left and right sorted parts of array to form a complete sorted array
}

// Print Array
void printArray(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    vector<int> arr = {3,4,1,6,2,5,7};
    printArray(arr);

    mergeSort(arr,0,6);

    printArray(arr);

    return 0;
}