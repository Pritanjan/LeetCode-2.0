//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int p[], int l, int r, int k) {
        priority_queue<int> pq;
        
        // step 1 
        for(int i=0; i<k; i++) pq.push(p[i]);
        
        // step 2
        for(int i=k; i<=r; i++){
            if(p[i] < pq.top()){
                pq.pop();
                pq.push(p[i]);
            }
        }
        
        int res = pq.top();
        return res;
    }
};


// APPROACH 1
// SORT THE ARRAY  --> O(N log N)
// RETURN P[K-1]   --> O(1)

// APPROACH 2
// FIREST K-ELEMENT -> MAX_HEAP
// FOR REST ELEMENT --> IF ELEMENT < HEAP.TOP()  
                            // HEAP.POP()
                            // HEAP.PUSH(ELEMENT)



//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends