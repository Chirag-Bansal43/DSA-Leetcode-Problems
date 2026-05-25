#include <bits/stdc++.h>
using namespace std;

// Application of Merge Sort in finding no. of inversions in an array

/* Finding No. Of Inversions in an array
    Two index (i,j) is said to be inversion index if:
    --> i<j and arr[i] > arr[j]

    // T.C = O(n* logn) , S.C = O(n)
*/


long long merge(vector<long long>& arr,int low,int mid, int high){
    //[low -> mid] --> left sorted part
    //[mid+1 -> high] --> right sorted part
    int cnt=0;
    vector<long long> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(arr[right] < arr[left]){
            cnt += mid-left+1;    // ---------> only this line gets added in merge sort algorithm code
            temp.push_back(arr[right]);
            right++;
        }
        else{
            temp.push_back(arr[left]);
            left++;
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
    // copy temp array into main array
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

long long solve(vector<long long>& arr,int low,int high){
    // Base case
    if(low == high) return 0;

    int cnt = 0;
    int mid = low+(high-low)/2;
    int cnt1 = solve(arr,low,mid);
    int cnt2 = solve(arr,mid+1,high);
    cnt = merge(arr,low,mid,high);
    return cnt1 + cnt2 + cnt;

}

long long getInversions(long long *arr, int n){
    // Make a copy of input array so that input array not gets changed
    vector<long long> copyArr;
    for(int i=0;i<n;i++)    copyArr.push_back(arr[i]);

    return solve(copyArr,0,n-1);
}

int main(){
    
    long long arr[7] = {11,20,7,2,8,5,1}; // ans(total no of inversions for this array) = 17
    cout<<"No. of Inversions : "<<getInversions(arr,7);

    return 0;
}