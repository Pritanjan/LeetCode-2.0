//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
private: 
    void dfs(int node, vector<int> adj_ls[], int vis[]) {
        vis[node] = 1;
        for(auto it : adj_ls[node]) {
            if(!vis[it]) {
                dfs(it, adj_ls, vis);
            }
        }
    }
    
public:
    int numProvinces(vector<vector<int>>& adj, int V) {
        // to convert adjacency matrix into adjacency list
        vector<int> adj_ls[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adj_ls[i].push_back(j);
                    adj_ls[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adj_ls, vis);
            }
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends