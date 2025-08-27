#include <iostream>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i = 0; i<=n-2; i++){
        int min = i;
        for(int j = i; j <= n-1; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        // Now we do swaping
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;        
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
    selection_sort(arr,n);
    cout<<"Array after sorting :"<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}