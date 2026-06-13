#include <bits/stdc++.h>
using namespace std;

// TC = O(v+e) and SC = O(v) , v=no. of vertices and e=no. of edges
void DFS(int node,vector<int> AdjList[],vector<int>& visited,vector<int>& ans)
{   
    visited[node] = 1;
    ans.push_back(node);

    // ye loop above node ke aage wale invisited nodes ko explore karega 
    for(int i=0;i<AdjList[node].size();i++){
        if(!visited[AdjList[node][i]]){
            DFS(AdjList[node][i],AdjList,visited,ans);
        }
    }
// Jab node se aage ke saare nodes explore ho jayenge to ye loop khatam ho jayega and fxn return ho jayega
}

int main(){
    int vertices,edges;
    cin>>vertices >> edges;
    vector<int> AdjList[vertices];
    int u,v; // u aur v ke beech ek edge ha (unweighted ha so by default weight 1 ha , weight ko store karne ki jarurat nahi ha)
    for(int i=0;i<edges;i++){
        cin>>u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);  // because it is undirected graph
    }
    
    vector<int> ans;
    vector<int> visited(vertices,0);
    DFS(0,AdjList,visited,ans);

    // Print ans vector
    cout<<"DFS : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}