/**
* @file tree_node.cpp
* @description Tree ağaç sınıfının düğüm sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include "tree_node.hpp"
#include <iostream>

void TreeNode::add(char val) {
	if (val < this->value) {
		if (this->left == nullptr) {
			this->left = new TreeNode(val, this, nullptr, nullptr);
		} else {
			this->left->add(val);
		}
	} else {
		if (this->right == nullptr) {
			this->right = new TreeNode(val, this, nullptr, nullptr);
		} else {
			this->right->add(val);
		}
	}
}

int TreeNode::getDepth(int current) const {
	int ld = current;
	int rd = current;

	if (this->left != nullptr) {
		ld = this->left->getDepth(current + 1);
	}
	if (this->right != nullptr) {
		rd = this->right->getDepth(current + 1);
	}

	return ld >= rd ? ld : rd;
}

TreeNode *TreeNode::selectAtDepth(int depth, int selection) {
	if (depth < 0 || depth > 30) {
		throw std::string("depth must be within range [0, 30]");
	}

	if (depth == 0) {
		return this;
	}

	int base_count = 1 << depth;
	if (selection < 0 || selection >= base_count) {
		throw std::string("selection must be within range [0, ") + std::to_string(base_count - 1) + ']';
	}

	if ((selection >> (depth - 1)) == 0) {
		if (this->left == nullptr) {
			return nullptr;
		} else {
			return this->left->selectAtDepth(depth - 1, selection);
		}
	} else {
		if (this->right == nullptr) {
			return nullptr;
		} else {
			return this->right->selectAtDepth(depth - 1, selection - (selection & (1 << (depth - 1))));
		}
	}
}

int TreeNode::getSubTotalValue() const {
	int val = 0;
	if (this->left != nullptr) {
		val += this->left->value * 2;
		val += this->left->getSubTotalValue();
	}
	if (this->right != nullptr) {
		val += this->right->value;
		val += this->right->getSubTotalValue();
	}
	return val;
}

void TreeNode::mirror() {
	auto *ln = this->left;
	auto *rn = this->right;
	this->left = rn;
	this->right = ln;

	if (ln != nullptr) {
		ln->mirror();
	}

	if (rn != nullptr) {
		rn->mirror();
	}
}

TreeNode::TreeNode(char value, TreeNode *parent, TreeNode *left, TreeNode *right)
	: value(value), parent(parent), left(left), right(right) {}

TreeNode::~TreeNode() {
	if (this->left != nullptr) {
		delete left;
	}

	if (this->right != nullptr) {
		delete right;
	}
}
