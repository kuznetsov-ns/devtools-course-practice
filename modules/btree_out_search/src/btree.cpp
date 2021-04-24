  // Copyright 2021 Kuznetsov Nikita

#include <malloc.h>
#include "include/btree.h"

tnode* addtree(tnode* p, int x) {
  if (p == NULL) {
    p = new tnode;
    p->value = x;
    p->left = p->right = NULL;
  } else if (x < p->value) {
    p->left = addtree(p->left, x);
  } else {
    p->right = addtree(p->right, x);
  }
  return p;
}

bool search(tnode* p, int x) {
  if (p != NULL) {
    if (x == p->value) {
      return true;
    } else {
      search(p->left, x);
      search(p->right, x);
    }
  } else {
    return false;
  }
}
