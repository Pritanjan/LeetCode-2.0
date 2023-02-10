//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    bool know(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1) return 1;
        else return 0;
    }
    
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // push all elemenbt in stack
        stack<int> stk;
        for(int i=0; i<n; i++){
            stk.push(i );
        }
        
        // get 2 element & compare them
        while(stk.size() > 1){
            int a = stk.top();
            stk.pop();
            
            int b = stk.top();
            stk.pop();
            
            if(know(M, a,b, n)) stk.push(b);
            else stk.push(a);
            
        }
        
        int condidate = stk.top();
        // single element in stack is potential celebraity
        
        
        int zerocount = 0;
        for(int i=0; i<n; i++){
            if(M[condidate][i] == 0) zerocount++;
        }
        
        if(zerocount != n) return -1;
        
        
        int onecount = 0;
        for(int i=0; i<n; i++){
            if(M[i][condidate] == 1) onecount++;
        }
        
        if(onecount != n-1) return -1;
        
        return condidate;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends