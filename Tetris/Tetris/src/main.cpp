#include <iostream>
#include <chrono>   // 시간 지연을 위해 필요
#include <thread>   // 시간 지연을 위해 필요
#include "Block.h"
#include<string>
// "Board.h"는 현재 테스트에 불필요하므로 제외했습니다.

// 렌더링 함수: 블록의 모양을 콘솔에 출력
void RenderBlock(const char* title, const Block& block) {
    const auto& shape = block.GetShape();

    std::cout << "--- " << title << " ---" << std::endl;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (shape[row][col]) {
                std::cout << " ■";
            }
            else {
                std::cout << " .";
            }
        }
        std::cout << std::endl; // 줄바꿈
    }
    std::cout << "====================" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
    Pos startPos = { 0, 0 };

    std::cout << ">>> I 블록 (BlockType::I) 테스트 시작 <<<" << std::endl;
    Block i_block;
    i_block.SpawnNewBlock(BlockType::I, startPos);

    for (int i = 0; i < 4; ++i) {
        RenderBlock(("I 블록 - 회전 " + std::to_string(i * 90) + "도").c_str(), i_block);
        i_block.Rotate();
    }

    std::cout << "\n>>> T 블록 (BlockType::T) 테스트 시작 <<<" << std::endl;
    Block t_block;
    t_block.SpawnNewBlock(BlockType::T, startPos);

    for (int i = 0; i < 4; ++i) {
        RenderBlock(("T 블록 - 회전 " + std::to_string(i * 90) + "도").c_str(), t_block);
        t_block.Rotate();
    }

    return 0;
}
