//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long>a(arr.begin(),arr.end());
        sort(a.begin(),a.end());
        unordered_map<long long,long long>mp;
        vector<long long>pre(n,0),ans(n,0);
        pre[0]=a[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=a[i]+pre[i-1];
        }
        for(int i=0;i<n;i++){
            if(i==0) mp[a[i]]=0;
            else if(!mp.count(a[i])) mp[a[i]]=pre[i-1];
        }
        for(int i=0;i<n;i++)
          ans[i]=mp[arr[i]];
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends