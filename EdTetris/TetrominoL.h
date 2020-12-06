#pragma once
#include "Tetromino.h"

class TetrominoL : public Tetromino {

public:
	TetrominoL();
	~TetrominoL();

public:
	virtual bool Init();
	virtual void Rotation();
};