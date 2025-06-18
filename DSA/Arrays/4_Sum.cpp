#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------------------------------
// Better solution - (using Sorting and  2 pointers Approach)
T.C = O(n^3 + n logn) , S.C = O(1)

// Reference for int S
nums[i] + nums[j] + nums[l] + nums[k] = target
S = nums[j] + nums[l] + nums[k] = target - nums[i]
S is the required sum of triplets for the particular i...
*/
vector<vector<int>> Four_Sum_01(vector<int>& ques,int& target){
    vector<vector<int>> ans;
    sort(ques.begin(),ques.end());
    int n = ques.size();
    for(int i=0;i<n;i++){ // T.C = O(n^3)
        if(i>0 && ques[i]==ques[i-1])   continue;
        int S = target-ques[i];
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && ques[j]==ques[j-1]) continue;
            int l = j+1,k=n-1;
            while(l<k){
                long long sum = (long long) ques[j] + ques[l] + ques[k];
                if(sum == S){
                    vector<int> quadruplet = {ques[i],ques[j],ques[l],ques[k]};
                    ans.push_back(quadruplet);
                    l++;k--;
                    while(l<k && ques[l]==ques[l-1]) l++;
                    while(l<k && ques[k]==ques[k+1]) k--;
                }
                else if(sum<S)  l++;
                else k--;
            }
        }
    }
    return ans;
}

void printAns(vector<vector<int>>& ans){
    cout<<endl;
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<4;j++){
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

    // Taking input for target sum of quadruplet
    int target;
    cout<<"Enter target : ";
    cin>>target;

    vector<vector<int>> ans = Four_Sum_01(arr,target);

    // Printing ans array
    printAns(ans);

    return 0;
}