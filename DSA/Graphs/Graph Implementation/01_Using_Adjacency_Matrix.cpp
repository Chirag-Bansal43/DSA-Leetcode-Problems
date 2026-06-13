#include <bits/stdc++.h>
using namespace std;

// Graph Implementation Using Adjacency Matrix
// Undirected Unweighted Graph - vertices and edges are present

// For Adjacency Matrix
    // Total TC for making Adjacency matrix of a graph = O(v^2 + 2* edges) = O(v^2)
    // Total SC = O(v^2)


int main(){
    int vertices,edges;
    cin>> vertices >> edges;

    // Undirected Unweighted Graph
    // Let's build one Adjacency Matrix
    vector<vector<bool>> AdjMat(vertices, vector<bool>(vertices,0)); // time= O(v^2)

    // Initializing our Adjacency Matrix

    int u,v; // => u = initial node no and v= final node no for a particular edge. eg=> 0 node se 1 node ke beech edge present ha to 0 ho gaya u and 1 ho gaya v 
    for(int i=0;i<edges;i++){ // no. of edges times loop chalega // time = O(2*edges)
        cin >> u >> v;
        AdjMat[u][v] = 1;
        AdjMat[v][u] = 1; // because it is undirected graph
    }
    
    //------------------------------------------------------------------------------------------------------------------
    /*
    // Undirected weighted Graph
    vector<vector<int>> AdjMat(vertices,vector<int>(vertices,0));

    // Initializing Adj Matrix
    int u,v,weight; // u aur v ke beech ek edge ha jiska weight weight variable mein lenge
    for(int i=0;i<edges;i++){
        cin>>u>>v>>weight;
        AdjMat[u][v] = weight;
        AdjMat[v][u] = weight; // because it is undirected graph
    }
    */ //-----------------------------------------------------------------------------------------------------------------

    // Directed weighted graph
    /*
    vector<vector<int>> AdjMat(vertices, vector<int>(vertices,0)); // time= O(v^2)

    // Initializing our Adjacency Matrix
    int u,v,weight; // => u = initial node no and v= final node no for a particular edge. eg=> 0 node se 1 node ke beech edge present ha to 0 ho gaya u and 1 ho gaya v 
    for(int i=0;i<edges;i++){ // no. of edges times loop chalega // time = O(2*edges)
        cin >> u >> v >> weight;
        AdjMat[u][v] = weight; // Directed Graph
    } */

    // Printing Adjacency Matrix
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}