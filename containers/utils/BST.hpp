#ifndef BST_HPP
# define BST_HPP

#include <stdlib.h>
#include <iostream>

namespace ft
{
    // template <class BST>
    template <class T, class Compare = std::less<T> >
    // template <class T, class Compare = std::less<T>, class Node = ft::BST<T>,
		// 	class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    struct BST
    {
          //RBT properties :
          //1. Red/Black Property: Every node is colored, either red or black.
          //2. Root Property: The root is black.
          //3. Leaf Property: Every leaf (NIL) is black.
          //4. Red Property: If a red node has children then, the children are always black.
          //5. Depth Property: For each node, any simple path from this node to any of its descendant
          //   leaf has the same black-depth (the number of black nodes).
          typedef T   value_type;

          BST *parent;
          BST *left; //child 1
          BST *right;//child 2
          value_type value;
          // int color; //1=red  0=black

          // RBT() : parent(), left(), right(){}

          // ~RBT(){}

          /*
            Insert
            1. Find the good path to put the key
            2. Insert it.
            3. If properties violated, fix it
            4. Return a pointer on the root
          */

          BST *CreateNewNode(value_type value){
            BST* newNode = new(BST); // a modif (use alloc)
            // BST *newNode = Node_Alloc.allocate(1);
            newNode->value = value;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = NULL;
            return (newNode);
          }

          BST *insertion(BST *root, value_type value)
          {
            if (root == NULL){
              parent = NULL;
              root = CreateNewNode(value);
            }
            else if (value.first < root->value.first)
            {
              root->left = insertion(root->left, value);
              root->left->parent = root;
            }
            else if (value.first > root->value.first){
              root->right = insertion(root->right, value);
              root->right->parent = root;
            }
            return root;
          }

          // void fixInsert()
          // {

          // }

          /*
            Delete
            1. Search for the key in the BST
            2. Delete it
            3. Replace it by another key (not understand which one yet)
            4. If properties violated, fix it
            5. Return a pointer on the root
          */

          BST *FindMin(BST *root){
            if (root)
              while (root->left != NULL)
                root = root->left;
            return root;
          }
          
          BST *FindMin(BST *root) const{
            if (root)
              while (root->left != NULL)
                root = root->left;
            return root;
          }

          BST *FindMax(BST *root){
            if (root)
              while (root->right != NULL)
                root = root->right;
            return root->right;
          }

          BST *FindMax(BST *root) const{
            if (root)
              while (root->right != NULL)
                root = root->right;
            return root->right;
          }

          BST *deletion(BST *root, value_type value)
          {
            if (root == NULL)
              return root;
            else if (value.first < root->value.first)
              root->left = deletion(root->left, value);
            else if (value.first > root->value.first)
              root->right = deletion(root->right, value);
            else
            {
              if (root->right == NULL && root->left == NULL){ // no child
                delete root; //
                root = NULL;
                return root;
              }
              else if (root->right == NULL){ // 1 child
                BST *tmp = root;
                root = root->left;
                delete tmp; //
                return root;
              }
              else if (root->left == NULL){
                BST *tmp = root;
                root = root->right;
                delete tmp; //
                return root;
              }
              else{ // 2 children
                BST *tmp = FindMin(root->right);
                root->value = tmp->value;
                root->right = deletion(root->right, tmp->value);
              }
            }
            return root;
          }

          // void fixDeletion()
          // {

          // }

          void swap(BST& x){
            if (&x == this)
              return ;
            
            BST* save = this;
            *this = x;
            x = *save;
          }

          // void next(){
          //   if (right == NULL && parent->value <= value)
          //     return ;
          //   else if (right)

          //   else if (parent->right)
          //   {

          //   }
          //   return ;
          // }

          // void prev(){

          // }
    };

}

#endif