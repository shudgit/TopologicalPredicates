#include "Number.h"
#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"
#include "PlaneSweep.h"
#include "ParallelObjTraversal.h"
#include <unordered_map>


class VerifyPredicate
{
private:

    HalfSegment2D findHS(vector<HalfSegment2D> HS, SimplePoint2D point);
    std::unordered_map<int, vector<bool>> predicates;
    std::vector<bool> PointPointAlgorithm(Point2D p1, Point2D p2);
    std::vector<bool> PointLineAlgorithm(Point2D obj1, Line2D obj2);
    std::vector<bool> PointRegionAlgorithm(Point2D obj1, Region2D obj2);
    std::vector<bool> LineLineAlgorithm(Line2D obj1, Line2D obj2);
    std::vector<bool> LineRegionAlgorithm(Line2D obj1, Region2D obj2);
    std::vector<bool> RegionRegionAlgorithm(Region2D f, Region2D g);

public:

    // This function creates a features vector, then manipulates it in parallel object traversal
    // It then evaluates that vector and returns true. 
    bool disjoint(Point2D obj1, Point2D obj2);
    bool disjoint(Point2D obj1, Line2D obj2);
    bool disjoint(Point2D obj1, Region2D obj2);
    bool disjoint(Line2D obj1, Line2D obj2);
    bool disjoint(Line2D obj1, Region2D obj2);
    bool disjoint(Region2D obj1, Region2D obj2);

    bool meet(Point2D obj1, Point2D obj2);
    bool meet(Point2D obj1, Line2D obj2);
    bool meet(Point2D obj1, Region2D obj2);
    bool meet(Line2D obj1, Line2D obj2);
    bool meet(Line2D obj1, Region2D obj2);
    bool meet(Region2D obj1, Region2D obj2);

    bool equal(Point2D obj1, Point2D obj2);
    bool equal(Point2D obj1, Line2D obj2);
    bool equal(Point2D obj1, Region2D obj2);
    bool equal(Line2D obj1, Line2D obj2);
    bool equal(Line2D obj1, Region2D obj2);
    bool equal(Region2D obj1, Region2D obj2);

    bool inside(Point2D obj1, Point2D obj2);
    bool inside(Point2D obj1, Line2D obj2);
    bool inside(Point2D obj1, Region2D obj2);
    bool inside(Line2D obj1, Line2D obj2);
    bool inside(Line2D obj1, Region2D obj2);
    bool inside(Region2D obj1, Region2D obj2);

    bool covered_by(Point2D obj1, Point2D obj2);
    bool covered_by(Point2D obj1, Line2D obj2);
    bool covered_by(Point2D obj1, Region2D obj2);
    bool covered_by(Line2D obj1, Line2D obj2);
    bool covered_by(Line2D obj1, Region2D obj2);
    bool covered_by(Region2D obj1, Region2D obj2);

    bool contains(Point2D obj1, Point2D obj2);
    bool contains(Point2D obj1, Line2D obj2);
    bool contains(Point2D obj1, Region2D obj2);
    bool contains(Line2D obj1, Line2D obj2);
    bool contains(Line2D obj1, Region2D obj2);
    bool contains(Region2D obj1, Region2D obj2);

    bool covers(Point2D obj1, Point2D obj2);
    bool covers(Point2D obj1, Line2D obj2);
    bool covers(Point2D obj1, Region2D obj2);
    bool covers(Line2D obj1, Line2D obj2);
    bool covers(Line2D obj1, Region2D obj2);
    bool covers(Region2D obj1, Region2D obj2);

    bool overlap(Point2D obj1, Point2D obj2);
    bool overlap(Point2D obj1, Line2D obj2);
    bool overlap(Point2D obj1, Region2D obj2);
    bool overlap(Line2D obj1, Line2D obj2);
    bool overlap(Line2D obj1, Region2D obj2);
    bool overlap(Region2D obj1, Region2D obj2);

    bool verify(Point2D obj1, Point2D obj2, int predicateNumber);  
    bool verify(Point2D obj1, Line2D obj2, int predicateNumber);
    bool verify(Point2D obj1, Region2D obj2, int predicateNumber);
    bool verify(Line2D obj1, Line2D obj2, int predicateNumber);
    bool verify(Line2D obj1, Region2D obj2, int predicateNumber);
    bool verify(Region2D obj1, Region2D obj2, int predicateNumber);
};
