#pragma once
#include "Tetromino.h"
class TetrominoI : public Tetromino {

public:
	TetrominoI();
	~TetrominoI();

public:
	virtual bool Init();
	virtual void Rotation();
};