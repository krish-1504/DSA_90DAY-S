class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* temp1 = head;
        bool flag = false;
        map<int,int> dup;
        while(temp1 !=NULL){
            dup[temp1->val]++;
            
            temp1 = temp1->next;
        }
        while(temp->next!=NULL){
            if(dup[temp->next->val]>1){
                temp->next = temp ->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        while(true){
            if(head == NULL || dup[head->val]<=1){
                break;
            }
            else{
                head = head->next;
            }
        }
        return head;
    }
};