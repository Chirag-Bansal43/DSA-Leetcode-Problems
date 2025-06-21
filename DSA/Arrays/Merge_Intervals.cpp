#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------------------------------------------------------
// Optimal Solution
T.C = O(n logn + n) , S.C = O(n*2) // for merged_list
*/
vector<vector<int>> Merge(vector<vector<int>>& ques){
    sort(ques.begin(),ques.end());
    vector<vector<int>> merged_list;
    merged_list.push_back(ques[0]);

    for(int i=1;i<ques.size();i++){
        vector<int> last_Interval(2);
        last_Interval = merged_list.back();
        if(ques[i][0]<=last_Interval[1]){
            if(ques[i][1]>last_Interval[1])
                merged_list[merged_list.size()-1][1] = ques[i][1];
        }
        else{
            merged_list.push_back(ques[i]);
        }
    }
    return merged_list;
} 
//----------------------------------------------------------------------------------------------------

void Input_array(vector<vector<int>>& ques , int n){
    cout<<"Enter pairs ->"<<endl;
    for(int i=0;i<n;i++){
        vector<int> Pair(2);
        cin>>Pair[0]>>Pair[1];
        ques.push_back(Pair);
    }
}

void printAns(vector<vector<int>>& ans){
    cout<<"\nMerged Array -> "<<endl;
    cout<<"[[ "<<ans[0][0]<<' '<<ans[0][1]<<" ], ";
    for(int i = 1;i<ans.size()-1;i++){
        cout<<"[ ";
        for(int j = 0;j<2;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"], ";
    }
    cout<<"[ "<<ans[ans.size()-1][0]<<' '<<ans[ans.size()-1][1]<<" ]]";
    cout<<endl;
}

int main(){
    vector<vector<int>> arr;
    vector<vector<int>> ans;
    int n;
    cout<<"Enter number of pairs in the array : ";
    cin>>n;
    // Taking input for question vector
    Input_array(arr,n);

    // Merging Intervals
    ans = Merge(arr);

    // Printing Merged Array
    printAns(ans);

    return 0;
}