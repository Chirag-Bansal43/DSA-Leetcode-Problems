// Leetcode : 1482

#include <bits/stdc++.h>
using namespace std;

// T.C = O(n * log2 ( min(arr[]) - max(arr[]) ) + n )
int Minimum_Number_of_Days_to_Make_m_Bouquets(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();

    // Checking when it is impossible to make m bouquets (this happens when no. of flowers require to make m bouquets is more than the total no. of flowers in the garden)
    // m*k is the no. of flowers require to make m bouquets
    if(1LL*m*k > n)     return -1;


    // Finding Maximum element in bloomDay -> O(n)
    int maxDay = -1,minDay = INT_MAX; 
    for(int i=0;i<n;i++){   //O(n)
        if(bloomDay[i]>maxDay)    maxDay=bloomDay[i];
        if(bloomDay[i]<minDay)    minDay=bloomDay[i];
    }
    
    // Starting the Binary Search
    // Our Search Space is from [ min(arr[]) - max(arr[]) ] ...
    int s = minDay,e = maxDay;
    int ans = INT_MAX;
    while(s<=e){
        int mid = s+(e-s)/2;
        int cnt = 0, NOfbouquet = 0;
        for(int i=0;i<n;i++){   //O(n)
            if(bloomDay[i]<=mid)    cnt++;
            else    cnt = 0;
            if(cnt == k){
                NOfbouquet++;
                cnt = 0;
            }
        }

        if(NOfbouquet<m)    s = mid+1;
        else{
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> bloomDay;
    cout<<"Enter size of bloomDay[] : ";
    int n;  cin>>n;
    // Taking input
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        bloomDay.push_back(temp);
    }

    int m,k;
    cout<<"Enter m and k : ";
    cin>>m>>k;

    cout<<"Minimum Number of Days to Make m Bouquets is : "<<Minimum_Number_of_Days_to_Make_m_Bouquets(bloomDay,m,k)<<endl;
    return 0;
}