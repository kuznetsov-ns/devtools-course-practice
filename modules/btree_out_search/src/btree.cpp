// Copyright 2021 Kuznetsov Nikita

#include <queue>
#include "include/btree.h"

struct tnode* addtree(struct tnode* p, int x) {
  if (p == NULL) {
    p = (struct tnode*)malloc(sizeof(struct tnode));
    p->value = x;
    p->left = p->right = NULL;
  }
  else if (x < p->value) {
    p->left = addtree(p->left, x);
  } else {
    p->right = addtree(p->right, x);
  }
  return p;
}

bool search(struct tnode* p, int x) {
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

void treePrint(tnode* root) {
  if (root == NULL) {
    return;
  }
  std::queue<tnode*> q;
  q.push(root);
  while (!q.empty()) {
    tnode* temp = q.front();
    q.pop();
    std::cout << temp->value << " ";
    if (temp->left != NULL)
      q.push(temp->left);
    if (temp->right != NULL)
      q.push(temp->right);
  }
}
