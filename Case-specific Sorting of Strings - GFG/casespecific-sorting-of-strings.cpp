//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n) {
        // your code here
        vector<char> L, U;
        
        for(int i=0; i<n; i++){
            if(s[i] >= 97 && s[i] < 123) L.push_back(s[i]);
            else U.push_back(s[i]);
        }
        
        sort(L.begin(), L.end());
        sort(U.begin(), U.end());
        
        int l = 0;
        int u = 0;
        for(int i=0; i<n; i++){
            if(s[i] >= 65 && s[i] <= 90) s[i] = U[u++];
            else s[i] = L[l++];
        }
        return s;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends