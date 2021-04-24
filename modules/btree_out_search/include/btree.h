  // Copyright 2021 Kuznetsov Nikita

#ifndef MODULES_BTREE_OUT_SEARCH_INCLUDE_BTREE_H_
#define MODULES_BTREE_OUT_SEARCH_INCLUDE_BTREE_H_

struct tnode {
  int value;
  struct tnode* left;
  struct tnode* right;
};

struct tnode* addtree(struct tnode* p, int x);
bool search(struct tnode* p, int x);
void treePrint(tnode* root);
#endif  // MODULES_BTREE_OUT_SEARCH_INCLUDE_BTREE_H_
