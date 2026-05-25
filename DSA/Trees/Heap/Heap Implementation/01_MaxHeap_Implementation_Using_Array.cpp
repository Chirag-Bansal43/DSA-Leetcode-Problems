#include <bits/stdc++.h>
using namespace std;

// MaxHeap And MinHeap Implementation using Array

class MaxHeap
{
    int* arr;
    int size; // no. of elements in heap
    int total_size; // total sie of heap

    public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    /* Steps of Insertion in Heap :->
    1. array mein new element push back karo
    2. Vo new Element of step up karte hue correct position pe leke jaayo
    */
    // TC = log2(n)
    void insert(int value){
        // check heap is full or not
        if(size == total_size){
            cout<<"Heap Overflow"<<endl;
        }
        else{
            arr[size] = value;
            int child = size;
            int parent = (child-1)/2;
            // step up algo.
            while(child > 0){
                if(arr[child] > arr[parent]){ // For MinHeap ke liye > will become < here ...
                    swap(arr[child],arr[parent]);
                    child = parent;
                    parent = (child-1)/2;
                }
                else{
                    break;
                }
            }
            size++;

            cout<< arr[child] <<" is inserted in MaxHeap"<<endl;
        }
    }

    // Ye Ek Process ka Top Element ko coreect position pe leke jane ka
    // step down process Heapify ko khete hai
    void Heapify(int index){ // ye index mein parent node ka index store hoga
        
        int largest = index; // abhi initialisation ke liye largest mein parent ka index store kiya hai
        int left = 2*index+1; // left mein parent ke left child ka index
        int right = 2*index+2; // right mein parent ke right child ka index

        // largest mein tino mein se yani parent , left child and right child jo bada hoga uska index store karna hai
        // left<size matlab left child exist karta hai , jo index size ke bahar chala gaya vo exist bhi nahi karta humare liye
        if(left<size && arr[left] > arr[largest]) // for MinHeap just replace > with < ... Now condtion become arr[left] < arr[largest]
            largest = left;
        
        if(right<size && arr[right] > arr[largest]) // for MinHeap just replace > with < ... Now condtion become arr[right] < arr[largest]
            largest = right;
        
        // Now largest contains address of maximum of all three elements parent , it's left child and it's right child

        if(largest != index){ // means one of it's child is greater than it's parent means we have to swap
            swap(arr[largest],arr[index]);
            Heapify(largest);
        }
        // and if largest == index means parent is greatest of it's childs and no swapping needs so simply return from this function
    }

    // Heap mein delete hamesha Top Element hota hai
    /* Steps of Deletion :-> 
    1. Top Element of swap karo last element se
    2. size ko ek se decrease karo
    3. Top Element ko apni correct position pe leke jaayo (or kahe sakte hai Heapify karo)
    */
    // TC = O(log2n)
    void Delete(){
        if(size == 0){
            cout<<"Heap Underflow"<<endl;
            return;
        }

        cout<<arr[0] <<" deleted from Heap"<<endl;
        
        arr[0] = arr[size-1];
        size--;

        if(size == 0)
            return;
        
        Heapify(0);
    }


    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    // Inserting n nodes in MaxHeap implemented using array takes O(n*logn) time
    MaxHeap H1(6);
    H1.insert(7);
    H1.insert(6);
    H1.insert(10);
    H1.insert(3);
    H1.insert(1);
    H1.insert(15);
    H1.print();
    H1.insert(10);
    H1.print();

    H1.Delete();
    H1.print();
    H1.Delete();
    H1.print();


    return 0;
}