#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int main(){
    struct Node* root = new Node(1);
    cout<<root->data<<" ";
    root->left = new Node(2);
    cout<<root->left->data<<" ";
    root->right = new Node(3);
    cout<<root->right->data<<" ";
    root->left->right = new Node(5);
    cout<<root->left->right->data<<" ";
    return 0;

}