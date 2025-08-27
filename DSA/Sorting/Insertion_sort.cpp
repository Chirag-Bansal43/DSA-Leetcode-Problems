#include <iostream>
using namespace std;

void Insertion_sort(int arr[],int n){
    for(int i = 0; i <= n-1; i++){
        int j=i;
        while (j>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j = j - 1;
        }
    }
}



int main(){
    int n;
    int arr[n];
    cout<<"Enter Number of elements in array : ";
    cin>>n;
    cout<<"Enter array elements :"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    Insertion_sort(arr,n);
    cout<<"Array after sorting :"<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}