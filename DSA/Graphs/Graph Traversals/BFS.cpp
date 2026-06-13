#include <bits/stdc++.h>
using namespace std;

// TC = O(v+e) , SC = O(v) , v=no. of vertices and e=no. of edges
vector<int> BFS(int vertices,vector<int> AdjList[]){
    vector<int> ans;
    queue<int> q;
    vector<int> visited(vertices,0);
    // Initially queue mein 0 daal do (0 wale node se traversal start kar kar lete ha)
    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        // front wale node ko ans mein daaldo and iske agal bagal wale jo visited nahi ha unko queue mein daaldo
        ans.push_back(node);
        for(int i=0;i<AdjList[node].size();i++){
            if(!visited[AdjList[node][i]]){
                visited[AdjList[node][i]] = 1;
                q.push(AdjList[node][i]);
            }
        }
    }
    return ans;
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

    vector<int> ans = BFS(vertices,AdjList);

    cout<<"BFS : ";
    for(int i=0;i<vertices;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}