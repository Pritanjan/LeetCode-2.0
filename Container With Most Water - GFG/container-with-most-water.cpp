//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int len){
    int L = 0;
    int R = len - 1;
    int sum = 0;
        
    while(L < R){
        int h = min(a[L], a[R]);
        sum = max(sum, h*(R-L));
            
        while(a[L] <=h && L<R ) L++;
        
        while(a[R] <=h && L<R ) R--;
    }
    return sum;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends