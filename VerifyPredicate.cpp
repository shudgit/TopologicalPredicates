#include "VerifyPredicate.h"
#include "ParallelObjTraversal.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "SimplePoint2D.h"
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

    std::vector<bool> PointPointAlgorithm(Point2D p1, Point2D p2)
    {
        vector<bool> flags; // poi_shared, poi_disjoint p1, poi_disjoint p2
        vector<SimplePoint2D> p1Points;
        vector<SimplePoint2D> p2Points;
        for(Point2D::Iterator iter = p1.begin(); iter != p1.end(); iter++) 
            p1Points.push_back(*iter);
        for(Point2D::Iterator iter = p2.begin(); iter != p2.end(); iter++) 
            p2Points.push_back(*iter);
        
        ParallelObjT pot(p1Points, p2Points);   // start of parallel object traversal
        SimplePoint2D next = pot.SelectNext();
        while(pot.status == 0 && !(flags[0] && flags[1] && flags[2]))       // while not end of either and not all flags have been set
        {
            if(pot.object == 1)         // if p1, then p1 has a disjoint point
                flags[1] = true;
            else if(pot.object == 2)    // if p2, then p2 has a disjoint point
                flags[2] = true;
            else                        // if both, they have a shared point
                flags[0] = true;
            next = pot.SelectNext();
        }
        
        if(pot.status == 1)             // ended early on p1 means p2 still has points which are disjoint
            flags[2] = true;
        else if(pot.status == 2)        // ended early on p2 means p1 still has points which are disjoint
            flags[1] = true;

        return flags;
    }
    
    std::vector<bool> LineLineAlgorithm(Line2D line1, Line2D line2)
    {
        std::vector<HalfSegment2D> line1Vector;
        std::vector<HalfSegment2D> line2Vector;
        std::vector<SimplePoint2D> line1Points;
        std::vector<SimplePoint2D> line2Points;
        std::vector<bool> featureVector;
        featureVector.resize(9, false);

        for(Line2D::Iterator ptr = line1.begin(); ptr != line1.end(); ptr++)
         {
            line1Vector.push_back(*ptr);
            if(line1Vector.back().isDominatingPointLeft) 
            {
                line1Points.push_back(line1Vector.back().s.leftEndPoint);
            }
            else
            {
                line1Points.push_back(line1Vector.back().s.rightEndPoint);
            }
        }
        for(Line2D::Iterator ptr = line2.begin(); ptr != line2.end(); ptr++) 
        {
            line2Vector.push_back(*ptr);
            if(line2Vector.back().isDominatingPointLeft) 
            {
                line2Points.push_back(line2Vector.back().s.leftEndPoint);
            }
            else
            {
                line2Points.push_back(line2Vector.back().s.rightEndPoint);
            }
        }
        
        PlaneSweep newSweep;
        ParallelObjT objT(line1Points, line2Points);
        SimplePoint2D eventPoint = objT.SelectNext();
    }

    std::vector<bool> PointRegionAlgorithm(Point2D points, Region2D region)
    {
        std::vector<SimplePoint2D> pointVector;
        std::vector<AttributedHalfSegment2D> regionVector;
        std::vector<SimplePoint2D> regionPoints;

        std::vector<bool> featureVector;
        featureVector.resize(3, false);

        for(Point2D::Iterator ptr = points.begin(); ptr != points.end(); ptr++) 
        {
            pointVector.push_back(*ptr);
        }
        for(Region2D::Iterator ptr = region.begin(); ptr != region.end(); ptr++) 
        {
            regionVector.push_back(*ptr);
            if(regionVector.back().hs.isDominatingPointLeft) 
            {
                regionPoints.push_back(regionVector.back().hs.s.leftEndPoint);
            }
            else
            {
                regionPoints.push_back(regionVector.back().hs.s.rightEndPoint);
            }
        }

        PlaneSweep newSweep;
        ParallelObjT objT(pointVector, regionPoints);
        SimplePoint2D eventPoint = objT.SelectNext();

        while(objT.status == 0 && (featureVector[0] == false || featureVector[1] == false || featureVector[2] == false)) 
        {
            if(objT.object == 1) //object is a point
            {
                if(newSweep.poi_on_seg(eventPoint))
                {
                    //Point on bound = true
                    featureVector[1] = true;
                }
                else if(newSweep.pred_exists(eventPoint))
                {
                    Segment2D newBound = newSweep.pred_of_p(eventPoint);
                    //get attribute of segment

                    if() //attribute = above 
                    {
                        featureVector[0] = true; //point on inside
                    }
                    else //attribute below
                    {
                        featureVector[2] = true; //point on outside
                    }
                }
                else //point below region
                {
                    featureVector[2] = true;
                }
            }
            else //object is the region or object is both
            {
                //get half segment from event point
                
                if(objT.object == 3)
                {
                    featureVector[1] = true; //point on boundary
                }
            }

            eventPoint = objT.SelectNext(); //call select next
        }

        if(objT.status == 2) //status = end of second
        {
            featureVector[2] = true;
        }

        return featureVector;
    }

