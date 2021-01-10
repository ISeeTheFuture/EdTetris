#pragma once

#include "value.h"

class CCore {

private:
	CCore();
	~CCore();

private:
	static CCore* m_pInst;

public:
	static CCore* GetInst() { // �̱��� ��ü ����
		if (!m_pInst) {
			m_pInst = new CCore;
		}
		return m_pInst;
	}

	static void DestroyInst() {
		if (m_pInst) {
			delete m_pInst;
			m_pInst = NULL;
		}
	}

private:
	HANDLE m_hConsole;
	bool m_bLoop;

public:
	bool Init(); // �ʱ�ȭ
	void Run(); // ��ü ���� ����
	void SetConsolePos(int x, int y);
	void End() {
		m_bLoop = false;
	}
};