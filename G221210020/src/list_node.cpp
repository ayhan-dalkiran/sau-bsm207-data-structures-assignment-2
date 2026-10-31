/**
* @file list_node.cpp
* @description LinkedList bağlı liste sınıfının düğüm sınıfının uygulaması
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include "list_node.hpp"

ListNode::ListNode(Tree *value, ListNode *next)
	: value(value), next(next) {}

ListNode::~ListNode() {
	delete this->value;
}
