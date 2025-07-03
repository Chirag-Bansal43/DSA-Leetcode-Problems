#include <bits/stdc++.h>
using namespace std;

/* Same solution as below using ceil() bulitin function
T.C = same as below solution
int Find_Min_Eating_Speed(vector<int>& piles,int h){
    int n = piles.size();
    // Finding Maximum element in piles
    int maxBan = -1;
    for(int i=0;i<n;i++){   //O(no. of piles)
        if(piles[i]>maxBan)    maxBan=piles[i];
    }

    int s = 1,e=maxBan;
    int ans;
    while(s<=e){    //O( log(max element of piles ) )
        int mid = s+(e-s)/2;
        long long Totalhrs = 0;
        for(int i=0;i<n;i++){   //O(no. of piles)
            int hrsToEat = ceil( (double) piles[i] / (double) mid);
            Totalhrs += hrsToEat;
        }
        if(Totalhrs > h)     s=mid+1;
        else{
            ans = mid;
            e=mid-1;
        }
    }
    return ans;
}
*/

// T.C = O( no. of piles *  log(max element of piles array) + no. of piles )
int Find_Min_Eating_Speed(vector<int>& piles,int h){
    int n = piles.size();
    // Finding Maximum element in piles
    int maxBan = -1;
    for(int i=0;i<n;i++){   //O(no. of piles)
        if(piles[i]>maxBan)    maxBan=piles[i];
    }

    int s = 1,e=maxBan;
    int ans;
    while(s<=e){    //O( log(max element of piles ) )
        int mid = s+(e-s)/2;
        long long Totalhrs = 0;
        for(int i=0;i<n;i++){   //O(no. of piles)
            int hrsToEat;
            if(piles[i] % mid != 0)
                hrsToEat = piles[i]/mid + 1;
            else
                hrsToEat = piles[i]/mid;
            Totalhrs += hrsToEat;
        }
        if(Totalhrs > h)     s=mid+1;
        else{
            ans = mid;
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> piles;
    cout<<"Enter size of piles[] : ";
    int n;  cin>>n;
    // Taking input
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        piles.push_back(temp);
    }

    int h;
    cout<<"Enter h : ";
    cin>>h;

    cout<<"Minimum Eating Speed of koko is : "<<Find_Min_Eating_Speed(piles,h)<<endl;
    return 0;
}