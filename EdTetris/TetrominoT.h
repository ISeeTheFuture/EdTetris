#pragma once
#include "Tetromino.h"
class TetrominoT : public Tetromino{

public:
	TetrominoT();
	~TetrominoT();

public:
	virtual bool Init();
	virtual void Rotation();
};