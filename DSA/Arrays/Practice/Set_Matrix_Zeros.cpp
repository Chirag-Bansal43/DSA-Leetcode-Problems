#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& matrix,string name){
    int m = matrix.size();  // Total no. of rows
    int n = matrix[0].size();  // Total no. of columns
    cout<<"\n\nPrinting "<<name<<" Matrix :-"<<endl;
    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            cout<<matrix[row][col]<<" ";
        }
        cout<<endl;
    }
}

// T.C = O(m*n(m+n)) , S.C = O(m*n)
// void rowZero(vector<vector<int>>& matrix,int rowNo){
//     for(int col = 0; col < matrix[0].size(); col++){
//         matrix[rowNo][col] = 0;
//     }
// }

// void colZero(vector<vector<int>>& matrix,int colNo){
//     for(int row = 0; row < matrix.size(); row++){
//         matrix[row][colNo] = 0;
//     }
// }

// void SetMatrixZeros(vector<vector<int>>& matrix){
//     int m = matrix.size();  // Total no. of rows
//     int n = matrix[0].size();  // Total no. of columns
//     vector<vector<int>> index;
//     for(int row = 0; row < m; row++){
//         for(int col = 0; col < n; col++){
//             if(matrix[row][col] == 0){
//                 index.push_back({row,col});
//             }
//         }
//     }

//     // Making row and column zero of every zero in index by traversing index
//     for(int ZeroPos = 0; ZeroPos < index.size(); ZeroPos++){
//         int rowNo = index[ZeroPos][0];
//         int colNo = index[ZeroPos][1];
//         rowZero(matrix,rowNo);
//         colZero(matrix,colNo);
//     }
// }

// T.C = O(m*n) , S.C = O(m+n)
// void SetMatrixZeros(vector<vector<int>>& matrix){
//     int m = matrix.size();  // Total no. of rows
//     int n = matrix[0].size();  // Total no. of columns
//     vector<int> rowZero(m,1);
//     vector<int> colZero(n,1);
//     for(int row = 0; row < m; row++){
//         for(int col = 0; col < n; col++){
//             if(matrix[row][col] == 0){
//                 rowZero[row] = 0;
//                 colZero[col] = 0;
//             }
//         }
//     }

//     for(int row = 0; row < m; row++){
//         for(int col = 0; col < n; col++){
//             if(rowZero[row] == 0 || colZero[col] == 0){
//                 matrix[row][col] = 0;
//             }
//         }
//     }
// }


// T.C = O(m*n) , S.C = O(1)
void SetMatrixZeros(vector<vector<int>>& matrix){
    int m = matrix.size();  // Total no. of rows
    int n = matrix[0].size();  // Total no. of columns
    int col0 = 1;
    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            if(matrix[row][col] == 0){
                matrix[row][0] = 0;
                if(col != 0){
                    matrix[0][col] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(int row = 1; row < m; row++){
        for(int col = 1; col < n; col++){
            if(matrix[row][0] == 0 || matrix[0][col] == 0){
                matrix[row][col] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        // first row ko zero karna hai
        for(int i = 1; i < n; i++){
            matrix[0][i] = 0;
        }
    }

    if(col0 == 0){
        // first column ko zero karna hai
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }

}


int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    printMatrix(matrix,"question");
    
    SetMatrixZeros(matrix);

    printMatrix(matrix,"answer");
    return 0;
}