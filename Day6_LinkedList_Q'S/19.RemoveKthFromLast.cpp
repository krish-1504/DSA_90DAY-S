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

    int getlength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        int len = getlength(head);
        if(len == n){
            return head -> next;
        }
        int remove = len - n;
        len = 1;
        ListNode* temp = head;
        while(len != remove){
            len ++;
            temp = temp -> next;
        }
        temp-> next = temp -> next -> next;
        return head;
    }
};