#ifndef BST_HPP
# define BST_HPP

#include <stdlib.h>

namespace ft
{
    // template <class BST>
    struct BST
    {
        //RBT properties :
        //1. Red/Black Property: Every node is colored, either red or black.
        //2. Root Property: The root is black.
        //3. Leaf Property: Every leaf (NIL) is black.
        //4. Red Property: If a red node has children then, the children are always black.
        //5. Depth Property: For each node, any simple path from this node to any of its descendant
        //   leaf has the same black-depth (the number of black nodes).

        // *RBT parent;
        BST *RootPTR;
        BST *left; //child 1
        BST *right;//child 2
        int value;
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

       BST *CreateNewNode(int value){
         RootPTR = new(BST);
         RootPTR->value = value;
         RootPTR->left = NULL;
         RootPTR->right = NULL;
         return (RootPTR);
       }

        BST *insertion(BST *root, int value)
        {
          if (root == NULL)
            root = CreateNewNode(value);
          else if (value <= root->value)
            root->left = insertion(root->left, value);
          else
            root->right = insertion(root->right, value);
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
         while (root->left != NULL)
          root = root->left;
          return root;
       }

        BST *deletion(BST *root, int value)
        {
          if (root == NULL)
            return root;
          else if (value < root->value)
            root->left = deletion(root->left, value);
          else if (value > root->value)
            root->right = deletion(root->right, value);
          else
          {
            if (root->right == NULL && root->left == NULL){ // no child
              delete root;
              root = NULL;
              return root;
            }
            else if (root->right == NULL){ // 1 child
              BST *tmp = root;
              root = root->left;
              delete tmp;
              return root;
            }
            else if (root->left == NULL){
              BST *tmp = root;
              root = root->right;
              delete tmp;
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

        // *BST next()
        // {

        // }

        // *BST prev()
        // {

        // }
    };

}

#endif