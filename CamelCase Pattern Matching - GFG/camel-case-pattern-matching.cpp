//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> result;
        vector<pair<string,string>> mp;
        for(auto word : Dictionary){
            string str="";
            for(auto i:word){
                if(isupper(i)){
                    str+=i;
                }
            }
            mp.push_back({word,str});
        }
        for(auto i:mp){
            if(i.second[0]==Pattern[0]){
                if (i.second.find(Pattern) != string::npos){
                    result.push_back(i.first);
                }
            }
        }
        if(!result.empty()){
            return result;
        }
        else{
            return {"-1"};
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends