// Copyright 2025 NNTU-CS
#include <iostream>
#include <fstream>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;
  makeTree(tree, "src/war_peace.txt");

  std::ofstream out("result/freq.txt");
  auto freq = tree.getFreq();
  for (const auto& p : freq) {
    out << p.first << " " << p.second << std::endl;
  }
  out.close();

  printFreq(tree);
  return 0;
}
