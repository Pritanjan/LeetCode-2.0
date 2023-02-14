//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int aa[4]={-1,1,0,0};
    int bb[4]={0,0,-1,1};
    void dfs(vector<vector<int>> &mat,vector<vector<int>> &v,int i,int j,int n,int m)
    {
        v[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int xx=i+aa[k],yy=j+bb[k];
            if(xx>=0 && yy>=0 && xx<n && yy<m && mat[xx][yy]>=mat[i][j] && v[xx][yy]==0) dfs(mat,v,xx,yy,n,m);
        }
    }
    int water_flow(vector<vector<int>> &mat,int n,int m)
    {
        vector<vector<int>> a(n,vector<int>(m,0)),b(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0) && a[i][j]==0) dfs(mat,a,i,j,n,m);
                if((i==n-1 || j==m-1) && b[i][j]==0) dfs(mat,b,i,j,n,m);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]>0 && b[i][j]) ans++;
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends