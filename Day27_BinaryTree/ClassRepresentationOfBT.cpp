#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        left = right = NULL;
    }
};
int main(){
    Node* root = new Node(1);
    cout<<root->data<<" ";
    root->left = new Node(2);
    cout<<root->left->data<<" ";
    root -> right = new Node(3);
    cout<<root->right->data<<" ";
    root->left->right = new Node(5);
    cout<<root->left->right->data<<" ";
    return 0;
}