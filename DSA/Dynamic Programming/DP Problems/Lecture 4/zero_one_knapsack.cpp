#include <bits/stdc++.h>
using namespace std;

// Recursive code
// Recursion which don't gets easily converted into DP top down, iske liye 3D DP lagegi , jo ki nahi banani kyunki 2D DP mein kam ho sakta hai
int Find(int index,int remaining_wt,int total_val , vector<int>& val , vector<int>& wt){
        // base case
        if(index == 0)  return total_val;
        
        // indexed item usko - 1. le sakte hai 2. ya nahi le sakte
        if(wt[index-1] > remaining_wt) // skip that item
        return Find(index-1,remaining_wt,total_val,val,wt);
        
        else{ // iss item of hum le bhi sakte ha ya nahi bhi le sakte
            return max(Find(index-1,remaining_wt - wt[index-1] , total_val + val[index-1] , val,wt) , 
            Find(index-1,remaining_wt,total_val,val,wt)
            );
        }
    }

    // Modified Recursive function which can easily be converted into 2D DP
    int Find(int index,int remaining_wt, vector<int>& val , vector<int>& wt){
        // base case
        if(remaining_wt == 0)   return 0;
        
        if(index == 0)  return 0;
        
        // indexed item usko - 1. le sakte hai 2. ya nahi le sakte
        if(wt[index-1] > remaining_wt) // skip that item
        return Find(index-1,remaining_wt,val,wt);
        
        else{ // iss item of hum le bhi sakte ha ya nahi bhi le sakte
        // agar ye item ko lenge to left side function call se jo bhi value aayi usme val[index-1] add karke uss value ko consider karna hoga left side ke liye and 
        // agar ye item ko nahi lete hai to right side function call se jo value aayegi to directly consider karenge right side ke liye and 
        // dono mein se jo maximum value hogi usko upar return karenge
            return max(val[index-1] + Find(index-1,remaining_wt - wt[index-1],val,wt) , 
            Find(index-1,remaining_wt,val,wt)
            );
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // Recursive code
        int n = wt.size();
        return Find(n,W,val,wt); // index remaining_wt total_val val[] wt[]
        
    }

    // Top Down
    int Find(int index,int remaining_wt, vector<int>& val , vector<int>& wt, vector<vector<int>>& dp){
        // base case
        if(remaining_wt == 0)   return 0;
        
        if(index == 0)  return 0;
        
        if(dp[index][remaining_wt] != -1)
            return dp[index][remaining_wt];
        
        // indexed item usko - 1. le sakte hai 2. ya nahi le sakte
        if(wt[index-1] > remaining_wt) // skip that item
        return dp[index][remaining_wt] = Find(index-1,remaining_wt,val,wt,dp);
        
        else{ // iss item of hum le bhi sakte ha ya nahi bhi le sakte
        // agar ye item ko lenge to left side function call se jo bhi value aayi usme val[index-1] add karke uss value ko consider karna hoga left side ke liye and 
        // agar ye item ko nahi lete hai to right side function call se jo value aayegi to directly consider karenge right side ke liye and 
        // dono mein se jo maximum value hogi usko upar return karenge
            return dp[index][remaining_wt] = max(val[index-1] + Find(index-1,remaining_wt - wt[index-1],val,wt,dp) , 
            Find(index-1,remaining_wt,val,wt,dp)
            );
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // Recursive code
        int n = wt.size();
        
        // Top Down Approach
        vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
        
        return Find(n,W,val,wt,dp); // index remaining_wt total_val val[] wt[]
        
    }
    
    // Bottom Up Approach
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        
        // Bottom Up Approach
        vector<vector<int>> dp(n+1, vector<int>(W+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1] > j) // skip that item
                dp[i][j] = dp[i-1][j];
                
                else{ // iss item of hum le bhi sakte ha ya nahi bhi le sakte
                // agar ye item ko lenge to left side function call se jo bhi value aayi usme val[index-1] add karke uss value ko consider karna hoga left side ke liye and 
                // agar ye item ko nahi lete hai to right side function call se jo value aayegi to directly consider karenge right side ke liye and 
                // dono mein se jo maximum value hogi usko upar return karenge
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                }
            }
        }
        return dp[n][W];
    }


    // Most Imp chij sikhi ha isme ki space optimization karne ke liye humasha phele 2D mein required space find out karo
    // required space matlab 2D array ka vo space jo humko dp[i][j] ki value nikalne ke liye required hai
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        
        // Bottom Up Approach with further space optimization
        
        vector<int> dp(W+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=W;j>=0;j--){ 
                // MOST IMP YAHA LOOP PEECHE SE CHALANA HOGA SPACE OPTIMIZATION KARNE KE LIYE BECAUSE ISME agar loop aage se chalaenge to apni current row update ho ja rahi hai and order row ki value lost ho jayegi jo ki required ha dp[i][j] ko nikalne ke liye
                // So, agar peeche se value fill karna start karte hai to order row ki values apne 1D array mein mil jayegi , that means dp[i][j] ko nikalne ke liye jo jo order row ki values chaihye ha vo apne 1D array mein hi present hogi , aur apna required space change nahi hoga
                // required space matlab 2D array ka vo space jo humko dp[i][j] ki value nikalne ke liye required hai
                if(wt[i-1] <= j) 
                dp[j] = max(val[i-1] + dp[j-wt[i-1]] , dp[j]);
            }
        }
        
        return dp[W];
        
    }

int main(){
    
    return 0;
}