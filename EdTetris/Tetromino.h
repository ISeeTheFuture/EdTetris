#pragma once

#include "value.h"

class Tetromino {
public:
	Tetromino();
	virtual ~Tetromino();

protected:
	// �⺻ ���� ��� ����
	char m_tetromino[4][4];
	POSITION m_tPos;
	POSITION m_tPivot; // ���� �������� ������
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

public: // O ���� �� ��Ʈ�ι̳� ���� ���� ������ �ϹǷ� virtual
	virtual bool Init();
	virtual void Rotation();

public:
	void Render();
	void RenderNext(); // Render() �ϳ��� ��� ������ �׸����� ������, ����ó���� ������ �׳� ���� ������ ���� ����.
	bool MoveDown();
	void MoveLeft();
	void MoveRight();
};
