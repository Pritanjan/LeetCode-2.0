//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    stack<int> stk;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        stk.push(temp);
    }
    
    while(!stk.empty()){
        int temp = stk.top();
        stk.pop();
        q.push(temp);
    }
    return q;
}

// APPROACH 1 USING STACK
// element ko queue se nikal ko stack me dalo

// APPROACH 2 RECURSION

