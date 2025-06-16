#include <bits/stdc++.h>
using namespace std;

/*
Important here is to see that there can be at most 2 elements that are majority element greater than n/3 in any array
ans = {_,_} (ans can have at most 2 elements)
*/

// Moore's Voting Algorithm (Optimal)
// T.C = O(2n) , S.C = O(1)
vector<int> Majority_greater_than_Nby3(vector<int>& ques){
    int cnt1 = 0 , cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for(int i=0;i<ques.size();i++){
        if(cnt1 == 0 && el2 != ques[i]){
            cnt1 = 1;
            el1 = ques[i];
        }
        else if(cnt2 == 0 && el1 != ques[i]){
            cnt2 = 1;
            el2 = ques[i];
        }
        else if(ques[i] == el1)    cnt1++;
        else if(ques[i] == el2)    cnt2++;
        else{
            cnt1--; cnt2--;
        }
    }

    // Checking if el1 & el2 are majority element or not
    cnt1 = 0; cnt2 = 0;
    for(int i=0;i<ques.size();i++){
        if(ques[i] == el1)  cnt1++;
        if(ques[i] == el2)  cnt2++;
    }
    vector<int> ans;
    if(cnt1 > ques.size()/3)    ans.push_back(el1);
    if(cnt2 > ques.size()/3)    ans.push_back(el2);

    return ans;
}


// Brute Force Solution , T.C = O(n^2) , S.C = O(1)
vector<int> Majority_greater_than_Nby3_01(vector<int>& ques){
    int n = ques.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(ans.size() == 0 || ques[i]!=ans[0]){
            int count = 0;
            for(int j=0;j<n;j++){
                if(ques[j] == ques[i]){
                    count++;
                }
            }
            if(count>n/3){
                ans.push_back(ques[i]);
                if(ans.size()==2)   break;
            }
        }
    }
    return ans;
}

// T.C = O(n) , S.C = O(n) (Using Hash Maps)
vector<int> Majority_greater_than_Nby3_02(vector<int>& nums){
    int n = nums.size();
    int min = n/3 + 1;
    unordered_map<int,int> count;
    vector<int> ans;
    for(int i=0;i<n;i++){
        count[nums[i]]++;
        if(count[nums[i]] == min){
            ans.push_back(nums[i]);
            if(ans.size()==2)   break;
        }
    }
    return ans;
}


void printAns(vector<int>& ans){
    int n = ans.size();
    cout<<endl;
    if(n==0)
        cout<<"[]";
    else if(n==1)
        cout<<"["<<ans[0]<<"]";
    else
        cout<<"["<<ans[0]<<","<<ans[1]<<"]";
    cout<<endl;
}

int main(){
    vector<int> ques;
    int N;
    cout<<"Enter size of question vector : ";
    cin>>N;
    // Taking input for question vector
    cout<<"Enter elements ->"<<endl;
    for(int i=0;i<N;i++){
        int ele;
        cin>>ele;
        ques.push_back(ele);
    }

    //Solution Starts
    vector<int> ans = Majority_greater_than_Nby3(ques);

    //Print ans vector
    printAns(ans);

    return 0;
}