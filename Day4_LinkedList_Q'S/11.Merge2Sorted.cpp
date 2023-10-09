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
    ListNode* mergesort(ListNode* &l1, ListNode* &l2){
        ListNode* prev1 = l1;
        ListNode* curr1 = l1->next;

        ListNode* prev2 = l2;
        ListNode* curr2 = l2->next;

        if(curr1 == NULL && curr2 == NULL){
            prev1 ->next = prev2;
            return l1;
        }
        
        while(prev2 != NULL ){
            if((prev1 -> val <= prev2->val && curr1 == NULL) || (prev1->val <= prev2->val && curr1->val >= prev2->val)){
                prev1 -> next = prev2;
                prev2 -> next = curr1;
                prev2 = curr2;
                if(curr2!=NULL){
                    curr2 = curr2 -> next;
                }
                prev1 = prev1->next;
            }
            else{
                prev1 = curr1;
                if(curr1 != NULL){
                    curr1 = curr1 -> next;
                }
            }
        }
        return l1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }
        if(list1->val <= list2 ->val){
            return mergesort(list1,list2);
        }
        else{
            return mergesort(list2,list1);
        }
        
    }
};