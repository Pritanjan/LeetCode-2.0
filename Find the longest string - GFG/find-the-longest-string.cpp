//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &w) {
        sort(w.begin(), w.end());
        vector<string> temp;
        for(auto &it : w){
            int n = it.size();
            string s = it.substr(0, n - 1);
            if(n == 1) temp.push_back(it);
            else if(find(temp.begin(),temp.end(), s) != temp.end()) temp.push_back(it);
        }
        
        int mx = 0;
        string ans;
        for(auto &it : temp){
            if(it.length() > mx){
                ans = it, mx = it.length();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends