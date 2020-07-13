#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data);
void invert(Node* root);
void printTree(Node* root);

int main(){
    Node* root = createNode(9);

    root->left = createNode(2);
    root->left->left = createNode(1);
    root->left->right = createNode(4);

    root->right = createNode(10);
    root->right->right = createNode(12);

    cout << "Inorder Traversal =>\n";
    cout << "Before Inversion:\n";
    printTree(root);
    invert(root);
    cout << "\nAfter Inversion:\n";
    printTree(root);

    return 0;
}

Node* createNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void invert(Node* root){
    if (root == NULL){
        return;
    }

    //swap all subtrees first
    invert(root->left);
    invert(root->right);

    //swap left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void printTree(Node* root){
    if(root == NULL){
        return;
    }

    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}