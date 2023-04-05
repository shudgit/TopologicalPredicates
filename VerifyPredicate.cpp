#include "VerifyPredicate.h"
#include <vector>


    bool disjoint(Point2D obj1, Point2D obj2)
    {

    }
    bool disjoint(Point2D obj1, Line2D obj2)
    {

    }
    bool disjoint(Point2D obj1, Region2D obj2)
    {

    }
    bool disjoint(Line2D obj1, Line2D obj2)
    {

    }
    bool disjoint(Line2D obj1, Region2D obj2)
    {

    }
    bool disjoint(Region2D obj1, Region2D obj2)
    {

    }

    bool meet(Point2D obj1, Point2D obj2)
    {

    }
    bool meet(Point2D obj1, Line2D obj2)
    {

    }
    bool meet(Point2D obj1, Region2D obj2)
    {

    }
    bool meet(Line2D obj1, Line2D obj2)
    {

    }
    bool meet(Line2D obj1, Region2D obj2)
    {

    }
    bool meet(Region2D obj1, Region2D obj2)
    {
        
    }

    bool equal(Point2D obj1, Point2D obj2)
    {

    }
    bool equal(Point2D obj1, Line2D obj2)
    {

    }
    bool equal(Point2D obj1, Region2D obj2)
    {

    }
    bool equal(Line2D obj1, Line2D obj2)
    {

    }
    bool equal(Line2D obj1, Region2D obj2)
    {

    }
    bool equal(Region2D obj1, Region2D obj2)
    {
        
    }

    bool inside(Point2D obj1, Point2D obj2)
    {

    }
    bool inside(Point2D obj1, Line2D obj2)
    {

    }
    bool inside(Point2D obj1, Region2D obj2)
    {

    }
    bool inside(Line2D obj1, Line2D obj2)
    {

    }
    bool inside(Line2D obj1, Region2D obj2)
    {

    }
    bool inside(Region2D obj1, Region2D obj2)
    {
        
    }

    bool covered_by(Point2D obj1, Point2D obj2)
    {

    }
    bool covered_by(Point2D obj1, Line2D obj2)
    {

    }
    bool covered_by(Point2D obj1, Region2D obj2)
    {

    }
    bool covered_by(Line2D obj1, Line2D obj2)
    {

    }
    bool covered_by(Line2D obj1, Region2D obj2)
    {

    }
    bool covered_by(Region2D obj1, Region2D obj2)
    {
        
    }

    bool contains(Point2D obj1, Point2D obj2)
    {

    }
    bool contains(Point2D obj1, Line2D obj2)
    {

    }
    bool contains(Point2D obj1, Region2D obj2)
    {

    }
    bool contains(Line2D obj1, Line2D obj2)
    {

    }
    bool contains(Line2D obj1, Region2D obj2)
    {

    }
    bool contains(Region2D obj1, Region2D obj2)
    {
        
    }

    bool covers(Point2D obj1, Point2D obj2)
    {

    }
    bool covers(Point2D obj1, Line2D obj2)
    {

    }
    bool covers(Point2D obj1, Region2D obj2)
    {

    }
    bool covers(Line2D obj1, Line2D obj2)
    {

    }
    bool covers(Line2D obj1, Region2D obj2)
    {

    }
    bool covers(Region2D obj1, Region2D obj2)
    {
        
    }

    bool overlap(Point2D obj1, Point2D obj2)
    {

    }
    bool overlap(Point2D obj1, Line2D obj2)
    {

    }
    bool overlap(Point2D obj1, Region2D obj2)
    {

    }
    bool overlap(Line2D obj1, Line2D obj2)
    {

    }
    bool overlap(Line2D obj1, Region2D obj2)
    {

    }
    bool overlap(Region2D obj1, Region2D obj2)
    {
        
    }


    bool verify(Point2D obj1, Point2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false};
    } 
    bool verify(Point2D obj1, Line2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false};
    }
    bool verify(Point2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false};
    }
    bool verify(Line2D obj1, Line2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false, false, false, false, false, false};
    }
    bool verify(Line2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false, false, false, false, false};
    }
    bool verify(Region2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false, false, false, false, false};
    }