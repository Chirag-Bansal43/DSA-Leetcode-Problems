#include <bits/stdc++.h>
using namespace std;

// Graph Implementation Using Adjacency List

// 1. Undirected Unweighted Graph / or  Directed Unweighted Graph
// 2. Undirected weighted Graph / or  Directed weighted Graph

int main(){

    int vertices,edges;
    cin>> vertices >> edges;

    // 1. Undirected Unweighted Graph

    // Declearing AdjList array
    /*
    vector<int> AdjList[vertices];

    int u,v; // u aur v ke beech ek edge ha (unweighted ha so by default weight 1 ha , weight ko store karne ki jarurat nahi ha)
    for(int i=0;i<edges;i++){
        cin>>u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);  // because it is undirected graph
    }
    */
    
    // Directed unweighted graph (same hi ha lagbhag)
    /*
    vector<int> AdjList[vertices];

    int u,v; // u aur v ke beech ek edge ha (unweighted ha so by default weight 1 ha , weight ko store karne ki jarurat nahi ha)
    for(int i=0;i<edges;i++){
        cin>>u >> v;
        AdjList[u].push_back(v); // Directed graph u se v edge present ha but v se u koi edge nahi ha
    }
    */


    // 2. Undirected weighted graph
    vector<pair<int,int>> AdjList[vertices]; 
    // first pair value represents ending node no. of an edge and second pair value represent weight of the edge (Note Edge is from starting node to ending node) // index of AdjList represent the starting node no. of a particular edge

    // Initialising AdjList
    int u,v,weight; // u sur v ke beetch edge present ha jiska weight , weight variable mein store hoga
    for(int i=0;i<edges;i++){
        cin>> u >> v >> weight;
        AdjList[u].push_back(make_pair(v,weight));
        AdjList[v].push_back(make_pair(u,weight)); // because it is undirected
    }

    // printing weighted AdjList
    for(int i=0;i<vertices;i++){
        cout<<i<<" -> ";
        for(int j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j].first <<" "<<AdjList[i][j].second<<" ";
        }
        cout<<endl;
    }

    // printing AdjList
    // for(int i=0;i<vertices;i++){
    //     cout<<i << " -> ";
    //     for(int j=0;j<AdjList[i].size();j++){
    //         cout<<AdjList[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



    return 0;
}