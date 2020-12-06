#include "Tetromino.h"
#include "Core.h" // ��ǥ ����
#include "Stage.h"
#include "StageManager.h"

Tetromino::Tetromino() {
	m_iDir = RD_UP;
	m_iWidthCount = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_tetromino[i][j] = '1'; // �� ���� = 1; ���� �ִ� ���� = 0;
		}
	}
}

Tetromino::~Tetromino() {
}

bool Tetromino::Init() {
	// ��� ���� ���� ������
	m_tPivot.x = 0;
	m_tPivot.y = 3;

	return true;
}

void Tetromino::Rotation() {
}

void Tetromino::Render() {
	for (int i = 0; i < 4; ++i) {
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0) { // ȭ�� �ۿ��� ������ ǥ���Ǵ� �� ����
			continue;
		}

		for (int j = 0; j < 4; ++j) {
			if (m_tPos.x + j >= STAGE_WIDTH) { // ������ ���� ���̺��� �� Ŭ ��, ���� ���� �� ������ ���� ����� ��µǴ� �� ����
				continue;
			}

			if (m_tetromino[i][j] == '0') {
				CCore::GetInst()->SetConsolePos(m_tPos.x + j, iYIndex); // "�� �� ��" �ֿܼ� ����� ��ǥ�� ���� �� ���
				cout << "��";
			}
		}
		cout << endl;
	}
}

void Tetromino::RenderNext() {
	for (int i = 0; i < 4; ++i) {
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0) { // ȭ�� �ۿ��� ������ ǥ���Ǵ� �� ����
			continue;
		}

		// �ܼ� ����� ��ǥ ���� �� ���
		CCore::GetInst()->SetConsolePos(m_tPos.x, iYIndex);

		for (int j = 0; j < 4; ++j) {
			if (m_tetromino[i][j] == '0') {
				CCore::GetInst()->SetConsolePos(m_tPos.x + j, iYIndex); // "�� �� ��" �ֿܼ� ����� ��ǥ�� ���� �� ���
				cout << "��";
			}
		}
		cout << endl;
	}
}

// true : �ٴ� �Ǵ� �ٸ� ������ �浹
bool Tetromino::MoveDown() {
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (m_tetromino[i][j] == '0') { // ���� ����
				if (pStage->CheckBlock(m_tPos.x + j, m_tPos.y - (2 - i))) {
					// ���� �ٴڿ� ��Ҵµ�, ������ �Ϻ� ��ǥ�� 0���� �۴ٸ� õ���� ���� ���̹Ƿ� ���� ����
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
			if (m_tetromino[i][j] == '0') { // ���� ����
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
			if (m_tetromino[i][j] == '0') { // ���� ����
				if (pStage->CheckBlock(m_tPos.x + j + 1, m_tPos.y - (3 - i))) {
					return;
				}
			}
		}
	}
	
	++m_tPos.x;
}