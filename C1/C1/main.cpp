#include <iostream>
#include <memory>
#include "TBoxRun3DEscapeGame.h"


std::ostream& operator<< (std::ostream& out,const TMapPoint& point) {
	
	out << "Point(" << point.x << ", " << point.y << ")\n";

	return out;
}


std::vector<TMapPoint> GameVec{ {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},\
								{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},\
								{1,1},{2,1},{3,1},{4,1},{5,1},\
								{1,2},{2,2},{3,2},{4,2},{5,2},};


std::vector<TMapPoint> GameVec2{ {0,0},{1,0},{2,0},{3,0},{4,0}};

void play() {

	{
		TBoxRun3DEscapeGame Game{};
		Game.CreateGame(GameVec,{0,0},4);
		auto move = NMoveAction::Forward;

		while(!Game.IsDone()) {

			Game.Step(move);

			for(int i = 0; i < Game.Rectangle->OccupiedArea().size(); ++i)
				std::cout << Game.Rectangle->OccupiedArea()[i];
			std::cout << "\n";
			//std::cout << Game.Rectangle->BaseCellRectangle;

		}

	}


	



}



int main() {

	play();
	

	return 0;
}
