#include <bits/stdc++.h>
using namespace std;

// BINARY EXPONENTIATION for calulating mid^n in O(log2 n) time
long long power(long long mid,int n,int m){
    long long result = 1;
    while(n>0){
        //if n == odd 
        if(n%2 == 1){
            result = result * mid;
            n = n - 1;
            if(result > m)  return result;
        }
        else{   // else n == even
            mid = mid*mid;
            n = n / 2;      // mid^n == (mid^2)^(n/2) == (mid^4)^(n/4) ...
            if(mid > m)     return mid;
        }
    }
    // mid^n is stored in result
    return result;
}

// T.C = O(log2 m * log2 n) = O(log2 (m+n)) -> Optimal Solution
int Nth_Root_Of_m(int n, int m) {
    int s = 0, e = m;
    while (s <= e) {    //O(log2 m)
        int mid = s + (e - s) / 2;
        long long midN = power(mid, n, m);  //O(log2 n)

        if (midN == m)
            return mid;
        else if (midN > m)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

/* T.C = O(n * log m) 
# Here Linear multiplication is used to find mid^n ... which takes O(n) time in worst case
int Nth_Root_Of_m(int n,int m){
    int s=1,e=m;
    while(s<=e){
        int mid = s+(e-s)/2;
        long long factor = 1;   // LINEAR MULTIPLICATION for calculating mid^n in O(n) time
        for(int i=0;i<n;i++){   //O(n) -> to calculate mid^n in worst case
            factor = factor * mid;
            if(factor>m)    break;
        }
        if(factor == m)     return mid;
        else if (factor>m)  e=mid-1;
        else    s=mid+1;
    }
    return -1;
}
*/

int main(){
    int n,m;
    cout<<"Enter n and m : ";
    cin>>n>>m;

    cout<<"Nth root of the number m : "<<Nth_Root_Of_m(n,m)<<endl;

    return 0;
}