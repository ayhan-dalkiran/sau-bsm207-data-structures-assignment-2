/**
* @file linked_list.hpp
* @description Dosyadan okunan ağaçlaranın saklandığı bağlı liste sınıfı
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once
#include "list_node.hpp"

class LinkedList {
protected:
    ListNode *head = nullptr;
	int count = 0;

public:
    ListNode *first() const;
	ListNode *last() const;
	int length() const;
	bool empty() const;

	ListNode *at(int pos) const;

    void add(Tree *tree);
	void removeAt(int pos);

	void printAt(int pos);

    LinkedList();
	~LinkedList();
};