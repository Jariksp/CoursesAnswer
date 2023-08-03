#include "TBoxRun3DEscapeGame.h"




TBoxRun3DEscapeGame::TBoxRun3DEscapeGame() {
	
	Rectangle = new T3DRectangleObject();

}

std::vector<TMapPoint> TBoxRun3DEscapeGame::CreateGame(std::vector<TMapPoint> cells,TMapPoint BasePosition, int MoveCount) {

	MoveAction = MoveCount;
	Rectangle->Map = cells;  
	GameScore = MoveCount * 5; 
	Rectangle->BaseCellRectangle = BasePosition;
	Cells = cells;

	return std::vector<TMapPoint>();
}

bool operator== (const TMapPoint& c1,const TMapPoint& c2) {
	return c1.x==c2.x && c1.y==c2.y;
}

bool TBoxRun3DEscapeGame::IsOutside() {

	if(Rectangle->ActiveRectangleSide == NActiveSide::SmallSide) {
		
		std::vector<TMapPoint> Cache = Map(); 
		auto RectanglePoint = Rectangle->BaseCellRectangle;
		if(!(std::find(Cache.begin(),Cache.end(),RectanglePoint) != Cache.end())) return true;
	}else if(Rectangle->ActiveRectangleSide == NActiveSide::BigSide) {

		std::vector<TMapPoint> Cache = Map(); 
		auto RectanglePoint1 = Rectangle->BaseCellRectangle; 
		auto RectanglePoint2 = Rectangle->SecondCellRectangle;

		if(!(std::find(Cache.begin(),Cache.end(),RectanglePoint1) != Cache.end() || std::find(Cache.begin(),Cache.end(),RectanglePoint2) != Cache.end())) return true;
	}


	return false;
}



bool TBoxRun3DEscapeGame::IsDone() {

	
	if(MoveAction == 0 || IsOutside()) {
		std::cout << "Game end\n";
		return true;
	}

	return false;

}



void TBoxRun3DEscapeGame::Step(NMoveAction move) {

	if(Rectangle->ActiveRectangleSide==NActiveSide::BigSide)					 
	{																			 
		switch(move)															 
		{																		 
		case NMoveAction::Right:												 
			Rectangle->BaseCellRectangle.x += 1;	
			Rectangle->SecondCellRectangle.x = Rectangle->BaseCellRectangle.x;


			break;																 
		case NMoveAction::Forward:												 
			Rectangle->BaseCellRectangle.y += 2;
			Rectangle->SecondCellRectangle.y = Rectangle->BaseCellRectangle.y;
			Rectangle->ActiveRectangleSide = NActiveSide::SmallSide;			 
			break;																 
		case NMoveAction::Left:													 
			Rectangle->BaseCellRectangle.x -= 1;
			Rectangle->SecondCellRectangle.x = Rectangle->BaseCellRectangle.x;
			break;																 
		case NMoveAction::Back:													 
			Rectangle->BaseCellRectangle.y -= 1;	
			Rectangle->SecondCellRectangle.y = Rectangle->BaseCellRectangle.y;
			Rectangle->ActiveRectangleSide = NActiveSide::SmallSide; 
		default:												 				 
			break;
		} 
		--MoveAction;
		GameScore -= 5;
	}
	else if(Rectangle->ActiveRectangleSide==NActiveSide::SmallSide) 
	{
		switch(move) 
		{																		 
		case NMoveAction::Right:												    
			Rectangle->BaseCellRectangle.x += 1;								    
			Rectangle->SecondCellRectangle.x += 2;								    
			Rectangle->ActiveRectangleSide = NActiveSide::BigSide;			        
			break;																    
		case NMoveAction::Forward:												    
			Rectangle->BaseCellRectangle.y += 1;								    
			Rectangle->SecondCellRectangle.y += 2;								    
			Rectangle->ActiveRectangleSide = NActiveSide::BigSide;				    
			break;																    
		case NMoveAction::Left:													    
			Rectangle->BaseCellRectangle.x -= 1;								    
			Rectangle->SecondCellRectangle.x -= 2;								    
			Rectangle->ActiveRectangleSide = NActiveSide::BigSide; 				    
			break;																    
		case NMoveAction::Back:													    
			Rectangle->BaseCellRectangle.y -= 2;								    
			Rectangle->SecondCellRectangle.y -= 1;								    
			Rectangle->ActiveRectangleSide = NActiveSide::BigSide; 				    
		default:																    
			break;																    
		}		
		--MoveAction;
		GameScore -= 5;	
	}
	

}



std::vector<TMapPoint> TBoxRun3DEscapeGame::Map() {


	return Cells;
}

void TBoxRun3DEscapeGame::Reset() {

	GameScore = 0;
	MoveAction = 0;
	Done = true;
}

int TBoxRun3DEscapeGame::Turns() {
	 
	return MoveAction; 
}



int TBoxRun3DEscapeGame::Score() {

	return GameScore;
}
