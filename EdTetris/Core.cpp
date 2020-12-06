#include "Core.h"
#include "StageManager.h"
#include "TetrominoManager.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore() : m_bLoop(true) {
	srand((unsigned int)time(0));
}

CCore::~CCore() {
	TetrominoManager::DestroyInst();
	CStageManager::DestroyInst();
}

bool CCore::Init() {
	// �ܼ� �ڵ� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE) {
		return false;
	}

	//�������� ������ �ʱ�ȭ
	if(!CStageManager::GetInst()->Init()) {
		return false;
	}
	
	return true;
}

void CCore::Run() {
	while (m_bLoop) {
		system("cls");
		TetrominoManager::GetInst()->UpdatePos();

		CStageManager::GetInst()->Run();
		TetrominoManager::GetInst()->Render();

		Sleep(10);// ȭ�鿡 �Ѹ��� �ӵ�...������ �ٸ� ������ ��ü �ʿ�
	}
}

void CCore::SetConsolePos(int x, int y) {
	COORD pos = {(x + 1) * 2, y}; // ���� ������ ���� �� ĭ �����ϹǷ� x + 1
	SetConsoleCursorPosition(m_hConsole, pos);
}
