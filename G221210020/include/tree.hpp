/**
* @file tree.hpp
* @description Dosyadan okunan karakterlerin saklandığı ağaç sınıfı
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once
#include "tree_node.hpp"

class Tree {
protected:
	TreeNode *head = nullptr;

public:
	TreeNode *root() const;
	bool empty() const;

	int getDepth() const;
	TreeNode *selectAtDepth(int depth, int selection);

    void add(char val);

	int getTotalValue() const;
	void mirror();

	void print();

	Tree();
	~Tree();
};