#pragma once
#include<vector>

class Block;

enum class CellType {
	EMPTY=0,WALL=1,STACKED_BLOCK=2
};

// 1.Init으로 벽으로 감싼 보드 생성
// 2.isCollision 검사를 통해 다음에 문제가 생긴다면 블록을 쌓음
// 3.블록이 한줄 가득 찼다면 지우는 로직과 땡기는 로직

class Board {
public:
	Board(int height = 11, int width = 22);

	bool isCollision(Block& block);
	void cleanFullLines();
	void stackBlock(Block& block);

	//test용 getBoard
	const std::vector<std::vector<CellType>>& getBoard() const {
		return this->_board;
	}

private:
	std::vector<std::vector<CellType>>_board;
	int height;
	int width;

	void Init();

	bool isFullLine(int y);
	void cleanLine(int y);
};