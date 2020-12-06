#include "TetrominoI.h"

TetrominoI::TetrominoI() {

}

TetrominoI::~TetrominoI() {

}

bool TetrominoI::Init() {

	if (!Tetromino::Init()) {
		return false;
	}

	// ���� ���ϴ� ����
	m_tetromino[3][0] = '0';
	m_tetromino[3][1] = '0';
	m_tetromino[3][2] = '0';
	m_tetromino[3][3] = '0';

	m_iWidthCount = 4;
	m_tPos.x = 4;
	m_tPos.y = 0;

	m_iDir = RD_DOWN;

	return true;
}

void TetrominoI::Rotation() {
	m_iDir = m_iDir == RD_DOWN ? RD_UP : RD_DOWN; // �Լ� ������ �� �� �ϳ��� �ٲ��

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_tetromino[i][j] = '1';
		}
	}

	switch (m_iDir) {
	case RD_UP:
		m_tetromino[0][0] = '0';
		m_tetromino[1][0] = '0';
		m_tetromino[2][0] = '0';
		m_tetromino[3][0] = '0';
		m_iWidthCount = 1;
		break;
	case RD_DOWN:
		m_tetromino[3][0] = '0';
		m_tetromino[3][1] = '0';
		m_tetromino[3][2] = '0';
		m_tetromino[3][3] = '0';
		m_iWidthCount = 4;
		break;
	}
}
