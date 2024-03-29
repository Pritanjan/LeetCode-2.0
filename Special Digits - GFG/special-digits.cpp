//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int m=1e9+7;
    int f;
    
    int fact(int x)
    {
        int ans=1;
        for(int i=2;i<=x;++i)
        {
            ans=(ans*1LL*i)%m;
        }
        
        return ans;
    }
    
    
    int binexp(int a,int b)
    {
        int ans=1;
        
        while(b>0)
        {
            if(b&1)
            {
                ans=(ans*1LL*a)%m;
            }
            a=(a*1LL*a)%m;
             b=(b>>1);
        }
        
        return ans;
    }
    
    
    bool test(int x,int y,long long num)
    {
        while(num>0)
        {
            int rem=num%10;
            
            if(rem==x || rem==y)num/=10;
            else return 0;
        }
        
        return 1;
    }
    
    
    int comb(int i,int n)
    {
       int deno=(fact(n-i)*1LL*fact(i))%m;
        
       int mmi= binexp(deno,m-2);
        
       int ans=(f*1LL*mmi)%m;
       
       return ans;
    }
    
    
    int bestNumbers(int n, int a, int b, int c, int d) 
    {
        // code here
        long long sum=0;
        
        int x=min(a,b);
        b=max(a,b);
        a=x;
        
        f=fact(n);
        
        int ans=0;
        
        for(int i=0;i<=n;++i)
        {
            sum=i*a+(n-i)*b;
            
            if(!test(c,d,sum))continue;
            
            int ct=(comb(i,n)*1LL)%m;
            
            ans=(ans+0LL+ct)%m;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends