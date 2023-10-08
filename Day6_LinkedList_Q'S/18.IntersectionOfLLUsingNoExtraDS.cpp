/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getlen(ListNode * head){
        int len =0;
        while(head != NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getlen(headA);
        int l2 = getlen(headB);

        int diff = (l1>=l2)?l1-l2:l2-l1;
        if(l1>=l2){
            while(l1!=l2){
                headA = headA -> next;
                l1--;
            }
        }
        else{
            while(l1!=l2){
                headB = headB -> next;
                l2--;
            }
        }

        while(headA != NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};