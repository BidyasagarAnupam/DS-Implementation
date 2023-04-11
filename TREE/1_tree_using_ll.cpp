#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *create() {
    int x;
    node *newNode = new node;
    cout << "Enter the data(-1 for no node): ";
    cin >> x;
    if (x == -1) return NULL;
    newNode->data = x;
    cout << "Enter left child of " << x << endl;
    newNode->left = create();
    cout << "Enter the right child of " << x << endl;
    newNode->right = create();
    return newNode;
}
void preorder(node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node *root = NULL;
    root = create();
    cout << "Preorder is : ";
    preorder(root);
    cout<<endl;
    cout<<"Post order is: ";
    postorder(root);
    cout<<endl;
    cout<<"In order is: ";
    inorder(root);

    return 0;
}