#include <bits/stdc++.h>
using namespace std;

//118. Pascal's Triangle

/* Theory
// Algorithm used to solve this is "Iterative Dynamic Programming (Bottom-Up) "
In This we Prints the rth row with the help of (r-1)th row
T.C = ~O(3* n^2) = O(n^2) (Optimal)
S.C = O(n) // for the use of vector<int> back vector here extra space used is O(n) and 
the space for 'row' vector and 'v' vector is required for returning answer so it is not counted in extra space
- We can do this in O(1) S.C in this algorithm but the solution written below uses O(n) space just to make the code not look messy

// Combinatorics to solve this and other variation of this Problem
(1st variation : Return Rth row and nth column element of Pascal's Triangle)
- This problem can also be solved using the concept of Combinatorics. The rth row and nth column(not talking about index) element 
of Pascal's Triangle can be given by Combination of (r-1,c-1); means C(r-1,n-1);
eg - 3rd row 2nd element of Pascal's Triangle is 2 so, it is given by C(3-1,2-1) = C(2,1) = 2

(2nd Variation) : Printing the rth row without using (r-1)th 
- If do this by relating the row number 'r'(not index of row) & column indexes with values of combination 
for each element i.e nCr = n!/r! x (n-r)! = (n*n-1*n-2*n-3*n-r+1)/1*2*3*r ; no. of terms in numerator = no.of terms in denominator 
=> n/1 * (n-1)/2 *(n-2)/3 * (n-r+1)/r -> ye ha isko chalaki se likhne ka tarika abb n*(n-1) 2 se divisible hoga
and n,n-1,n-2 tino mein se koi ek to 3 se divisible hoga hi hoga... 
                     (0)   (1)       (2)            (3) // column indexes (col)
eg =        4th row : 1     3         3              1
C(r-1,column index) :(3,0) (3,1)    (3,2)          (3,3)
                =>     1    3/1   (3/1 * 2/2)  (3/1 * 2/2 * 1/3)
*************(row-col)/col term is multiplied to obtain the next term of the row

(3rd variation) : It is the same as above printing the entire pascal triangle till nth row
-Method1 : This we can do with Iterative Dynamic Programming algo 
-Method2 : Make rth row using 2nd Variation and print the rows till the nth row
Both are optimal approaches done in O(n^2) time & O(1) space
*/

// 1st variation : getting rth row and nth column element of Pascal's Triangle (here r and n are row and column number not indexes)
// T.C = O(k), where k = column number of element to find
int getelement(vector<vector<int>> &v,int row,int column){
    // find C(row-1,column-1) -> nikalne ke liye '1 to column-1' tak loop chalana padega
    // nCr = n/1 * (n-1)/2 *(n-2)/3 * (n-r+1)/r -> 1 se r tak loop chalta hai
    int ans = 1;
    for(int i=1;i<column;i++){
        ans = ans * (row-i)/i;
    }
    return ans;
}

// 3rd variation
//Method-1 "Iterative Dynamic Programming (Bottom-Up) Algo"
void FirstRowPush(vector<vector<int>> &v){
    vector<int> row = {1};
    v.push_back(row);
}

void FirstTwoRowsPush(vector<vector<int>> &v){
    FirstRowPush(v);
    vector<int> row = {1,1};
    v.push_back(row);
}

// T.C = O(n^2) , S.C = O(n)
void PascalTriangle_01(vector<vector<int>> &v,int& n){
    if(n==1)    FirstRowPush(v);
    else if(n==2)   FirstTwoRowsPush(v);
    else{
        FirstTwoRowsPush(v);
        int count = 0;
        vector<int> row;
        while(count < (n-2)){
            row.push_back(1);
            vector<int> back = v.back();
            for(int i = 1;i<v.back().size();i++){
                int sum = back[i] + back[i-1];
                row.push_back(sum);
            }
            row.push_back(1);
            v.push_back(row);
            count++;
            row = {};
        }
    }
} //Method:1 ends


// Method 2 : Using (2nd variation to generate rows and print all rows till nth row)
//Combinatorics Approach
// Here we are generating rth row not using (r-1)th row
// T.C = O(n^2) , S.C = O(1)
vector<int> generateRow(int row){
    long long ans = 1; // take it long long as it is storing product int may get overflow
    vector<int> ansrow;
    ansrow.push_back(1);
    for(int col = 1;col<row;col++){
        ans = ans * (row-col)/col;
        ansrow.push_back(ans);
    }
    return ansrow;
}

void PascalTriangle(vector<vector<int>> &v,int& n){
    for(int row=1;row<=n;row++){
        v.push_back(generateRow(row));
    }
}


int main(){
    vector<vector<int>> v;
    int n;
    cout<<"Enter Number of rows : ";
    cin>>n;

    PascalTriangle(v,n);

    cout<<"\nPrinting the Pascal's Pattern upto "<<n<<" row ->"<<endl;
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\n7th row 7th column element : "<<getelement(v,7,7)<<endl;

    return 0;
}