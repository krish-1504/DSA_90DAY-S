/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */


Node* sorting(Node* left,Node* right){
	if(right == NULL){
		return left;
	}
	if(left == NULL){
		return right;
	}
	Node* ans = new Node(0);
	Node* dum = ans;

	while(left != NULL && right != NULL){
		if(left -> data < right -> data){
			dum -> child = left;
			left = left -> child;
			dum = dum -> child;
		}
		else{
			dum -> child = right;
			right = right -> child;
			dum = dum -> child;
		}
	}
	if( left != NULL){
		dum -> child = left;
	}
	else{
		dum -> child = right;
	}

	Node* current = ans->child;
    while (current->child != nullptr) {
		if(current -> next != NULL){
			current -> next = NULL;
		}
        current = current->child;
    }
    current->next = nullptr;
	return ans -> child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == NULL || head -> next == NULL){
		return head;
	}
	head -> next = flattenLinkedList(head -> next);
	head = sorting(head , head -> next);

	return head;
}
