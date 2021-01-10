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
	// ���� ��� ���� ���� ǥ��
	class Tetromino* m_pCurTetromino;

	// ������ ����� ���� ǥ��
	class Tetromino* m_pNextTetromino;

	// ������ ������ ���ؽð�
	int m_iSpeed;

public:
	void UpdatePos(); // ������ ������ update
	void Render(); // ȭ�� ��� �Լ�
	class Tetromino* CreateRandomTetromino();
	class Tetromino* CreateTetromino(TETROMINO_TYPE eType);
};