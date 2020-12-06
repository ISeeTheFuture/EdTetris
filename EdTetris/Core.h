#pragma once

#include "value.h"

class CCore {

private:
	CCore();
	~CCore();

private:
	static CCore* m_pInst;

public:
	static CCore* GetInst() { // 싱글톤 객체 생성
		if (!m_pInst) {
			m_pInst = new CCore;
		}
		return m_pInst;
	}

	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}

private:
	HANDLE m_hConsole;
	bool m_bLoop;

public:
	bool Init(); // 초기화
	void Run(); // 전체 게임 동작
	void SetConsolePos(int x, int y);
	void End() {
		m_bLoop = false;
	}
};