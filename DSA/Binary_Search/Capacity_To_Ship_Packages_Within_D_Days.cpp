// Leetcode : 1011

#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int>& weights,int mid,int n){
    int sum = 0, days_to_transfer=1;
    for(int i=0;i<n;i++){
        sum += weights[i];
        if(sum>mid){
            days_to_transfer++;
            sum = weights[i];
        }
    }
    return days_to_transfer;
}

// T.C = O(n * log (max(array) - sum(array) + 1) )
int shipWithinDays(vector<int>& weights, int days){
    int n = weights.size();
    // Finding Maximum element in weights and also find sum of all weights
    int maxEle = -1, maxSum = 0;
    for(int i=0;i<n;i++){   //O(n)
        if(weights[i]>maxEle)    maxEle=weights[i];
        maxSum += weights[i];
    }

    // Apply Binary Search [max(array) - sum(array)] ...
    int s = maxEle,e = maxSum;
    while(s<=e){
        int mid= s+(e-s)/2;
        int days_to_Transfer = findDays(weights,mid,n);
        if(days_to_Transfer<=days)  e = mid-1;
        else    s = mid+1;
    }
    return s;
}


int main(){
    vector<int> weights;
    cout<<"Enter size of weights[] : ";
    int n;  cin>>n;
    // Taking input
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        weights.push_back(temp);
    }

    int days;
    cout<<"Enter days : ";
    cin>>days;

    cout<<"Minimum Capacity of Ship so that it can transfer all weights in "<<days<<" days is : "<<shipWithinDays(weights,days)<<endl;
    return 0;
}