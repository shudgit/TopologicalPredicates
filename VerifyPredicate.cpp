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

    //Line || Line
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

        std::vector<bool> featureVector;
        featureVector.resize(9, false);

        SimplePoint2D lastDpF;
        SimplePoint2D lastDpG;
        SimplePoint2D lastBoundPointF;
        SimplePoint2D lastBoundPointG;

        
        SimplePoint2D eventPoint = objT.SelectNext();
        while(objT.status != 3 && (featureVector[0] == false || featureVector[1] == false || featureVector[2] == false || featureVector[3] == false || featureVector[4] == false || featureVector[5] == false || featureVector[6] == false || featureVector[7] == false || featureVector[8] == false))
        {
            if(objT.object == 1)
            {
                HalfSegment2D halfSeg = GetHalfSeg(line1Vector, eventPoint);
                if(halfSeg.isDominatingPointLeft)
                {
                    newSweep.add_left(halfSeg.s);
                }
                else
                {
                    newSweep.del_right(halfSeg.s);
                    featureVector[2] = true; //seg unshared
                }

                if(halfSeg.getDP() != lastDpF)
                {
                    lastDpF = halfSeg.getDP();
                }
                if(!newSweep.look_ahead(halfSeg, line1Vector))
                {
                    lastBoundPointF = halfSeg.getDP();
                    if(lastBoundPointF == lastBoundPointG)
                    {
                        featureVector[4] = true; //bound point shared
                    }
                    else if(lastBoundPointF == lastDpG)
                    {
                        featureVector[3] = true; //bound point on interior
                    }
                    else if(!newSweep.look_ahead(halfSeg, line2Vector))
                    {
                        featureVector[5] = true; //obj1 boundary disjoint
                    }
                }

                if(halfSeg.getDP() != lastBoundPointF)
                {
                    if(halfSeg.getDP() == lastBoundPointG)
                    {
                        featureVector[7] = true; //obj2 bound on interior
                    }
                    else if(halfSeg.getDP() == lastDpG)
                    {
                        featureVector[1] = true; //interior point shared
                    }
                }
            }
            else if(objT.object == 2)
            {
                HalfSegment2D halfSeg = GetHalfSeg(line1Vector, eventPoint);
                if(halfSeg.isDominatingPointLeft)
                {
                    newSweep.add_left(halfSeg.s);
                }
                else
                {
                    newSweep.del_right(halfSeg.s);
                    featureVector[6] = true; //seg unshared
                }

                if(halfSeg.getDP() != lastDpG)
                {
                    lastDpG = halfSeg.getDP();
                }
                if(!newSweep.look_ahead(halfSeg, line2Vector))
                {
                    lastBoundPointG = halfSeg.getDP();
                    if(lastBoundPointG == lastBoundPointF)
                    {
                        featureVector[4] = true; //bound point shared
                    }
                    else if(lastBoundPointG == lastDpF)
                    {
                        featureVector[7] = true; //bound point on interior
                    }
                    else if(!newSweep.look_ahead(halfSeg, line1Vector))
                    {
                        featureVector[8] = true; //obj2 boundary disjoint
                    }
                }

                if(halfSeg.getDP() != lastBoundPointG)
                {
                    if(halfSeg.getDP() == lastBoundPointF)
                    {
                        featureVector[3] = true; //obj1 bound on interior
                    }
                    else if(halfSeg.getDP() == lastDpF)
                    {
                        featureVector[1] = true; //interior point shared
                    }
                }
            }
            else
            {
                HalfSegment2D halfSegF = GetHalfSeg(line1Vector, eventPoint);
                HalfSegment2D halfSegG = GetHalfSeg(line2Vector, eventPoint);
                if(halfSegF == halfSegG)
                {
                    featureVector[0] = true;
                    
                }
            }
        }
    }

    //Point || Region
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
                else if(newSweep.pred_of_p_exists(eventPoint))
                {
                    Segment2D newBound = newSweep.pred_of_p(eventPoint);
                    bool isAbove = newSweep.get_attr(newBound);
                    if(isAbove) //attribute = above 
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
                AttributedHalfSegment2D attrHalfSeg = GetAttrHalfSeg(regionVector, eventPoint);
                if(attrHalfSeg.hs.isDominatingPointLeft) 
                {
                    newSweep.add_left(attrHalfSeg.hs.s);
                    newSweep.set_attr(attrHalfSeg.hs.s, attrHalfSeg.above);
                }
                else
                {
                    newSweep.del_right(attrHalfSeg.hs.s);
                }
                
                if(objT.object == 3)
                {
                    featureVector[1] = true; //point on boundary
                }
            }

            eventPoint = objT.SelectNext(); //call select next
        }

        if(objT.status == 2) //status = end of second
        {
            featureVector[2] = true; //point on outside
        }

        return featureVector;
    }

    AttributedHalfSegment2D GetAttrHalfSeg(std::vector<AttributedHalfSegment2D> halfSegVec, SimplePoint2D point)
    {
        for(int i = 0; i < halfSegVec.size(); i++)
        {
            if(halfSegVec[i].hs.isDominatingPointLeft)
            {
                if(halfSegVec[i].hs.s.leftEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
            else
            {
                if(halfSegVec[i].hs.s.rightEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
        }
    }

    HalfSegment2D GetHalfSeg(std::vector<HalfSegment2D> halfSegVec, SimplePoint2D point)
    {
        for(int i = 0; i < halfSegVec.size(); i++)
        {
            if(halfSegVec[i].isDominatingPointLeft)
            {
                if(halfSegVec[i].s.leftEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
            else
            {
                if(halfSegVec[i].s.rightEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
        }
    }

