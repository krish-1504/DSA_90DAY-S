class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp  =head;

        map<int,int> mp;
        while(temp!=NULL){
            mp[temp->val]++;
            temp = temp -> next;
        }

        while(curr !=NULL){
            if(mp[curr->val]>1){
                if(prev!=NULL){
                    prev -> next = curr -> next;
                }
                else{
                    head = head -> next;
                }
                curr = curr -> next;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};