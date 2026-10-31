/**
* @file main.cpp
* @description Ayarüz kodunun saklandığı dosya
* @course 2. Öğretim B Grubu
* @assignment 2. Ödev
* @date 22/12/2024
* @author G221210020 - Ayhan Dalkıran - g221210020@sakarya.edu.tr
*/
#include <fstream>
#include <iostream>
#include <sstream>

#include "linked_list.hpp"

auto tree_list = LinkedList();

void readTrees() {
	auto file = std::ifstream("./agaclar.txt");
	file >> std::skipws;

	auto buffer = std::istringstream();
	buffer >> std::skipws;

	std::string line;
	while (std::getline(file, line)) {
		if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
			continue;
		}

		buffer.clear();
		buffer.str(line);

		auto tree = new Tree();
		char val;
		while (buffer >> val) {
			tree->add(val);
		}
		tree_list.add(tree);
	}
}

void resetStream(std::istream &s) {
	s.clear();
	s.ignore(LLONG_MAX, '\n');
}

int main() {
	readTrees();
	int pos = 0;

	while (true) {
		system("cls");
		if (tree_list.length() != 0) {
			tree_list.printAt(pos);
		}
		std::cout << "[A/D] Move Left/Right" << std::endl;
		std::cout << "[S] Delete Tree" << std::endl;
		std::cout << "[W] Mirror Tree" << std::endl;
		std::cout << "[E] Exit" << std::endl;

		while (true) {
			std::cout << "Select Command: ";
			std::string command;
			if (!(std::cin >> command)) {
				std::cout << "input error: failed to read command" << std::endl;
				resetStream(std::cin);
				continue;
			}

			if (command.length() != 1) {
				std::cout << "input error: invalid command" << std::endl;
				continue;
			}

			char selection = toupper(command.at(0));

			if (selection == 'A') {
				if (pos > 0) {
					pos -= 1;
				}
				break;
			}
			else if (selection == 'D') {
				if (pos < tree_list.length() - 1) {
					pos += 1;
				}
				break;
			}
			else if (selection == 'S') {
				if (tree_list.length() == 0) {
					break;
				}

				tree_list.removeAt(pos);

				if (pos != 0) {
					pos -= 1;
				}
				break;
			}
			else if (selection == 'W') {
				if (tree_list.length() == 0) {
					break;
				}

				tree_list.at(pos)->value->mirror();
				break;
			}
			else if (selection == 'E') {
				return 0;
			}
			else {
				std::cout << "input error: invalid command" << std::endl;
			}
		}
	}

	return 0;
}