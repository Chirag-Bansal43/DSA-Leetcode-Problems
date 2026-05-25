#include <bits/stdc++.h>
using namespace std;


// Opimal :- TC = O(k1*logk1 + k2*logk2) , SC = O(k1+k2)
long long sumBetweenTwoKth(long long A[], long long N, long long k1, long long k2) {
        // for finding kth smallest elements we use MaxHeap
        priority_queue<long long> q1; // for storing k1 smallest elements
        priority_queue<long long> q2; // for storing k2 smallest elements actually we don't need k2 smallest elements we only need to store k2-1 smallest elements
        
        // And we actually subtract sum of k1 smallest elements from k2-1 smallest element to get sum of elements between k1 smallest and k2 smallest elemets
        
        // storing k1 smallest elements into queue q1
        for(long long i=0;i<k1;i++){
            q1.push(A[i]);
        }
        
        for(long long i=k1;i<N;i++){
            if(A[i] < q1.top()){
                q1.pop();
                q1.push(A[i]);
            }
        }
        
        // storing k2-1 smallest elements into queue q2
        for(long long i=0;i<k2-1;i++){
            q2.push(A[i]);
        }
        
        for(long long i=k2-1;i<N;i++){
            if(A[i] < q2.top()){
                q2.pop();
                q2.push(A[i]);
            }
        }
        
        // Now find sum of elements in q1 and q2 in sum1 and sum2 respectively
        long long sum1 = 0,sum2 = 0;
        while(!q1.empty()){
            sum1 += q1.top();
            q1.pop();
        }
        
        while(!q2.empty()){
            sum2 += q2.top();
            q2.pop();
        }
        
        return sum2-sum1;
    }

// M-2 : Brute Force using sorting :- TC = O(n*logn)
long long sumBetweenTwoKth(long long A[], long long N, long long k1, long long k2) {
        sort(A,A+N);
        
        // calculating sum b/w k1th smallest (at index k1-1) and k2th smaleest element (at index k2-1)
        long long sum = 0;
        for(long long i=k1;i<k2-1;i++){
            sum += A[i];
        }
        
        return sum;
    }

int main(){
    
    return 0;
}