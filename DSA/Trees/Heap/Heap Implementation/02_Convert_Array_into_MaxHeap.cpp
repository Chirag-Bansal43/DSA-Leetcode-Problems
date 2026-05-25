#include <bits/stdc++.h>
using namespace std;

// Heapify code using recursion
// Recursion mein current node ka index , index parameter se pata chal jata hai

/*
void Heapify(int arr[],int index,int size){
    // here index parameter stores current element ka index
    int largest = index;
    int left = 2* index + 1;
    int right = 2* index + 2;

    if(left<size && arr[left] > arr[largest])
        largest = left;
    if(right<size && arr[right] > arr[largest])
        largest = right;
    
    if(largest != index){ // if largest not equal to current element ka index
        swap(arr[largest],arr[index]); // largest and current element ko swap kar denge
        Heapify(arr,largest,size); // abb current element ka index largest ke barabaar ho jayega
    }
}
*/

// Heapify code written iteratively
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

// Converting Array into MaxHeap
// Optimal : TC = O(n) , SC = O(1) {Using Step Down Approach from right to left in array starting from last non leaf node}
// It can also be done Using Step Up applied from left to right in array But that approach takes O(n*logn) time . Hence that was Brute Force Approach
void BuildMaxHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,i,n);
    }
}

// Brute Force Using Step Up applying from left to right in an array
// TC = O(n*logn) , SC = O(1)
/*
void BuildMaxHeap(int arr[],int n){
    for(int i=1;i<n;i++){
        int child = i;
        int parent = (i-1)/2;
        while(child>0 && arr[child] > arr[parent]){
            swap(arr[child],arr[parent]);
            child = parent;
            parent = (child-1)/2;
        }
    }
}
*/

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2,5,7,3,17,15,25,27,21,78,71};
    BuildMaxHeap(arr,11);
    print(arr,11);

    return 0;
}