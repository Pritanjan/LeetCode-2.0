//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int xmod11(string x) {
        int i = 0;
        int rem = 0;
        
        while(i < x.length()){
            int ct = 0;
            int digit = 0;
            digit += 10 * rem;
           
            while(ct < 1 && i < x.length()) {
                digit += (x[i]-'0');
                i++;
                ct++;
            }
            rem = digit%11;
        }
        return rem;
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends