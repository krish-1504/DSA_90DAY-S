class Solution {
public:
    bool FloydCycleDetection(ListNode* head) {
        if (head == NULL){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL &&fast != NULL && fast->next !=NULL){
            fast = fast-> next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};