// Leetcode : 1539
// fxnName_001 -> use this name when none of your solution matches with striver's solutions and the solution given by striver are best...

#include <bits/stdc++.h>
using namespace std;

// Using Binary Search -> Most Optimal solution by striver
// T.C = O(log n) , S.C = O(1)
/* 
Iss question mein ek bahut sundar technique hai i.e of "ideal array" 
for eg:- 
>>>Ideal array of [2,3,4,7,11] is [1,2,3,4,5]
>>> If we subtract corresponding index element of given array and ideal array => we get "no. of missing elements before that element" in the given array
like No. of Missing elements before 7 => 7-(corresponding index's element of ideal array) = 7-4 = 3 | So, there are three missing elements that are 1,5,6 before 7;
We can find "corresponding index's element of ideal array" is equal to (index + 1) , where index of the particular element in the given array

That How the formula of finding -> No. of Missing elements before ith element of the array = arr[i] - (i+1) = (arr[i] - i - 1) ; // vvvImp

For My sake of clarity I say "No. of Missing elements before mid" as "cnt of mid"... It is not actually count of mid but only used for the sake of convenience
*/
int findKthPositive_003(vector<int>& arr, int k){
    int n = arr.size();
    // arr[n-1]-n => No. of missing elements before the last element
    // return => arr[n-1] + (k - {cnt of last element} );
    // return => arr[n-1] + (k - {arr[n-1] - (n-1+1)}) => k+n;
    if(k> arr[n-1]-n)   return k+n;

    // Applying Binary Search
    int s = 0,e = n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        // cnt of mid (No. of Missing elements before mid) = arr[mid] - (mid+1) => arr[mid]-mid-1
        if((arr[mid]-mid-1) < k){
            // This means our missing element is in the right half so,
            s = mid+1;
        }
        else{   // That is (cnt of mid >= k) that means our missing element is in the left part so, trim the right part
            e = mid-1;
        }
    }
    // At the end of binary search => our missing element is present after e and before s 
    // So, for returning our missing element we have to add something to arr[e]...
    // Therefore, return arr[e]+ (k - cnt of e) => arr[e]+(k - (arr[e]-e-1)) => e+1+k; -> Here cnt of e = No. of Missing elements before e
    
    return e + 1 + k; // or you can return (s + k) also as (e + 1 == s) after BS
    // if our k is less than the first element of array then after BS e becomes -1 -> you can see it by doing dry run... So, it will then return k; which is correct... 
}



// Perfect and clean Better Solution with T.C = O(n)
// T.C = O(n) , S.C = O(1)
int findKthPositive_001(vector<int>& arr, int k){
    int n = arr.size();
    // arr[n-1]-n => No. of missing elements before the last element
    // return => arr[n-1] + (k - {arr[n-1] - (n-1+1)}) => k+n 
    if(k> arr[n-1]-n)   return k+n;

    // No. of missing elements before the ith element => arr[i]-i-1
    // return => arr[i-1] + (k - {arr[i-1] - (i-1+1)}) => k+i 
    for(int i=0;i<n;i++){
        if(arr[i]-i-1 >= k) return k+i;
    }
    return -1;
}

// Perfect and clean Better Solution with T.C = O(n) by striver
// T.C = O(n) , S.C = O(1)
/*
Theory:-
Something Different and out of the box Approach given by striver
If no element is present in array then our answer(i.e Kth missing number) is equal to k;
In this we assume that k is our answer and if we found any element less than or equal to k in array we have to eliminate that element by moving k to k++ | So that our answer(i.e Kth misiing integer) remains equal to k...
In this if our element of array is less than or equal to k then we can't take that element so, our required kth element is one step ahead so, we increase k to k++; and so on...
And when our element of array is greater than k  we stops because we only have to find the answer(Kth missing integer) which is less than this element...| and now, our k will become our required kth Missing number 
So, we will simply return k;

*/
int findKthPositive_002(vector<int>& arr, int k) {
    for(int i=0;i<arr.size();i++){
        if(arr[i] <= k)  k++;
        else    break;
    }
    return k;
}


// Below are Brute Force Solutions having different complexities are all written by me 
// I will say they are "Not Good Solutions"

bool Binary_Search_In_Arr(vector<int>& arr,int mid,int n){
    int s = 0,e = n-1;
    while(s<=e){
        int midArr = s+(e-s)/2;
        if(mid<arr[midArr])  e = midArr-1;
        else if(mid>arr[midArr]) s = midArr+1;
        else    return true;
    }
    return false;
}

// So, Basically If mid is a missing element in the array then we are finding that mid konsawa Missing Element hai... and If mid not a Missing Element(i.e it is element of array) then we are finding No. of Missing Elements present before mid(i.e mid se phele kitne missing element aa chuke hai)
int Konsawa_Missing_Element_hai(vector<int>& arr,int mid,int n){
    // Edge case -> first ele of array
    if(mid<arr[0])  return mid;
    else if (mid == arr[0]) return mid-1;

    int cnt = arr[0] - 1;
    for(int i=1;i<n;i++){
        if(mid > arr[i])
            cnt += (arr[i] - arr[i-1] - 1);
        else if(mid < arr[i]){
            cnt += (mid - arr[i-1]);
            return cnt;
        }
        else{
            cnt += (arr[i] - arr[i-1] - 1);
            return cnt;
        }
    }
    return -1;
}

// This Solution written by me uses Binary Search
// T.C = O( log2(maxEle) * ( n + log2 n) ) => O( n* log2(maxEle) + log2(n+maxEle) )
int findKthPositive_02(vector<int>& arr, int k){
    int lastEle = arr.back();
    int n = arr.size();
    int MissingInArr = lastEle - n;
    // Kth Missing element is present outside the range of array
    if(k > MissingInArr)    return lastEle + (k-MissingInArr);
    
    // Apply Binary Search [1 - arr.back()]
    int s = 1,e = lastEle;
    while(s<=e){
        int mid = s+(e-s)/2;
        // Let mid be Mth missing Element or if mid is present in array then we return "No. of Missing Elements present before mid" in the array
        int M = Konsawa_Missing_Element_hai(arr,mid,n); //T.C1 = O(n)
        
        // mid is the element of Array
        if(Binary_Search_In_Arr(arr,mid,n)){    // T.C2 = O(log2 n)
            if(k<=M)    e=mid-1;
            else    s=mid+1;
        }
        else{   // mid is Not the element of Array (that mean's mid is a missing element in array)
            if(k<M) e=mid-1;
            else if(k>M) s=mid+1;
            else    return mid;
        }
    }
    return -1;
}

// S.C = O(k) , T.C = O(Kth missing element) when K <= No. of missing ele in the array ; for K>MissingInArr => T.C=O(1)
// Time Complexity doesn't depend on size of array and maxElement of array... It depends on the value of Kth Missing Element in the range from [1 to maxEleOfArr]
// Let say Kth missing element = 10 then T.C = O(10)
int findKthPositive_01(vector<int>& arr, int k){
    int lastEle = arr.back();
    int n = arr.size();
    int MissingInArr = lastEle - n;
    // Kth Missing element is present outside the range of array
    if(k > MissingInArr)    return lastEle + (k-MissingInArr);
    
    vector<int> missing;
    int num = 1, cnt = 0;
    for(int i=0;i<n;i++){
        while(num != arr[i]){
            missing.push_back(num);
            num++; cnt++;
            if(cnt == k)    return missing.back();
        }
        num++;
    }
    return -1;
}

int main(){
    vector<int> arr;
    cout<<"Enter size of arr[] : ";
    int n;  cin>>n;
    // Taking input
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int k;
    cout<<"Enter k : ";
    cin>>k;

    cout<<"Kth Missing Number is : "<<findKthPositive_003(arr,k)<<endl;
    return 0;
}