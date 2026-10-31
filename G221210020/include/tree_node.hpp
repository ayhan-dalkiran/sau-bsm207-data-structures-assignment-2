/**
* @file tree_node.hpp
* @description Tree ağaç sınıfının düğüm sınıfı
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once

class TreeNode {
public:
    char value;

	TreeNode *parent;
	TreeNode *left;
    TreeNode *right;

	void add(char val);
	int getDepth(int current) const;
	TreeNode *selectAtDepth(int depth, int selection);
	int getSubTotalValue() const;
	void mirror();

    TreeNode(char val, TreeNode *parent, TreeNode *left, TreeNode *right);
	~TreeNode();
};