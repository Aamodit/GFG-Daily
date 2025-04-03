//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool hasCycleDFS(int node,int parent,vector<int>&visited,unordered_map<int,list<int>>&adj){
        visited[node]=true;
        for(auto&nbr:adj[node]){
            if(nbr==parent)continue;
            if(visited[nbr]&&nbr!=parent) return true;
            if(!visited[nbr]&&hasCycleDFS(nbr,node,visited,adj)) return true;
        }
        return false;
    }
    bool hasCycleBFS(int node,int parent,vector<int>&visited,unordered_map<int,list<int>>&adj){
        queue<pair<int,int>>q;
        q.push({node,parent});
        visited[node]=true;
        
        while(!q.empty()){
            int nde=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto&nbr:adj[nde]){
                if(nbr==parent)continue;
                if(visited[nbr]&&nbr!=parent) return true;
                if(!visited[nbr]){
                    q.push({nbr,nde});
                    visited[nbr]=true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        for(auto&vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i] && hasCycleBFS(i,-1,visited,adj)) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends