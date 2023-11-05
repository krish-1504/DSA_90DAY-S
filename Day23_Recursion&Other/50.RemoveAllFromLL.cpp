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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head!=NULL && head -> val == val){
            head = head -> next;
        }
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        while(curr != NULL){
            nxt = curr -> next;
            if(curr -> val == val && prev!=NULL){
                curr -> next ==  NULL ? prev -> next = NULL : prev -> next = curr -> next;
            }else{
                prev = curr;
            }
            curr = nxt;
        }
        return head;
    }
};