// using deque T.C O(N)   S.C O(N)
class Solution {
public:   
    void reorderList(ListNode* head) {
        deque<int>q;
        ListNode*temp = head;
        
        while(temp) {
            q.push_back(temp -> val);
            temp = temp -> next;
        }
        
        temp = head;
        int i = 1;
        while(temp) {
            if(i % 2 == 0) {
                temp -> val=q.back();
                q.pop_back();
            }
            else{
                temp->val = q.front();
                q.pop_front();
            }
            i++;
            temp = temp->next;
        }        
    }
};



