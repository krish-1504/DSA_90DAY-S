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
    int len(ListNode* head){
        int i=0;
        while(head !=NULL){
            i++;
            head = head -> next;
        }
        return i;
    }
    ListNode* reverse(ListNode* head, int k ,int length){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int c = 0 ;
        while(curr != NULL && c != k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            c++;
        }
        length = (length-k);
        if(next != NULL && (length>=k)){
            head -> next = reverse(next,k,length);
        }
        else{
            head -> next = next;
        }
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k ) {
        int l = len(head);
        return reverse(head,k,l);
        
    }
};