/**
* @file list_node.hpp
* @description LinkedList bağlı liste sınıfının düğüm sınıfı
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#pragma once
#include "tree.hpp"

class ListNode {
public:
    Tree *value;
    ListNode *next;

    ListNode(Tree *value, ListNode *next);
	~ListNode();
};