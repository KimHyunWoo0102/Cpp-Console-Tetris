#include "Board.h"

Board::Board(int height, int width)
	:height(height),width(width)
{
	Init();
}

void Board::Init()
{
	this->_board.resize(height);

	for (int i = 0; i < this->height; ++i) {
		this->_board[i].resize(this->width);
	}

	for (int row = 0; row < this->height; row++) {
		this->_board[row][0] = CellType::WALL;
		this->_board[row][this->width - 1] = CellType::WALL;
	}

	for (int col = 0; col < this->width; col++) {
		this->_board[this->height - 1][col] = CellType::WALL;
	}
}