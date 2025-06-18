#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------------------------------------------------------
// Optimal Solution - Sorting and 2 Pointer Approach
T.C = O(n^2 + n logn) , S.C = O(1)
*/
vector<vector<int>> Three_Sum(vector<int>& ques){
    vector<vector<int>> ans;
    sort(ques.begin(),ques.end()); // O(n logn)
    for(int i=0;i<ques.size();i++){
        if(i>0 && ques[i]==ques[i-1])   continue;
        int j = i+1 , k = ques.size()-1;
        while(j<k){
            int sum = ques[i] + ques[j] + ques[k];
            if(sum == 0){
                vector<int> triplet = {ques[i],ques[j],ques[k]};
                ans.push_back(triplet);
                j++; k--;
                while(ques[j]==ques[j-1] && j<k)    j++;
                while(ques[k]==ques[k+1] && j<k)    k--;
            }
            else if(sum<0)  j++;
            else k--;
        }
    }
    return ans;
}

/*--------------------------------------------------------------------------------------------------
// Better Solution - HashSet Approach
T.C = O(n^2 * log n) , S.C = O(n^2 + n) = O(n^2)
*/
vector<vector<int>> Three_Sum_03(vector<int>& ques){
    set<vector<int>> AnsSet; // extra space = O(n^2) we have to remove this extra space in optimal solution
    // T.C = O(n^2 * log(n^2) + n^2) = O(n^2 * log n)
    for(int i=0;i<ques.size();i++){
        unordered_set<int> hashset; // extra space = O(n)
        for(int j=i+1;j<ques.size();j++){
            int third = -(ques[i] + ques[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> triplet = {ques[i],ques[j],third};
                sort(triplet.begin(),triplet.end());
                AnsSet.insert(triplet); // time = O(n^2) in average case
            }
            hashset.insert(ques[j]);
        }
    }

    vector<vector<int>> ans(AnsSet.begin(),AnsSet.end()); // time = O(n^2)
    return ans;
}

/*---------------------------------------------------------------------------------------------------
// Brute Force Solution
T.C = O(n^3 * logn) , S.C = O(n^3) in worst case because in worst case ~n^3(nC3) triplets can have sum == 0 
If I use set for storing triplets , it will already take care of duplicate triplets
and at the end traverse the set and copy the triplets to a vector<vector<int>>
*/
vector<vector<int>> Three_Sum_02(vector<int>& arr){
    int n = arr.size();
    int sum = 0;
    set<vector<int>> st;
    for(int i = 0;i<=n-3;i++){
        for(int j = i+1;j<=n-2;j++){
            for(int k = j+1;k<=n-1;k++){
                sum = arr[i]+arr[j]+arr[k];
                if(sum == 0){
                    vector<int> triplet = {arr[i],arr[j],arr[k]};
                    sort(triplet.begin(),triplet.end());
                    st.insert(triplet); // O(log (n^2)) in average case because ~n^2(nC3) triplet can have sum == 0 in average case
                }  
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end()); //O(n^2) in average case or O(n^3) in worst case
    return ans;
}

/*-------------------------------------------------------------------------------------------------------------------------------
// Extreme Brute Force Solution (My solution)
T.C = O(n^5) in average case and O(n^6) in worst case
S.C = O(1)

// Since there can be ~n^3 (nC3 = [n*(n-1)*(n-2)]/6 ) triplets that can be present in ans
So each call to Ispresent() takes O(n^3) time for checking duplicates in the worst case and O(n^2) time in the average case
// Comparison in if (i == triplet) takes O(3) = O(1) time 
So, T.C1 = O(n^3) (running 3 nested for loops) 
and let say most of the triplets in array have sum == 0 so Ispresent is called for most of the triplets in array with each call it takes O(n^2) time in average case
So, total T.C = O(n^3) * O(n^2) in average case = O(n^5) in average case
and T.C = O(n^3) * O(n^3) in worst case = O(n^6) in worst case
So, for loop in Ispresent() is really expensive...
*/
bool Ispresent(vector<int>& triplet,vector<vector<int>>& ans){
    bool present = false;
    for(auto i:ans){   // O(n^3) in worst case and O(n^2) time in average case
        if(i == triplet){
            present = true;
        }
    }
    return present;
}

vector<vector<int>> Three_Sum_01(vector<int>& arr){
    //T.C = O(n^5) in average case and O(n^6) in worst case , S.C = O(1)
    int n = arr.size();
    int sum = 0;
    vector<vector<int>> ans;
    for(int i = 0;i<=n-3;i++){
        for(int j = i+1;j<=n-2;j++){
            for(int k = j+1;k<=n-1;k++){
                sum = arr[i] + arr[j] + arr[k];
                if(sum == 0){
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);
                    sort(triplet.begin(),triplet.end());
                    if(!Ispresent(triplet,ans))
                        ans.push_back(triplet);
                }
            }
        }
    }
    return ans;
}
//-----------------------------------------------------------------------------------------------------------------------------


void printAns(vector<vector<int>>& ans){
    cout<<endl;
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main(){
    vector<int> arr;
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    // Taking input for question vector
    cout<<"Enter elements ->"<<endl;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }

    vector<vector<int>> ans = Three_Sum(arr);


    // Printing ans array
    printAns(ans);

    return 0;
}