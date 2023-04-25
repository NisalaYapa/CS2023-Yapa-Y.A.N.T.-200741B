#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL){
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Creating a node
struct node *createNode(int key){
    node* newNode = new node();
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    if (root == NULL) return createNode(key);
    else if (key <= root->key) root->left = insertNode(root->left,key);
    else if (key > root->key) root->right = insertNode(root->right,key);
    return root;
}

// Finding minimum node
struct node *minNode(struct node* root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key) 
        root->left = deleteNode(root->left, key);
    else if (key > root->key) 
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}



// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}