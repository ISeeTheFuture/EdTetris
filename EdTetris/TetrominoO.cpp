
#include "TetrominoO.h"

TetrominoO::TetrominoO() {

}

TetrominoO::~TetrominoO() {

}

bool TetrominoO::Init() {
	
	if (!Tetromino::Init()) {
		return false;
	}
	
	// ���� ���ϴ� ����
	m_tetromino[2][0] = '0';
	m_tetromino[2][1] = '0';
	m_tetromino[3][0] = '0';
	m_tetromino[3][1] = '0';

	m_iWidthCount = 2;
	m_tPos.x = 4;
	m_tPos.y = 0;

	return true;
}