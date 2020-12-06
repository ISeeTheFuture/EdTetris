#include "Tetromino.h"
#include "Core.h" // 좌표 설정
#include "Stage.h"
#include "StageManager.h"

Tetromino::Tetromino() {
	m_iDir = RD_UP;
	m_iWidthCount = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_tetromino[i][j] = '1'; // 빈 공간 = 1; 도형 있는 공간 = 0;
		}
	}
}

Tetromino::~Tetromino() {
}

bool Tetromino::Init() {
	// 모든 도형 공통 기준점
	m_tPivot.x = 0;
	m_tPivot.y = 3;

	return true;
}

void Tetromino::Rotation() {
}

void Tetromino::Render() {
	for (int i = 0; i < 4; ++i) {
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0) { // 화면 밖에서 도형이 표현되는 것 방지
			continue;
		}

		for (int j = 0; j < 4; ++j) {
			if (m_tPos.x + j >= STAGE_WIDTH) { // 도형의 가로 길이보다 더 클 때, 도형 우측 빈 공간이 벽을 지우고 출력되는 것 방지
				continue;
			}

			if (m_tetromino[i][j] == '0') {
				CCore::GetInst()->SetConsolePos(m_tPos.x + j, iYIndex); // "각 블럭 별" 콘솔에 출력할 좌표를 설정 후 출력
				cout << "■";
			}
		}
		cout << endl;
	}
}

void Tetromino::RenderNext() {
	for (int i = 0; i < 4; ++i) {
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0) { // 화면 밖에서 도형이 표현되는 것 방지
			continue;
		}

		// 콘솔 출력할 좌표 설정 후 출력
		CCore::GetInst()->SetConsolePos(m_tPos.x, iYIndex);

		for (int j = 0; j < 4; ++j) {
			if (m_tetromino[i][j] == '0') {
				CCore::GetInst()->SetConsolePos(m_tPos.x + j, iYIndex); // "각 블럭 별" 콘솔에 출력할 좌표를 설정 후 출력
				cout << "■";
			}
		}
		cout << endl;
	}
}

// true : 바닥 또는 다른 도형과 충돌
bool Tetromino::MoveDown() {
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (m_tetromino[i][j] == '0') { // 블럭일 때만
				if (pStage->CheckBlock(m_tPos.x + j, m_tPos.y - (2 - i))) {
					// 블럭이 바닥에 닿았는데, 도형의 일부 좌표가 0보다 작다면 천장을 뚫은 것이므로 게임 종료
					for (int k = 0; k < 4; ++k) {
						for (int l = 0; l < 4; ++l) {
							if (m_tetromino[k][l] == '0') {
								if (m_tPos.y - (3 - k) < 0) {
									CCore::GetInst()->End();
									break;
								}
							}
						}
					}
					return true;
				}
			}
		}
	}
	++m_tPos.y;

	return false;
}

void Tetromino::MoveLeft() {
	if (m_tPos.x == 0) {
		return;
	}

	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (m_tetromino[i][j] == '0') { // 블럭일 때만
				if (pStage->CheckBlock(m_tPos.x + j - 1, m_tPos.y - (3 - i))) {
					return;
				}
			}
		}
	}

	--m_tPos.x;
}

void Tetromino::MoveRight() {
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH) {
		return;
	}
	
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (m_tetromino[i][j] == '0') { // 블럭일 때만
				if (pStage->CheckBlock(m_tPos.x + j + 1, m_tPos.y - (3 - i))) {
					return;
				}
			}
		}
	}
	
	++m_tPos.x;
}