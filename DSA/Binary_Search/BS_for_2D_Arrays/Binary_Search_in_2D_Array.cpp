#include <bits/stdc++.h>
using namespace std;

// Q1 -> Search a 2D Matrix I
// When all 2D array is sorted
// T.C = O(log (m*n))
bool BinarySearch_2DArray(vector<vector<int>>& matrix,int target){
    int m = matrix.size();
    int n = matrix[0].size();

    // Applying Binary Search
    int s = 0, e = m*n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        // index se row/col nikalna hai => | row = index / no. of col | col = index % no. of col
        int element = matrix[mid / n][mid % n];
        
        if(element == target)   return true;
        else if(element < target)   s=mid+1;
        else    e = mid-1;
    }
    return false;
}

/*Q2 -> Search a 2D Matrix II
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/
// M-1 : Brute Force Approach
// T.C = O(m* log(n)) , where m= no.of rows and n = no. of columns 
bool BinarySearch_2DArray_02(vector<vector<int>>& matrix,int target){
    int m = matrix.size();
    int n = matrix[0].size();

    // Applying Binary Search on each row
    for(int i=0;i<m;i++){
        // Apply BS on matrix[i]
        // starting -> row=i,col=0 | ending -> row=i,col=n-1
        int s = i*n,e = i*n + n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int element = matrix[ mid/n ][ mid%n ];
            if(element == target)   return true;
            else if(element < target)   s=mid+1;
            else    e = mid-1;
        }
    }
    return false;
}

// M-2 : Optimal Solution - Using concept of Binary search not the standard BS
// T.C = O(m+n) 
// Reducing the search space by checking some element from the array into the conditions like
// what if(ele < target) , if(ele > target) -> What happens How we can reduce our search space that whould our main goal
bool BinarySearch_2DArray_002(vector<vector<int>>& matrix,int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    // We start searching from the last ele of first row (or from the first ele of the last row)
    
    int RowIndex = 0;
    int ColIndex = cols-1;
    
    while(RowIndex < rows && ColIndex >= 0){
        int ele = matrix[RowIndex][ColIndex];
        if(ele < target){
            // we can't find target in the particular row so, we will do RowIndex++
            RowIndex++;
        }
        else if(ele > target){
            // we can't find target in the particular column so, we will do ColIndex--
            ColIndex--;
        } 
        else{
            return true;
        }
    }
    return false;
}



void Input2DMatrix(vector<vector<int>>& matrix,int m,int n){
    for(int r=0;r<m;r++){
        vector<int> Row;
        for(int c=0;c<n;c++){
            int ele;
            cin>>ele;
            Row.push_back(ele);
        }
        matrix.push_back(Row);
    }
}



int main(){
    vector<vector<int>> matrix;
    int m,n;
    cout<<"Enter number of rows and columns : ";
    cin>>m>>n;

    Input2DMatrix(matrix,m,n);

    int target;
    cout<<"Enter target : ";
    cin>>target;

    if(BinarySearch_2DArray(matrix,target))     cout<<"Element found"<<endl;
    else    cout<<"Element Not found"<<endl;


    return 0;
}