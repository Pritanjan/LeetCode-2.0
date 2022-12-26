//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    
    long long solve(long long L, long long R){
        long long ans = 0;
         for(int i=0; i<64; i++){
            for(int j=i+1; j<64; j++){
                for(int k=j+1; k<64; k++){
                    long long temp = 0;
                    temp = temp | (1L<<i);
                    temp = temp | (1L<<j);
                    temp = temp | (1L<<k);
                    if(temp >= L && temp <= R ) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends