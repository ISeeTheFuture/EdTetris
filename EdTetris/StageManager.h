#pragma once

#include "value.h"

class CStageManager {

public:
	CStageManager();
	~CStageManager();

private:
	static CStageManager* m_pInst;

public:
	static CStageManager* GetInst() {
		if (!m_pInst) {
			m_pInst = new CStageManager;
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
	class CStage* m_pCurStage; // include 안했으므로 clss 전방 선언

public:
	class CStage* GetCurrentStage() const {
		return  m_pCurStage;
	}

public:
	bool Init();
	void Run();
};

