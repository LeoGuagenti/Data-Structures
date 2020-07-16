#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool sameTree(Node* tree_1, Node* tree_2);
void printTree(Node* root);

int main(){
    Node* tree1 = new Node(200);
    tree1->left = new Node(100);
    tree1->right = new Node(300);

    Node* tree2 = new Node(200);
    tree2->left = new Node(100);
    tree2->right = new Node(300);

    printTree(tree1); 
    cout << endl; 
    printTree(tree2);

    cout << boolalpha << "Same tree? ==> " << sameTree(tree1, tree2) << "\n\n";

    tree2->right = new Node(400);

    printTree(tree1); 
    cout << endl; 
    printTree(tree2);

    cout << boolalpha << "Same tree? ==> " << sameTree(tree1, tree2) << endl;

    return 0;
}

bool sameTree(Node* tree_1, Node* tree_2){
    if(tree_1 == NULL && tree_2 == NULL){
        return true;
    }

    if(tree_1 != NULL && tree_2 != NULL){
        bool dataValidity = (tree_1->data == tree_2->data);
        bool leftValidity = sameTree(tree_1->left, tree_2->left);
        bool rightValidity = sameTree(tree_1->right, tree_2->right);

        return (dataValidity && leftValidity && rightValidity);
    }

    return false;
}

void printTree(Node* root){
    if(root == NULL){
        return;
    }

    printTree(root->left);
    cout << root->data << endl;
    printTree(root->right);
}