// Copyright 2025 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <vector>
#include <algorithm>

template <typename T>
class BST {
 private:
  struct Node {
    T key;
    int count;
    Node* left;
    Node* right;
    Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root;

  Node* insert(Node* node, const T& key) {
    if (!node) return new Node(key);
    if (key < node->key)
      node->left = insert(node->left, key);
    else if (key > node->key)
      node->right = insert(node->right, key);
    else
      node->count++;
    return node;
  }

  int searchNode(Node* node, const T& key) const {
    if (!node) return 0;
    if (key < node->key) return searchNode(node->left, key);
    if (key > node->key) return searchNode(node->right, key);
    return node->count;
  }

  int depthNode(Node* node) const {
    if (!node) return 0;
    return 1 + std::max(depthNode(node->left), depthNode(node->right));
  }

  void collect(Node* node, std::vector<std::pair<T, int>>& v) const {
    if (!node) return;
    collect(node->left, v);
    v.push_back({node->key, node->count});
    collect(node->right, v);
  }

  void clearNode(Node* node) {
    if (!node) return;
    clearNode(node->left);
    clearNode(node->right);
    delete node;
  }

 public:
  BST() : root(nullptr) {}
  ~BST() { clearNode(root); }

  void add(const T& key) { root = insert(root, key); }
  int search(const T& key) const { return searchNode(root, key); }
  int depth() const { return depthNode(root); }

  std::vector<std::pair<T, int>> getFreq() const {
    std::vector<std::pair<T, int>> result;
    collect(root, result);
    std::sort(result.begin(), result.end(),
      [](const std::pair<T, int>& a, const std::pair<T, int>& b) {
        return a.second > b.second;
      });
    return result;
  }
};

#endif  // INCLUDE_BST_H_
