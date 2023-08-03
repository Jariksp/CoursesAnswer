#ifndef TBOXRUN3DESCAPEGAME_H
#define TBOXRUN3DESCAPEGAME_H

#include <vector>
#include <memory>
#include <algorithm>
#include "TMapPoint.h"
#include "NNMoveAction.h"
#include "T3DRectangleObject.h"



class TBoxRun3DEscapeGame {
	public:
	TBoxRun3DEscapeGame();
	std::vector<TMapPoint> CreateGame(std::vector<TMapPoint> cells, TMapPoint BasePosition, int CountMove);
	bool IsDone();

	public:
	void Step(NMoveAction move);
	bool IsOutside();

	public:
	int Score();
	int Turns();

	public:
	std::vector<TMapPoint> Map();
	void Reset();

	public:
	std::vector<TMapPoint> Cells;
	T3DRectangleObject* Rectangle;

	public:
	int MoveAction;
	bool Done = false;
	int GameScore;


};


#endif // !TBOXRUN3DESCAPEGAME_H



