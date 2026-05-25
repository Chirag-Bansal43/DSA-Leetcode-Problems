#include <bits/stdc++.h>
using namespace std;

/* Heap Sort Process same as deletion baas deletion ko repeatedly execute karna hai till the size of heap becomes 1 
1. Make array into MaxHeap
2. Swap Top element of heap with the last element
3. Decrease the size of heap
4. Now, Top element of uski correct position pe leke jaayo using Heapify and Now again Maxheap is ready of size = n-1 ...
So, again do the same process i.e swapping the Top element -> decrease the size -> Bring Top Element to it's correct position using Heapify untill size of heap becomes 1..
After Size of Heap becomes 1 complete array gets sorted
*/

// Heapify code written iteratively => TC = O(n*logn) , SC = O(1)
void Heapify(int arr[],int index,int size){
    // here current stores index of current element
    int current = index;
    while(true){
        int largest = current;
        int left = 2* current + 1;
        int right = 2* current + 2;

        if(left<size && arr[left] > arr[largest])
            largest = left;
        if(right<size && arr[right] > arr[largest])
            largest = right;
        
        if(largest != current){ // if largest not equal to current element ka index
            swap(arr[largest],arr[current]); // largest and current element ko swap kar denge
            current = largest; // abb current element ka index largest ke barabaar ho jayega
        }
        else    break;
    }   
}

void BuildMaxHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
}

// Recursive code (TC = O(n*logn) , SC = O(n))
/*
void SortArray(int arr[],int size){
    // base case
    if(size == 1)   return;

    swap(arr[0],arr[size-1]);
    size--;
    Heapify(arr,0,size);
    SortArray(arr,size);
}
*/

// Iterative Code (TC = O(n*logn) , SC = O(1))
void SortArray(int arr[],int size){
    while(size){
        swap(arr[0],arr[size-1]);
        size--;
        Heapify(arr,0,size);
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2,5,7,3,17,15,25,27,21,78,71};
    
    // Heap Sort : Start
    BuildMaxHeap(arr,11);
    SortArray(arr,11);
    //Heap sort end

    print(arr,11);

    return 0;
}