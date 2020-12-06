#pragma once
#include "Tetromino.h"
class TetrominoS : public Tetromino {

public:
	TetrominoS();
	~TetrominoS();

public:
	virtual bool Init();
	virtual void Rotation();
};