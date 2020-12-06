#include "TetrominoJ.h"

TetrominoJ::TetrominoJ() {

}

TetrominoJ::~TetrominoJ() {

}

bool TetrominoJ::Init() {

	if (!Tetromino::Init()) {
		return false;
	}

	// ���� ���ϴ� ����
	m_tetromino[2][0] = '0';
	m_tetromino[2][1] = '0';
	m_tetromino[2][2] = '0';
	m_tetromino[3][2] = '0';

	m_iWidthCount = 3;
	m_tPos.x = 4;
	m_tPos.y = 0;

	m_iDir = RD_LEFT;

	return true;
}

void TetrominoJ::Rotation() {
	++m_iDir;

	m_iDir %= RD_END; // ������ ������. �ٽ� UP���� ���ư�����

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_tetromino[i][j] = '1';
		}
	}

	switch (m_iDir) {
	case RD_UP:
		m_tetromino[1][1] = '0';
		m_tetromino[2][1] = '0';
		m_tetromino[3][0] = '0';
		m_tetromino[3][1] = '0';
		m_iWidthCount = 2;
		break;
	case RD_RIGHT:
		m_tetromino[2][0] = '0';
		m_tetromino[3][0] = '0';
		m_tetromino[3][1] = '0';
		m_tetromino[3][2] = '0';
		m_iWidthCount = 3;
		break;
	case RD_DOWN:
		m_tetromino[1][0] = '0';
		m_tetromino[1][1] = '0';
		m_tetromino[2][0] = '0';
		m_tetromino[3][0] = '0';
		m_iWidthCount = 2;
		break;
	case RD_LEFT:
		m_tetromino[2][0] = '0';
		m_tetromino[2][1] = '0';
		m_tetromino[2][2] = '0';
		m_tetromino[3][2] = '0';
		m_iWidthCount = 3;
		break;
	}
}
