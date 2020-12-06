#pragma once
#include "Tetromino.h"
class TetrominoJ : public Tetromino {

public:
	TetrominoJ();
	~TetrominoJ();

public:
	virtual bool Init();
	virtual void Rotation();
};