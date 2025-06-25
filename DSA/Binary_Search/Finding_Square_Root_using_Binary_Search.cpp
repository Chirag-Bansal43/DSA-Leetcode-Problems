#include <bits/stdc++.h>
using namespace std;

int Integral_Part_of_square_root(int n){
    // Applying Binary Search from 0 to n
    int s = 0,e = n;
    int ans;
    while(s<=e){
        int mid = s+(e-s)/2;
        long long square = 1LL*mid*mid;
        if(square == n) return mid;
        else if(square>n)   e=mid-1;
        else{
            ans=mid;
            s = mid+1;
        }   
    }
    return ans;
}

// T.C = O(log n) + O(10*precesion) ~ O(log n) , S.C = O(1)
double Sqrt(int n,int precesion){
    double ans = (double) Integral_Part_of_square_root(n); //O(log n)
    double factor = 1; 
    // For precesion = 3 we have to run a loop three times for calculating 3 digits after decimal
    // If precesion is 3 ,loop will run 3 times
    for(int i=0;i<precesion;i++){  // O(precesion * 10) in the worst case
        factor = factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter any number : ";
    cin>>n;

    cout<<"Sqrt root of the number : "<<Sqrt(n,4)<<endl;

    return 0;
}