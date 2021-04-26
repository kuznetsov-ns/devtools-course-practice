// Copyright 2021 Kuznetsov Nikita

#include <gtest/gtest.h>

#include "include/btree.h"

TEST(BINARY_TREE, SUCCESSFUL_CREATION) {
  ASSERT_NO_THROW(tnode* root);
}

TEST(BINARY_TREE, ADD_VALUE_TO_THE_ROOT) {
  struct tnode* root;
  root = NULL;

  ASSERT_NO_THROW(root = addtree(root, 12));
}

TEST(BINARY_TREE, ADD_VALUE_AFTER_THE_ROOT) {
  struct tnode* root;
  root = NULL;

  root = addtree(root, 12);

  ASSERT_NO_THROW(root = addtree(root, 8));
}

TEST(BINARY_TREE, CAN_SEARCH) {
  tnode* root;
  root = NULL;
  int search_value = 5;

  for (int i = 0; i < 10; i++) {
    root = addtree(root, i);
  }

  ASSERT_TRUE(NULL != find(root, search_value));
}

TEST(BINARY_TREE, CAN_SEARCH_WHEN_NOT_FOUND) {
  tnode* root;
  root = NULL;
  int search_value = -15;

  for (int i = 0; i < 100; i++) {
    root = addtree(root, i);
  }

  ASSERT_TRUE(NULL == find(root, search_value));
}

TEST(BINARY_TREE, CANT_SEARCH_WHEN_TREE_IS_EMPTY) {
  tnode* root;
  root = NULL;
  int search_value = -15;

  ASSERT_TRUE(NULL == find(root, search_value));
}

TEST(BINARY_TREE, CAN_SEARCH2) {
  tnode* root;
  root = NULL;
  int search_value = 50;

  for (int i = 100; i > 0; i--) {
    root = addtree(root, i);
  }

  ASSERT_TRUE(NULL != find(root, search_value));
}

TEST(BINARY_TREE, CAN_SEARCH_WHEN_NOT_FOUND2) {
  tnode* root;
  root = NULL;
  int search_value = -50;

  for (int i = 100; i > 0; i--) {
    root = addtree(root, i);
  }

  ASSERT_TRUE(NULL == find(root, search_value));
}

TEST(BINARY_TREE, CORRECT_SEARCH1) {
  tnode* root;
  root = NULL;
  int search_value = 50;

  for (int i = 100; i > 0; i--) {
    root = addtree(root, i);
  }

  tnode* result = find(root, search_value);

  ASSERT_EQ(result->value, search_value);
}

TEST(BINARY_TREE, CORRECT_SEARCH2) {
  tnode* root;
  root = NULL;
  int search_value = 20;

  for (int i = 0; i < 10; i++) {
    root = addtree(root, i);
  }

  tnode* result = find(root, search_value);

  ASSERT_TRUE(result == NULL);
}
