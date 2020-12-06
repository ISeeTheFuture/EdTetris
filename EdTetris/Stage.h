#pragma once

#include "value.h"

class CStage {

private:
	CStage();
	~CStage();

private:
	friend class CStageManager;

private:
	char m_Stage[STAGE_HEIGHT][STAGE_WIDTH];
	int m_iSpeed;

public:
	int GetSpeed() const {
		return m_iSpeed;
	}
	void SetSpeed(int iSpeed) {
		m_iSpeed = iSpeed;
	}

public:
	void AddBlock(class Tetromino* pShape, const POSITION& tPos);
	bool CheckBlock(int x, int y); // block ¶Ç´Â ¹Ù´Ú : true, ¾Æ´Ò°æ¿ì : false

public:
	bool Init();
	void Render();
};

