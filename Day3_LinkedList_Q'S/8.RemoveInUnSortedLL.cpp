Node *removeDuplicates(Node *head){
        if(head==NULL){
            return head;
        }
        unordered_map<int , int>mp;
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
            mp[curr->data]++;
            if(mp[curr->data] > 1){ 
                Node* temp= curr;
                prev->next= curr->next;
                curr=curr->next;
                delete temp;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }