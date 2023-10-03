class Solution {
public:

    int len(ListNode* head){
        if(head->next == NULL){
            return 1;
        }
        if (head == NULL){
            return 0;
        }
        int i = 0;
        while(head!=NULL){
            head = head-> next;
            i++;
        }
        return i;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int l = len(temp);
        int mid = (l/2 )+ 1;
        int i = 0;
        while(temp!=NULL){
            if(i == mid-2){
                head = temp -> next;
            }
            i++;
            temp = temp-> next;
        }
        return head;
    }
};