#include "T3DRectangleObject.h"

NActiveSide T3DRectangleObject::ActiveSide() {
    return ActiveRectangleSide;
}

TMapPoint T3DRectangleObject::BaseCell() {


    return BaseCellRectangle;
}

TSize T3DRectangleObject::Size() {

    return RectangleSize;
}



std::vector<TMapPoint> OffsetsCellBigSide = {{1,0},{0,1},{-1,0},{0,-1}};
std::vector<TMapPoint> OffsetsCellSmallSide = {{2,0},{0,2},{-2,0},{0,-2}};

std::vector<TMapPoint> T3DRectangleObject::OffsetsByActiveSide() {

    std::vector<TMapPoint> CellsWithOffsets;
    TMapPoint CellsWithOffset;
    
    if(ActiveRectangleSide == NActiveSide::SmallSide) {
        for(int i = 0;i < OffsetsCellSmallSide.size(); ++i) {
            CellsWithOffset.x = BaseCellRectangle.x + OffsetsCellSmallSide[i].x;
            CellsWithOffset.y = BaseCellRectangle.y + OffsetsCellSmallSide[i].y;
            CellsWithOffsets.push_back(CellsWithOffset);

        }
    } else if(ActiveRectangleSide == NActiveSide::BigSide) {                                 
        for(int i = 0;i < OffsetsCellBigSide.size(); ++i) {
            CellsWithOffset.x = BaseCellRectangle.x + OffsetsCellBigSide[i].x;
            CellsWithOffset.y = BaseCellRectangle.y + OffsetsCellBigSide[i].y;
            CellsWithOffsets.push_back(CellsWithOffset);                                     
                                                                                             
        }
    }

    return CellsWithOffsets;
}

std::vector<TMapPoint> T3DRectangleObject::OccupiedArea() {

    std::vector<TMapPoint> OccupiedRectangleArea;

    OccupiedRectangleArea.push_back(BaseCellRectangle);
    if(ActiveRectangleSide == NActiveSide::BigSide) OccupiedRectangleArea.push_back(SecondCellRectangle);

    return OccupiedRectangleArea;
}

std::vector<TMapPoint> T3DRectangleObject::SizeToOffsets() {


    return std::vector<TMapPoint>();
}

