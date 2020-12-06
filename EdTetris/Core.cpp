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
	// 콘솔 핸들 생성
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE) {
		return false;
	}

	//스테이지 관리자 초기화
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

		Sleep(10);// 화면에 뿌리는 속도...앞으로 다른 것으로 대체 필요
	}
}

void CCore::SetConsolePos(int x, int y) {
	COORD pos = {(x + 1) * 2, y}; // 가장 왼쪽은 벽이 한 칸 차지하므로 x + 1
	SetConsoleCursorPosition(m_hConsole, pos);
}
