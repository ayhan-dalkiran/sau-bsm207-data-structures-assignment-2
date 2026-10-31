/**
* @file tree.cpp
* @description Dosyadan okunan karakterlerin saklandığı ağaç sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include <iostream>

#include "tree.hpp"

TreeNode *Tree::root() const {
	return this->head;
}

bool Tree::empty() const {
	return this->root() == nullptr;
}

int Tree::getDepth() const {
	if (!this->empty()) {
		return this->root()->getDepth(0);
	} else {
		return 0;
	}
}

TreeNode *Tree::selectAtDepth(int depth, int selection) {
	if (!this->empty()) {
		return this->root()->selectAtDepth(depth, selection);
	} else {
		return nullptr;
	}
}

void Tree::add(char val) {
	if (this->empty()) {
		auto *node = new TreeNode(val, nullptr, nullptr, nullptr);
		this->head = node;
	} else {
		this->root()->add(val);
	}
}

int Tree::getTotalValue() const {
	if (!this->empty()) {
		return this->root()->value + this->root()->getSubTotalValue();
	} else {
		return 0;
	}
}

void Tree::mirror() {
	if (!this->empty()) {
		this->root()->mirror();
	}
}

void Tree::print() {
	static const int LEFT_PADDING = 3;
	static const int BOTTOM_NODE_GAP = 1;

	if (this->empty()) {
		return;
	}

	int total_depth = this->getDepth();
	int base_width = ((1 << total_depth) * (BOTTOM_NODE_GAP + 1)) - BOTTOM_NODE_GAP;

	//Printing root value
	std::cout << std::string(LEFT_PADDING + (base_width >> 1), ' ');
	std::cout << this->root()->value;
	std::cout << std::endl;

	for (int i = 1; i <= total_depth; i++) {
		int chunk_width = base_width >> (i + 1);

		//Printing shoulders, as I like to call them
		std::cout << std::string(LEFT_PADDING, ' ');
		for (int j = 0; j < (1 << i); j += 2) {
			std::cout << std::string(chunk_width, ' ');
			auto *ls = this->selectAtDepth(i, j);
			auto *rs = this->selectAtDepth(i, j + 1);

			if (ls == nullptr) {
				std::cout << std::string(chunk_width + 1, ' ');
			} else {
				std::cout << std::string(chunk_width + 1, '.');
			}

			if (ls == nullptr && rs == nullptr) {
				std::cout << ' ';
			} else {
				std::cout << '.';
			}

			if (rs == nullptr) {
				std::cout << std::string(chunk_width + 1, ' ');
			} else {
				std::cout << std::string(chunk_width + 1, '.');
			}

			std::cout << std::string(chunk_width + 1, ' ');
		}
		std::cout << std::endl;

		//Printing arms
		std::cout << std::string(LEFT_PADDING, ' ');
		for (int j = 0; j < (1 << i); j += 2) {
			std::cout << std::string(chunk_width, ' ');
			auto *ls = this->selectAtDepth(i, j);
			auto *rs = this->selectAtDepth(i, j + 1);

			if (ls == nullptr) {
				std::cout << std::string(chunk_width + 1, ' ');
			} else {
				std::cout << '.';
				std::cout << std::string(chunk_width, ' ');
			}

			std::cout << ' ';

			if (rs == nullptr) {
				std::cout << std::string(chunk_width + 1, ' ');
			} else {
				std::cout << std::string(chunk_width, ' ');
				std::cout << '.';
			}

			std::cout << std::string(chunk_width + 1, ' ');
		}
		std::cout << std::endl;

		//Printing values
		std::cout << std::string(LEFT_PADDING, ' ');
		for (int j = 0; j < (1 << i); j += 2) {
			std::cout << std::string(chunk_width, ' ');
			auto *ls = this->selectAtDepth(i, j);
			auto *rs = this->selectAtDepth(i, j + 1);

			if (ls == nullptr) {
				std::cout << std::string(chunk_width + 1, ' ');
			} else {
				std::cout << ls->value;
				std::cout << std::string(chunk_width, ' ');
			}

			std::cout << ' ';

			if (rs == nullptr) {
				std::cout << std::string(chunk_width + 1, ' ');
			} else {
				std::cout << std::string(chunk_width, ' ');
				std::cout << rs->value;
			}

			std::cout << std::string(chunk_width + 1, ' ');
		}
		std::cout << std::endl;
	}
}

Tree::Tree() {}
Tree::~Tree() {
	if (!this->empty()) {
		delete this->root();
	}
}
