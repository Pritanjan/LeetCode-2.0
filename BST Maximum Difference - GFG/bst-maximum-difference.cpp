//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int uppersum=0,mini=1e9;

    Node* func(Node* root,int target){
        if(root==NULL) return NULL;
        if(root->data==target) return root;
        uppersum+=root->data;
        if(target<root->data) return func(root->left,target);
        if(target>root->data) return func(root->right,target);
        return NULL;
    }
    
    void lowersum(Node* root,int lsum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            lsum+=root->data;
            mini=min(mini,lsum);
        }
        lsum+=root->data;
        lowersum(root->left,lsum);
        lowersum(root->right,lsum);
    }
    
    int maxDifferenceBST(Node* root,int target){
        Node* nodefound=func(root,target);
        if(nodefound!=NULL){
            lowersum(nodefound,0);
            mini-=target;
            return uppersum-mini;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends