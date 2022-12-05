/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head) {
        int n = getLength(head);
        
        ListNode* temp = head;
        int cnt = 0;
        
        while(cnt < n/2){
            temp = temp -> next;
            cnt++;
        }
        return temp;
    }
};