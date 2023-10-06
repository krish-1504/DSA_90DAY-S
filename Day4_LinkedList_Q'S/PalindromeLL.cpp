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
    ListNode* rev(ListNode* no){
        ListNode* prev = NULL;
        ListNode* curr = no;
        ListNode* nex = NULL;
        while(curr != NULL){
            nex = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL){
            return true;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow -> next;
        }
        ListNode* re = rev(slow->next);
        slow -> next = NULL;
        while(head!=NULL){
            cout<<head->val<<" "<<re->val<<endl;
            if(head->val != re->val){
                return false;
            }
            head = head -> next;
            re = re->next;
        }

        return true;
    }
};