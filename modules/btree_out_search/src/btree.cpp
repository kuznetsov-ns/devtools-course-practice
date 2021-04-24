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

tnode* find(tnode* r, int d) {
  if (r == NULL) {
    return NULL;
  }
  if (r->value == d) {
    return r;
  }
  if (d <= r->value) {
    if (r->left != NULL) {
      return find(r->left, d);
    } else {
      return NULL;
    }
  } else {
    if (r->right) {
      return find(r->right, d);
    } else {
      return NULL;
    }
  }
}
