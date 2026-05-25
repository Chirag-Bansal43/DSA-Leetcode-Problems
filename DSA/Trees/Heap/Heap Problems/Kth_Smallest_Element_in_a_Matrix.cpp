#include <bits/stdc++.h>
using namespace std;

// Heap Ki Bhatareen Problems mein se ek. It Problem have 5 approaches to solve

/* Concept 1 known by studing this problem
We can Convert array into MaxHeap in O(n) Using Step Down Approach
We can also make MaxHeap from array using Priority_Queue in O(n) time which uses Step Down Approach in background by writing this:-
priority_queue<int> q(vector.begin(),vector.end()); -> this will directly make MaxHeap(or priority_queue) from vector in O(n) time using step-down approach
priority_queue<int> q(arr,arr+n); -> if we want to make MaxHeap using C style array 
*/

/*
Concept 2 :- I studied How to use pair DS with priority_queue
pair<type1,type2> name_of_pair; -> this is how pairs are declared
pair<int,pair<int,int>> p; -> this is how we can store 3 values together in pairs. we can store 4, 5 .. any number of values by making more pairs

// Advantage of pair is that it can be used with priority_queue to decide priority of element based on first value,second value and third value
priority_queue< pair<int,pair<int,int>> > q; :- priority_queue ke aandar pair ki form mein tin value store ha
it will make MaxHeap according to first integer value of pair and if first integer value is same then it will give priority to second integer value of pair and if second integer value is same then it will give priority to third integer value of pair...
This is How we can use pairs with priority_queue
*/


// Method 1 : Solving using MinHeap
// Solving Using MinHeap : Optimal Approach :- TC = O(n*logn + k*logn) , SC = O(n)
int kthSmallest(vector<vector<int>> &mat, int k) {

        // first push all the elements of 0th column in MinHeap So, that we have to move only in one direction (i.e horizontal direction) for insertion of elements of matrix in MinHeap we don't need to move in both horizontal and vertical direction for insertion of elements in MinHeap
        // humko matrix mein dono direction mein move na karna pade iske liye humne ek direction ke saare elements phele hi MinHeap mein daal diye taaki sabhi elements ke liye humko sirf horizontal direction wala element daalna pade vertical wala element nahi
        // kyunki dikkat ye ho rahi thi ki kisi element ke liye vectical wala element MinHeap mein daalna tha kisi ke liye nahi to humne vertical direction ke 1st column ke saare elements daalke vertical direction ka kissa hi khatam kar diya abb khali horizontal direction mein hi chalna hoga sabhi elements ke liye
        
        // 3 values hogi pair mein ek element ke liye first uska data , then pair mein uska row and column index 
        // Space = O(n)
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q; // MinHeap is formed according to it's data value and if data value is same then it decide priority based on row index and then based on column index
        
        // pushing 1st column values in MinHeap
        int n = mat.size();
        for(int row=0;row<n;row++){ // column = 0; // time = O(n*logn)
            pair<int,pair<int,int>> p;
            p = make_pair(mat[row][0] , make_pair(row,0));
            q.push(p);
        }
        
        // Now extract k elements from MinHeap so that top will become kth smallest element pair
        // and wherever you extract element from heap insert it's next horizontal element from the matrix into MinHeap
        pair<int,pair<int,int>> top;
        for(int i=0;i<k;i++){ // time = O(k*logn)
            top = q.top();
            q.pop();
            
            if(top.second.second + 1 < n) // column index of next horizontal pair must be < n
            {
                pair<int,pair<int,int>> p;
                p = make_pair(mat[top.second.first][top.second.second + 1] , make_pair(top.second.first , top.second.second + 1));
                q.push(p);
            }
        }
        
        return top.first;
    }


    // Method-2 : Solving Using Binary Search
    // TC = O(n*log(max_Element-min_Element)) , SC = O(1)
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // Method-2 : Solving Using Binary Search
        // We know that our ans is lie b/w 1st element of matrix which is smallest element and last element of matrix which is largest element of matrix so, we apply BS on these two
        
        int n=mat.size();
        
        int st = mat[0][0],end = mat[n-1][n-1];
        
        int ans = -1;
        
        while(st<=end){
        
            int mid = st+(end-st)/2;
            
            // We will find that how many elements are there in matrix which is less than or equal to mid element , for this we not need to traverse the complete matrix one by one
            // For this We have the smart approach we can start from top right or bottom left element of matrix basically we need to start from that point of matrix jiske ek side element decrease ho rhe ho aur dusri side element increase ho rhe ho taki hum ek side ko reject kar sake aur dusri side mein search kare
            // like for top-right element left mein elements decrease kar rhe ha and niche elements increase kar rhe ha similar for bottom-left element
            // for top-left element ke liye dono side element decrease kar rhe ha so we can't reject one row/column dono side pe humare required elements which are less than or equal to mid element mil sakte ha to iss case mein humko dono side jana padega jisse TC increase hogi
            // Therefore, we start searching from top-right or botton-left element of matrix 
            
            // Go from top-right element towards left side
            int row = 0,col = n-1;
            int count = 0;
            while(row<n && col>=0){ // ye loop humko count karke bata dega ki kitne elements matrix mein mid wale element se <= hai in O(2n) time
                if(mat[row][col] > mid){
                    col--;
                }
                else{
                    // mat[row][col] <= mid , count these elements 
                    count += col+1;
                    // go niche
                    row++;
                }
            }
            
            
            // Isme ek Edge Case Banta hai duplicate Elements ka so for catering duplicates we write the condition that if(count > k) ha then also mid can be our answer if duplicates are present so we have to update ans in this case also
            /* See example
                mat = { {1,2},
                        {2,2} }    // sorted order => 1,2,2,2  So, if k = 1 or 2 then our 1st or 2nd smallest element is 2 But count for mid=2 is 4 So, if we simply decrease end to mid-1 then end will become 1 skips the element 2 which is our answer 
                        
                    So, we should update ans if(count>=k) and checks for smallest element whose count>=k in the left by doing end=mid-1;    
            
            */
            if(count >= k){
                ans = mid;
                end = mid-1;
            }
            else // count < k
                st = mid+1;
            
        }
        
        return ans;
        
    }




int main(){
    
    return 0;
}