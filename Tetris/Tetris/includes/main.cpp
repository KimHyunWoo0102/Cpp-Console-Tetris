#include<iostream>
#include"Board.h"

int main() {
	Board gameboard;

	auto board = gameboard.getBoard();

	for (const auto& row : board) {
		for (const auto& col : row) {
			if (col == CellType::WALL) {
				std::cout << "#";
			}
			else if (col == CellType::EMPTY) {
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
	return 0;
}