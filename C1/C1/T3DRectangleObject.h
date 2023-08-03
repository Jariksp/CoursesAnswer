#ifndef T3DRECTANGLEOBJECT_H 
#define T3DRECTANGLEOBJECT_H

#include <vector>
#include <iostream>
#include "NNActiveSide.h"
#include "TMapPoint.h"
#include "TSize.h"



static const int X = 1;
static const int Y = 1;
static const int Z = 2;

class T3DRectangleObject {
	public: 
	NActiveSide ActiveSide(); 
	TMapPoint BaseCell();

	public:
	TSize Size();

	public:
	std::vector<TMapPoint> OffsetsByActiveSide();
	std::vector<TMapPoint> OccupiedArea(); 

	public:
	TSize RectangleSize{X,Y,Z}; 
	std::vector<TMapPoint> SizeToOffsets();

	public:
	NActiveSide ActiveRectangleSide = NActiveSide::SmallSide; 
	TMapPoint BaseCellRectangle = {0,0};  
	TMapPoint SecondCellRectangle = BaseCellRectangle;

	public:
	std::vector<TMapPoint> Map; 

};


#endif //  T3DRECTANGLEOBJECT


