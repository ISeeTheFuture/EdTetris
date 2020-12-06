#include "Stage.h"
#include "Core.h"
#include "Tetromino.h"

CStage::CStage() : m_iSpeed(2) {
}

CStage::~CStage() {
}

void CStage::AddBlock(Tetromino* pShape, const POSITION& tPos) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (pShape->GetBlock(j, i) == '0') { // 블럭일 경우
				m_Stage[tPos.y - (3 - i)][tPos.x + j] = '0';


				bool bLine = true;
				// 현재 줄 체크
				for (int k = 0; k < STAGE_WIDTH; ++k) {
					if (m_Stage[tPos.y - (3 - i)][k] != '0') {
						bLine = false;
						break;
					}
				}
				if (bLine) { // 현재 줄이 모두 블럭?
					for (int k = tPos.y - (3 - i); k > 0; --k) {
						for (int l = 0; l < STAGE_WIDTH; ++l) {
							m_Stage[k][l] = m_Stage[k - 1][l]; // 현재 줄을 그 상위의 줄로 대체
						}
					}
				}
			}
		}
	}
}

bool CStage::CheckBlock(int x, int y) {
	if (y == STAGE_HEIGHT) { // 바닥에 닿았을 때 true
		return true;
	}

	else if (x < 0 || x >= STAGE_WIDTH) {
		return true;
	}

	return m_Stage[y][x] == '0';
}

bool CStage::Init() {
	for (int i = 0; i < STAGE_HEIGHT; ++i) {
		for (int j = 0; j < STAGE_WIDTH; ++j) {
			m_Stage[i][j] = '1';
		}
	}

	return true;
}

void CStage::Render() {
	for (int i = 0; i < STAGE_HEIGHT + 1; ++i) {
		for (int j = 0; j < STAGE_WIDTH + 2; ++j) {
			if (i == 0 && (j == 0 || j == STAGE_WIDTH + 1)) {
				cout << "■";
			}
			else if (j == 0) {
				cout << "■";
			}
			else if (i == STAGE_HEIGHT) {
				cout << "■";
			}
			else if (j == STAGE_WIDTH + 1) {
				cout << "■";
			}
			else {
				if (m_Stage[i][j - 1] == '1') {
					cout << "  ";
				}
				else {
					cout << "■";
				}
			}
		}
		cout << endl;
	}

	// 다음 도형 미리보기
	for (int i = 0; i < 7; ++i) {
		CCore::GetInst()->SetConsolePos(17, i);
		cout << "■";
	}
	for (int i = 0; i < 6; ++i) {
		CCore::GetInst()->SetConsolePos(11 + i, 6);
		cout << "■";
	}
}
