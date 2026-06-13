#include <bits/stdc++.h>
using namespace std;

// Solved using DFS
// TC = O(V+2E) , SC = O(v)
bool CycleExist(int node,int preNode,vector<int> AdjList[],vector<int>& visited){   
    visited[node] = 1;

    // ye loop above node ke aage wale invisited nodes ko explore karega 
    for(int i=0;i<AdjList[node].size();i++){
        if(visited[AdjList[node][i]] && AdjList[node][i] != preNode){
            return true;
        }
        else if(!visited[AdjList[node][i]]){
            bool result = CycleExist(AdjList[node][i],node,AdjList,visited);
            if(result == true)  return true;
        }
    }
    return false;
// Jab node se aage ke saare nodes explore ho jayenge to ye loop khatam ho jayega and fxn return ho jayega
}


// Solved Using BFS Traversal
bool CycleExist(int node,vector<int> AdjList[],vector<int>& visited)
{   
    // BFS
    visited[node] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(node,-1));
    
    while(!q.empty()){
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(int i=0;i<AdjList[currNode].size();i++){
            if(parent == AdjList[currNode][i])  continue;
            else if(visited[AdjList[currNode][i]]){
                return true; // cycle detected
            }
            else{
                visited[AdjList[currNode][i]] = 1;
                q.push(make_pair(AdjList[currNode][i],currNode));
            }
        }
    }
    
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> AdjList[V];
        // u aur v ke beech ek edge ha (unweighted ha so by default weight 1 ha , weight ko store karne ki jarurat nahi ha)
        for(int i=0;i<edges.size();i++){
                int node1 = edges[i][0];
                int node2 = edges[i][1];
                AdjList[node1].push_back(node2);
                AdjList[node2].push_back(node1);  // because it is undirected graph
        }
        
        // prenode means previous node 
        vector<int> visited(V,0); // O(v) = SC
        
        // this is correct for connected graph but if the graph is disconnected like here in this question then you have to check cycle exist for every unvisited node or not
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(CycleExist(i,-1,AdjList,visited))    return true; //O(v) = SC for recursion
            }
        }
        
        return false;
        
    }

int main(){
    
    return 0;
}