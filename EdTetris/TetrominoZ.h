#pragma once
#include "Tetromino.h"
class TetrominoZ : public Tetromino {

public:
	TetrominoZ();
	~TetrominoZ();

public:
	virtual bool Init();
	virtual void Rotation();
};