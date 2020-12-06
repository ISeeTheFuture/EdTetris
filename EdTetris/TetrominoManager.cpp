#include "TetrominoManager.h"
#include "TetrominoI.h"
#include "TetrominoJ.h"
#include "TetrominoL.h"
#include "TetrominoO.h"
#include "TetrominoS.h"
#include "TetrominoT.h"
#include "TetrominoZ.h"
#include "StageManager.h"
#include "Stage.h"

TetrominoManager* TetrominoManager::m_pInst = NULL;

TetrominoManager::TetrominoManager() : m_pCurTetromino(NULL), m_pNextTetromino(NULL) {
	m_pCurTetromino = CreateRandomTetromino();
	m_pNextTetromino = CreateRandomTetromino();
	m_iSpeed = 0;
}

TetrominoManager::~TetrominoManager() {
	SAFE_DELETE(m_pCurTetromino);
	SAFE_DELETE(m_pNextTetromino);
}

void TetrominoManager::UpdatePos() {
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();

	++m_iSpeed;

	if (pStage->GetSpeed() == m_iSpeed) {
		if (m_pCurTetromino->MoveDown()) { // true�� ��� �ٴ��̹Ƿ� ����Ʈ�� �߰� �� ���� ������ ���� �������� ����. ���� �ٽ� ���� ������ ����.
			// ����� �� �� �߰�.
			pStage->AddBlock(m_pCurTetromino, m_pCurTetromino->GetPosition());
			
			SAFE_DELETE(m_pCurTetromino);
			
			m_pCurTetromino = m_pNextTetromino;
			m_pCurTetromino->SetPosition(4, 0); // ���ο� ���� ������ ��ġ�� �ʱ�ȭ.

			m_pNextTetromino = CreateRandomTetromino();
		}
		m_iSpeed = 0;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) { // �¿� �������� ��� ����
		m_pCurTetromino->MoveLeft();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		m_pCurTetromino->MoveRight();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		m_pCurTetromino->Rotation();
	}
}

void TetrominoManager::Render() {
	m_pCurTetromino->Render(); // ���� ���

	m_pNextTetromino->SetPosition(12, 4);
	m_pNextTetromino->RenderNext(); // �̸����� ���� ���
}

Tetromino* TetrominoManager::CreateRandomTetromino() {
	int iType = rand() % TT_END;

	return CreateTetromino((TETROMINO_TYPE)iType);
}

Tetromino* TetrominoManager::CreateTetromino(TETROMINO_TYPE eType) {
	Tetromino* pTetromino = NULL;

	switch (eType) {
	case TT_I:
		pTetromino = new TetrominoI;
		break;
	case TT_J:
		pTetromino = new TetrominoJ;
		break;
	case TT_L:
		pTetromino = new TetrominoL;
		break;
	case TT_O:
		pTetromino = new TetrominoO;
		break;
	case TT_S:
		pTetromino = new TetrominoS;
		break;
	case TT_T:
		pTetromino = new TetrominoT;
		break;
	case TT_Z:
		pTetromino = new TetrominoZ;
		break;
	}


	if (!pTetromino->Init()) {
		SAFE_DELETE(pTetromino);
		return NULL;
	}

	return pTetromino;
}
