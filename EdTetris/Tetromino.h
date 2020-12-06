#pragma once

#include "value.h"

class Tetromino {
public:
	Tetromino();
	virtual ~Tetromino();

protected:
	// 기본 도형 모양 정의
	char m_tetromino[4][4];
	POSITION m_tPos;
	POSITION m_tPivot; // 도형 내에서의 기준점
	int m_iWidthCount;
	int m_iDir;

public:
	char GetBlock(int x, int y) const {
		return m_tetromino[y][x];
	}

	void SetPosition(int x, int y) {
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& tPos) {
		m_tPos = tPos;
	}

	POSITION GetPosition() const {
		return m_tPos;
	}

	POSITION GetPivot() const {
		return m_tPivot;
	}

public: // O 제외 각 테트로미노 별로 따로 만들어야 하므로 virtual
	virtual bool Init();
	virtual void Rotation();

public:
	void Render();
	void RenderNext(); // Render() 하나로 모든 도형을 그리려고 했지만, 예외처리가 빡세서 그냥 다음 도형은 따로 만듦.
	bool MoveDown();
	void MoveLeft();
	void MoveRight();
};
