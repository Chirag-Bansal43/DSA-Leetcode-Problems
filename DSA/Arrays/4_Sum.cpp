#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------------------------------
// Better solution - (using HashSet)
T.C = O(n^3 * log(no. of unique quadruplets) + n^3) = O(n^3 * log (n^3)) in average case = O(n^3 * logn)
S.C = O(no. of unique triplets + n) ~ O(n^3) in average case

// hashSet.find(forth) , this is a point where mistake happens
here if hashSet stores int i.e hashSet<int> then argument of find will also take integer 
it is like this - hashSet<int>.find((int) forth) , if forth is long long then it will type cast forth in integer and if forth is out of range of integer then also it will type cast it and shows ajib sa behaviour
So, if your argument of find is long long So, you should change the hashSet<int> to hashSet<long long>
hashSet<long long>.find((long long) forth) : it will take long long argument And works fine
*/
vector<vector<int>> Four_Sum_02(vector<int>& ques,int& target){
    set<vector<int>> AnsSet;
    int n = ques.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            unordered_set<long long> hashSet;
            for(int l=j+1;l<n;l++){
                //here ques[i] Explicitly type cast into long long to avoid integer overflow while doing addition in right hand side
                // the long long in right hand side again implicitly converts into int and stores into forth variable
                long long forth = target-(1LL * ques[i]+ques[j]+ques[l]); // 1LL * x (Explicit type conversion of x to long long)
                if(hashSet.find(forth) != hashSet.end()){
                    vector<int> quadruplet = {ques[i],ques[j],ques[l],(int)forth};
                    sort(quadruplet.begin(),quadruplet.end());
                    AnsSet.insert(quadruplet);
                }
                hashSet.insert(1LL * ques[l]);
            }
        }
    }

    vector<vector<int>> ans(AnsSet.begin(),AnsSet.end());
    return ans;
}


/*---------------------------------------------------------------------------------------------------
// Optimal Solution - (using Sorting and  2 pointers Approach)
T.C = O(n^3 + n logn) , S.C = O(1)
*/
vector<vector<int>> Four_Sum(vector<int>& ques,int& target){
    vector<vector<int>> ans;
    sort(ques.begin(),ques.end());
    int n = ques.size();
    for(int i=0;i<n;i++){ // T.C = O(n^3)
        if(i>0 && ques[i]==ques[i-1])   continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && ques[j]==ques[j-1]) continue;
            int l = j+1,k=n-1;
            while(l<k){
                long long sum = (long long) ques[i] + ques[j] + ques[l] + ques[k];
                if(sum == target){
                    vector<int> quadruplet = {ques[i],ques[j],ques[l],ques[k]};
                    ans.push_back(quadruplet);
                    l++;k--;
                    while(l<k && ques[l]==ques[l-1]) l++;
                    while(l<k && ques[k]==ques[k+1]) k--;
                }
                else if(sum<target)  l++;
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

    vector<vector<int>> ans = Four_Sum(arr,target);

    // Printing ans array
    printAns(ans);

    return 0;
}