  // Copyright 2021 Kuznetsov Nikita

#include <malloc.h>

#include "include/btree.h"

tnode* addtree(tnode* tree, int val) {
  if (tree == NULL) {
    tree = new tnode;
    tree->value = val;
    tree->left = tree->right = NULL;
  } else if (val < tree->value) {
    tree->left = addtree(tree->left, val);
  } else {
    tree->right = addtree(tree->right, val);
  }
  return tree;
}

tnode* find(tnode* tree, int val) {
  if (tree == NULL) {
    return NULL;
  }
  if (tree->value == val) {
    return tree;
  }
  if (val <= tree->value) {
    if (tree->left != NULL) {
      return find(tree->left, val);
    } else {
      return NULL;
    }
  } else {
    if (tree->right) {
      return find(tree->right, val);
    } else {
      return NULL;
    }
  }
}
