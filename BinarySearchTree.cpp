#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
   if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == nullptr) {
        node = new struct node;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }
    else if (key <= node->key) {
        node->left = insertNode(node->left, key);
    }
    return node;

}
//an additional function to support deleteNode function(to find the minimimum)
struct node *Findminimum(struct node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // base case
    if (root == NULL){
        return root;
    }
    //moving to the left tree if the given data is less than the root value
    else if (key < root-> key){
        root -> left = deleteNode(root->left , key); 
    }
    //moving to the right tree if the given data is greater than the root value
    else if (key > root-> key){
        root->right = deleteNode(root->right , key);
    }
    else{
        //case 1: no child
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        //case 2: only one child
        else if(root->left == NULL){
            node* temp = root;
            root = root-> right;
            delete temp;

        }
        else if(root->right == NULL){
            node* temp = root;
            root = root->left;
            delete temp;

        }

        //case 3: two children
        else{
            node* temp = Findminimum(root->right);
            
        }

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