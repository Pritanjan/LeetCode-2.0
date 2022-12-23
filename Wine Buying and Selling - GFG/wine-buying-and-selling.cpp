//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define ll long long int 
class Solution{
public:
  long long int wineSelling(vector<int>& arr, int N){
      ll res = 0, sum = 0;
      for(int i=0; i<N; i++){
          res += abs(sum);
          sum += arr[i];
          
        //   cout << res << endl;
      }
      return res;
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
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends