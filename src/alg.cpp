// Copyright 2025 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);
  if (!file) return;

  std::string word;
  char ch;
  while (file.get(ch)) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      word += std::tolower(ch);
    } else {
      if (!word.empty()) {
        tree.add(word);
        word.clear();
      }
    }
  }
  if (!word.empty()) {
    tree.add(word);
  }
  file.close();
}

void printFreq(BST<std::string>& tree) {
  auto freq = tree.getFreq();
  for (const auto& p : freq) {
    std::cout << p.first << " " << p.second << std::endl;
  }
}
