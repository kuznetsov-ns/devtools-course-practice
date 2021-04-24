// Copyright 2021 Kuznetsov Nikita

#include <gtest/gtest.h>
#include "include/btree.h"

TEST(BINARY_TREE, SUCCESSFUL_CREATION) {
  EXPECT_NO_THROW(tnode* root);
}

TEST(BINARY_TREE, ADD_VALUE_TO_THE_ROOT) {
  struct tnode* root;
  root = NULL;
  EXPECT_NO_THROW(root = addtree(root, 12));
}

TEST(BINARY_TREE, CAN_SEARCH) {
  tnode* root;
  root = NULL;
  int search_value = 5;
  for (int i = 0; i < 10; i++) {
    root = addtree(root, i);
  }
  EXPECT_TRUE(search(root, search_value));
}
//TEST(BINARY_TREE, CAN_SEARCH_WHEN_NOT_FOUND) {
//  tnode* root;
//  root = NULL;
//  int search_value = -15;
//  for (int i = 0; i < 100; i++) {
//    root = addtree(root, i);
//  }
//  EXPECT_FALSE(search(root, search_value));
//}
