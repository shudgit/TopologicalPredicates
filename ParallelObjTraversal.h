#include "SimplePoint2D.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "EventPoint.h"
#include <vector>
#include <queue>

class ParallelObjT 
{
    std::queue<SimplePoint2D> point1Queue;
    std::queue<SimplePoint2D> point2Queue;
    std::queue<SimplePoint2D> point1Dynamic;
    std::queue<SimplePoint2D> point2Dynamic;

    std::queue<HalfSegment2D> line1Queue;
    std::queue<HalfSegment2D> line2Queue;
    std::queue<HalfSegment2D> line1Dynamic;
    std::queue<HalfSegment2D> line2Dynamic;

    std::queue<AttributedHalfSegment2D> region1Queue;
    std::queue<AttributedHalfSegment2D> region2Queue;

    int object1Type; //0 = point, 1 = line, 2 = region
    int object2Type; //0 = point, 1 = line, 2 = region

    EventPoint PointPointNext();
    EventPoint PointLineNext();
    EventPoint PointRegionNext();
    EventPoint LineLineNext();
    EventPoint LineRegionNext();
    EventPoint RegionRegionNext();

    public:
    std::queue<AttributedHalfSegment2D> region1Dynamic;
    std::queue<AttributedHalfSegment2D> region2Dynamic;
    
    int object = 0; //1 = object 1, 2 = object 2, 3 = both objects
    int status = 0; // 0 = end of none, 1 = end of first, 2 = end of second, 3 = end of both
    ParallelObjT(std::vector<SimplePoint2D> obj1, std::vector<SimplePoint2D> obj2);
    //ParallelObjT(Point2D obj1, Point2D obj2);
    ParallelObjT(std::vector<AttributedHalfSegment2D> obj1, std::vector<AttributedHalfSegment2D> obj2);
    ParallelObjT(std::vector<SimplePoint2D> obj1, std::vector<HalfSegment2D> obj2);
    ParallelObjT(std::vector<HalfSegment2D> obj1, std::vector<AttributedHalfSegment2D> obj2);
    ParallelObjT(std::vector<SimplePoint2D> obj1, std::vector<AttributedHalfSegment2D> obj2);
    ParallelObjT(std::vector<HalfSegment2D> obj1, std::vector<HalfSegment2D> obj2);
    EventPoint SelectNext();
};