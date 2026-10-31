/**
* @file linked_list.cpp
* @description Dosyadan okunan ağaçlaranın saklandığı bağlı liste sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>

#include "linked_list.hpp"

ListNode *LinkedList::first() const {
	return this->head;
}

ListNode *LinkedList::last() const {
	return this->at(this->length() - 1);
}

int LinkedList::length() const {
	return this->count;
}

bool LinkedList::empty() const {
	return this->length() == 0;
}

ListNode *LinkedList::at(int pos) const {
	if (this->empty()) {
		throw std::string("list is empty");
	}

	if (pos < 0 || pos >= this->length()) {
		throw std::string("value must be within range [0, ") + std::to_string(this->length() - 1) + "]";
	}

	auto *it = this->first();
	for (int i = 0; i < pos; i++) {
		it = it->next;
	}

	return it;
}

void LinkedList::add(Tree *tree) {
	auto *node = new ListNode(tree, nullptr);

	if (this->empty()) {
		this->head = node;
	}
	else {
		this->last()->next = node;
	}

	count += 1;
}

void LinkedList::removeAt(int pos) {
	if (this->empty()) {
		throw std::string("list is empty");
	}

	if (pos < 0 || pos >= this->length()) {
		throw std::string("value must be within range [0, ") + std::to_string(this->length() - 1) + "]";
	}

	if (pos == 0) {
		auto *node = this->first();
		this->head = node->next;
		delete node;
	} else {
		auto *prev_node = this->at(pos - 1);
		auto *node = this->at(pos);
		prev_node->next = node->next;
		delete node;
	}

	count -= 1;
}

void LinkedList::printAt(int pos) {
	static constexpr int LEFT_PADDING = 3;
	static constexpr int NODE_REGISTER_WIDTH = 16 + 2; //+2 due to 0x at front
	static constexpr int NODE_GAP = 1;
	static constexpr int NODE_COUNT = 10;

	int s_pos = pos - (pos % NODE_COUNT);
	int e_pos = this->length() - s_pos <= NODE_COUNT ? this->length() - 1 : s_pos + NODE_COUNT - 1;
	auto *s_it = this->at(s_pos);
	ListNode *it;

	//Separator Lines
	std::string separators = std::string(LEFT_PADDING, ' ');
	for (int i = s_pos; i <= e_pos; i++) {
		separators += std::string(NODE_REGISTER_WIDTH + 2, '.');
		separators += std::string(NODE_GAP, ' ');
	}

	//Ceilings
	std::cout << separators;
	std::cout << std::endl;

	//Addresses
	it = s_it;
	std::cout << std::hex;
	std::cout << std::string(LEFT_PADDING, ' ');
	for (int i = s_pos; i <= e_pos; i++) {
		std::cout << '.';
		std::cout << std::setw(NODE_REGISTER_WIDTH) << it;
		std::cout << '.';
		std::cout << std::string(NODE_GAP, ' ');
		it = it->next;
	}
	std::cout << std::endl;

	//First Separators
	std::cout << separators;
	std::cout << std::endl;

	//Tree Values
	it = s_it;
	std::cout << std::dec;
	std::cout << std::string(LEFT_PADDING, ' ');
	for (int i = s_pos; i <= e_pos; i++) {
		std::cout << '.';
		std::cout << std::setw(NODE_REGISTER_WIDTH) << it->value->getTotalValue();
		std::cout << '.';
		std::cout << std::string(NODE_GAP, ' ');
		it = it->next;
	}
	std::cout << std::endl;

	//Second Separators
	std::cout << separators;
	std::cout << std::endl;

	//Next Addresses
	it = s_it;
	std::cout << std::hex;
	std::cout << std::string(LEFT_PADDING, ' ');
	for (int i = s_pos; i <= e_pos; i++) {
		std::cout << '.';
		std::cout << std::setw(NODE_REGISTER_WIDTH) << it->next;
		std::cout << '.';
		std::cout << std::string(NODE_GAP, ' ');
		it = it->next;
	}
	std::cout << std::endl;

	//Floors
	std::cout << separators;
	std::cout << std::endl;

	//Arrows
	int offset = LEFT_PADDING + ((NODE_REGISTER_WIDTH + 2 + NODE_GAP) * (pos - s_pos));
	std::cout << std::string(offset, ' ');
	std::cout << std::string(NODE_REGISTER_WIDTH + 2, '^');
	std::cout << std::endl;
	std::cout << std::string(offset, ' ');
	std::cout << std::string(NODE_REGISTER_WIDTH + 2, '|');
	std::cout << std::endl;
	std::cout << std::endl;

	//Tree Printing
	this->at(pos)->value->print();
	std::cout << std::endl;
	std::cout << std::dec;
}

LinkedList::LinkedList() {}
LinkedList::~LinkedList() {
	if (this->empty()) {
		return;
	}

	for (auto *it = this->first(); it != nullptr; it = it->next) {
		delete it;
	}
}
