#ifndef BST_HPP
# define BST_HPP

#include <iostream>
#include "utils.hpp"

namespace ft
{
    template <class T, class Compare = ft::less<T> >
    struct BST
    {
          typedef T value_type;

          BST *parent;
          BST *left;
          BST *right;
          value_type value;
          bool is_end;
          std::allocator<BST> alloc;
          Compare comp;

            BST *CreateNewNode(value_type value){
            BST *newNode = alloc.allocate(1);
            newNode->value = value;
            newNode->left = NULL;
            newNode->parent = NULL;
            newNode->is_end = false;
            newNode->right = NULL;
            return (newNode);
          }

          ft::pair<BST*, bool> insertion(BST *root, value_type value)
          {
            if (root == NULL || root->is_end == true)
              root = CreateNewNode(value);
            else if (comp(value.first,root->value.first))
            {
              root->left = insertion(root->left, value).first;
              root->left->parent = root;
            }
            else if (comp(root->value.first,value.first)){
              root->right = insertion(root->right, value).first;
              root->right->parent = root;
            }
            else
              return ft::make_pair(root, false);
            return ft::make_pair(root, true);
          }

          BST *FindMin(BST *root){
            if (root && root->is_end == false)
              while (root->left != NULL)
                root = root->left;
            return root;
          }

          BST *FindMin(BST *root) const{
            if (root && root->is_end == false)
              while (root->left != NULL)
                root = root->left;
            return root;
          }

          BST *FindMax(BST *root){
            if (root && root->is_end == false)
              while (root->right != NULL && root->right->is_end == false)
                root = root->right;
            return root;
          }

          BST *FindMax(BST *root) const{
            if (root && root->is_end == false)
              while (root->right != NULL && root->right->is_end == false)
                root = root->right;
            return root;
          }

          BST *deletion(BST *root, value_type value)
          {
            if (root == NULL)
              return root;
            else if (comp(value.first,root->value.first))
              root->left = deletion(root->left, value);
            else if (comp(root->value.first,value.first))
              root->right = deletion(root->right, value);
            else
            {

              if (root->right == NULL && root->left == NULL){
                alloc.destroy(root);
                alloc.deallocate(root, 1);
                root = NULL;
                return root;
              }
              else if (root->right == NULL){
                BST *tmp = root;
                if (root->parent)
                  root->left->parent = root->parent;
                else
                  root->left->parent = NULL;
                root = root->left;
                alloc.destroy(tmp);
                alloc.deallocate(tmp, 1);
                tmp = NULL;
                return root;
              }
              else if (root->left == NULL){
                BST *tmp = root;
                if (root->parent)
                  root->right->parent = root->parent;
                else
                  root->right->parent = NULL;
                root = root->right;
                alloc.destroy(tmp);
                alloc.deallocate(tmp, 1);
                tmp = NULL;
                return root;
              }
              else{
                BST *tmp = FindMin(root->right);
                root->value = tmp->value;
                root->right = deletion(root->right, tmp->value);
              }
            }
            return root;
          }
    };
}

#endif