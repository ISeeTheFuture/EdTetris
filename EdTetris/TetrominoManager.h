#pragma once

#include "value.h"

class TetrominoManager {
private:
	TetrominoManager();
	~TetrominoManager();

private:
	static TetrominoManager* m_pInst;

public:
	static TetrominoManager* GetInst() {
		if (!m_pInst) {
			m_pInst = new TetrominoManager;
		}
		return m_pInst;
	}

	static void DestroyInst() {
		if (m_pInst) {
			delete m_pInst;
			m_pInst = NULL;
		}
	}

private:
	// 현재 출력 중인 도형 표현
	class Tetromino* m_pCurTetromino;

	// 다음에 출력할 도형 표현
	class Tetromino* m_pNextTetromino;

	// 도형이 움직일 기준시간
	int m_iSpeed;

public:
	void UpdatePos(); // 도형의 움직임 update
	void Render(); // 화면 출력 함수
	class Tetromino* CreateRandomTetromino();
	class Tetromino* CreateTetromino(TETROMINO_TYPE eType);
};