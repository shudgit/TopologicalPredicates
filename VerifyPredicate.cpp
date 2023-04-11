#include "VerifyPredicate.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "SimplePoint2D.h"
#include "EventPoint.h"
#include <vector>
#include <unordered_map>


    bool VerifyPredicate::disjoint(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[0])
            return false;
        return true;
    }
    bool VerifyPredicate::disjoint(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (!(flags[1] && flags[2]))
            return true;
        return false;
    }
    bool VerifyPredicate::disjoint(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::disjoint(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::disjoint(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if (!(flags[0] && (flags[1] || flags[3]) && flags[4] && flags[5]))
            return true;
        return false;
    }
    bool VerifyPredicate::disjoint(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        if(flags[2] || flags[3] || flags[4] || flags[5] || flags[6] || flags[7] || flags[10] || flags[11])
            return false;
        return true;
    }

    bool VerifyPredicate::meet(Point2D obj1, Point2D obj2)
    {
        return false;
    }
    bool VerifyPredicate::meet(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (!flags[1] && flags[2])
            return true;
        return false;
    }
    bool VerifyPredicate::meet(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::meet(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::meet(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if ((!flags[0] && (flags[1] || flags[3])) || (!flags[0] && flags[4]) || (!flags[0] && flags[5]))
            return true;
        return false;
    }
    bool VerifyPredicate::meet(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        if(!(flags[2] || flags[3] || flags[4] || flags[5] || flags[10] || flags[11]) && (flags[6] || flags[7]))
            return true;
        return false;
    }

    bool VerifyPredicate::equal(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[1] && flags[2])
            return false;
        return true;
    }

    // Point object and Line cannot be equal
    bool VerifyPredicate::equal(Point2D obj1, Line2D obj2)
    {
       return false;
    }
    bool VerifyPredicate::equal(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::equal(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::equal(Line2D obj1, Region2D obj2)
    {
        return false;
    }
    bool VerifyPredicate::equal(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        if(flags[2] || flags[3] || flags[4] || flags[5] || flags[6] || flags[7] || flags[10] || flags[11])
            return false;
        return true;
    }

    bool VerifyPredicate::inside(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[1])
            return false;
        return true;
    }
    bool VerifyPredicate::inside(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (flags[1] && !flags[0])
            return true;
        return false;
    }
    bool VerifyPredicate::inside(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::inside(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::inside(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if (flags[0] && !flags[2] && !flags[6])
            return true;
        return false;
    }
    bool VerifyPredicate::inside(Region2D obj1, Region2D obj2)
    {
        
    }

    bool VerifyPredicate::covered_by(Point2D obj1, Point2D obj2)
    {
        return false;
    }
    bool VerifyPredicate::covered_by(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if ((flags[1] && !flags[0]) || (flags[2] && !flags[0]))
            return true;
        return false;
    }
    bool VerifyPredicate::covered_by(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::covered_by(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::covered_by(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if ((flags[0] && !flags[2] && !flags[6])||((flags[1] || flags[3]) && !flags[2] && !flags[6])||(flags[4] && !flags[2] && !flags[6])||(flags[5] && !flags[2] && !flags[6]))
            return true;
        return false;
    }
    bool VerifyPredicate::covered_by(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        if(flags[2] || flags[3] || flags[4] || flags[5] || flags[6] || flags[7] || flags[10] || flags[11])  // not correct
            return false;
        return true;
    }

    bool VerifyPredicate::contains(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[2])
            return false;
        return true;
    }

    // cannot happen because the exterior of a point always intersects the interior of a line
    bool VerifyPredicate::contains(Point2D obj1, Line2D obj2)
    {
        return false;
    }
    bool VerifyPredicate::contains(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::contains(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::contains(Line2D obj1, Region2D obj2)
    {
        return false;
    }
    bool VerifyPredicate::contains(Region2D obj1, Region2D obj2)
    {
        
    }

    bool VerifyPredicate::covers(Point2D obj1, Point2D obj2)
    {
        return false;
    }

    // cannot happen for same reasoning as contains
    bool VerifyPredicate::covers(Point2D obj1, Line2D obj2)
    {
        return false;
    }
    bool VerifyPredicate::covers(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::covers(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::covers(Line2D obj1, Region2D obj2)
    {
        return false;
    }
    bool VerifyPredicate::covers(Region2D obj1, Region2D obj2)
    {
        
    }

    bool VerifyPredicate::overlap(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[0] && flags[1] && flags[2])
            return true;
        return false;
    }
    bool VerifyPredicate::overlap(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (flags[1] && flags[0])
            return true;
        return false;
    }
    bool VerifyPredicate::overlap(Point2D obj1, Region2D obj2)
    {

    }
    bool VerifyPredicate::overlap(Line2D obj1, Line2D obj2)
    {

    }
    bool VerifyPredicate::overlap(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if (flags[0] && flags[2])
            return true;
        return false;
    }
    bool VerifyPredicate::overlap(Region2D obj1, Region2D obj2)
    {
        
    }


    bool VerifyPredicate::verify(Point2D obj1, Point2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false};
    } 
    bool VerifyPredicate::verify(Point2D obj1, Line2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false};
    }
    bool VerifyPredicate::verify(Point2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false};
    }
    bool VerifyPredicate::verify(Line2D obj1, Line2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false, false, false, false, false, false};
    }
    bool VerifyPredicate::verify(Line2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false, false, false, false, false};
    }
    bool VerifyPredicate::verify(Region2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> features {false, false, false, false, false, false, false, false};
    }

    std::vector<bool> VerifyPredicate::PointPointAlgorithm(Point2D p1, Point2D p2)
    {
        std::vector<bool> flags; // poi_shared, poi_disjoint p1, poi_disjoint p2
        flags.resize(3, false);
        std::vector<SimplePoint2D> p1Points;
        std::vector<SimplePoint2D> p2Points;
        for(Point2D::Iterator iter = p1.begin(); iter != p1.end(); iter++) 
            p1Points.push_back(*iter);
        for(Point2D::Iterator iter = p2.begin(); iter != p2.end(); iter++) 
            p2Points.push_back(*iter);
        
        ParallelObjT pot(p1Points, p2Points);   // start of parallel object traversal
        SimplePoint2D next = pot.SelectNext().point;
        while(pot.status == 0 && !(flags[0] && flags[1] && flags[2]))       // while not end of either and not all flags have been set
        {
            if(pot.object == 1)         // if p1, then p1 has a disjoint point
                flags[1] = true;
            else if(pot.object == 2)    // if p2, then p2 has a disjoint point
                flags[2] = true;
            else                        // if both, they have a shared point
                flags[0] = true;
            next = pot.SelectNext().point;
        }

        if(pot.status == 1)             // ended early on p1 means p2 still has points which are disjoint
            flags[2] = true;
        else if(pot.status == 2)        // ended early on p2 means p1 still has points which are disjoint
            flags[1] = true;

        return flags;
    }
    
    //Line || Line
    std::vector<bool> VerifyPredicate::LineLineAlgorithm(Line2D line1, Line2D line2)
    {
        std::vector<HalfSegment2D> line1Vector;
        std::vector<HalfSegment2D> line2Vector;
        std::vector<bool> featureVector;
        featureVector.resize(9, false);

        for(Line2D::iterator ptr = line1.begin(); ptr != line1.end(); ptr++)
         {
            line1Vector.push_back(*ptr);
        }
        for(Line2D::iterator ptr = line2.begin(); ptr != line2.end(); ptr++) 
        {
            line2Vector.push_back(*ptr);
        }
        
        PlaneSweep newSweep;
        ParallelObjT objT(line1Vector, line2Vector);

        std::vector<bool> featureVector;
        featureVector.resize(9, false);

        SimplePoint2D lastDpF;
        SimplePoint2D lastDpG;
        SimplePoint2D lastBoundPointF;
        SimplePoint2D lastBoundPointG;

        
        EventPoint eventPoint = objT.SelectNext();
        while(objT.status != 3 && (featureVector[0] == false || featureVector[1] == false || featureVector[2] == false || featureVector[3] == false || featureVector[4] == false || featureVector[5] == false || featureVector[6] == false || featureVector[7] == false || featureVector[8] == false))
        {
            if(objT.object == 1)
            {
                HalfSegment2D halfSeg = eventPoint.halfSeg;
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
                HalfSegment2D halfSeg = eventPoint.halfSeg;
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
                featureVector[0] = true;
                HalfSegment2D halfSeg = eventPoint.halfSeg;
                if(halfSeg.isDominatingPointLeft)
                {
                    newSweep.add_left(halfSeg.s);
                }
                else
                {
                    newSweep.del_right(halfSeg.s);
                }
                if(halfSeg.getDP() != lastDpF)
                {
                    lastDpF = halfSeg.getDP();

                    if(!newSweep.look_ahead(halfSeg, line2Vector))
                    {
                        lastBoundPointF = halfSeg.getDP();
                    }
                }
                if(halfSeg.getDP() != lastDpG)
                {
                    lastDpG = halfSeg.getDP();

                    if(!newSweep.look_ahead(halfSeg, line2Vector))
                    {
                        lastBoundPointG = halfSeg.getDP();
                    }
                }
                if(lastBoundPointF == lastBoundPointG)
                {
                    featureVector[4] = true;
                }
                else
                {
                    if(lastBoundPointF == lastDpG)
                    {
                        featureVector[3] = true;
                    }
                    if(lastBoundPointG == lastDpF)
                    {
                        featureVector[7] = true;
                    }
                }
            }
            if(objT.status == 1)
            {
                featureVector[6] = true;
            }
            else if(objT.status == 2)
            {
                featureVector[2] = true;
            }
            eventPoint = objT.SelectNext();
        }
    }

    //Point || Region
    std::vector<bool> VerifyPredicate::PointRegionAlgorithm(Point2D points, Region2D region)
    {
        std::vector<SimplePoint2D> pointVector;
        std::vector<AttributedHalfSegment2D> regionVector;

        std::vector<bool> featureVector;
        featureVector.resize(3, false);

        for(Point2D::Iterator ptr = points.begin(); ptr != points.end(); ptr++) 
        {
            pointVector.push_back(*ptr);
        }
        for(Region2D::iterator ptr = region.begin(); ptr != region.end(); ptr++) 
        {
            regionVector.push_back(*ptr);
        }

        PlaneSweep newSweep;
        ParallelObjT objT(pointVector, regionVector);
        EventPoint eventPoint = objT.SelectNext();

        while(objT.status == 0 && (featureVector[0] == false || featureVector[1] == false || featureVector[2] == false)) 
        {
            if(objT.object == 1) //object is a point
            {
                SimplePoint2D point = eventPoint.point;
                if(newSweep.poi_on_seg(point))
                {
                    //Point on bound = true
                    featureVector[1] = true;
                }
                else if(newSweep.pred_of_p_exists(point))
                {
                    Segment2D newBound = newSweep.pred_of_p(point);
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
                AttributedHalfSegment2D attrHalfSeg = eventPoint.attrHalfSeg;
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

    std::vector<bool> VerifyPredicate::RegionRegionAlgorithm(Region2D f, Region2D g)
    {
        std::vector<bool> flags; // 0/1, 1/0, 1/2, 2/1, 0/2, 2/0, 1/1, bound_poi_shared, 0/1g, 1/0g, 1/2g, 2/1g
        flags.resize(12, false);
        std::vector<AttributedHalfSegment2D> fSegments;
        std::vector<AttributedHalfSegment2D> gSegments;
        //std::vector<SimplePoint2D> fPoints;
        //std::vector<SimplePoint2D> gPoints;
        for(Region2D::iterator iter = f.begin(); iter != f.end(); iter++)
        {
            fSegments.push_back(*iter);
            /*if((*iter).hs.isDominatingPointLeft)
                fPoints.push_back((*iter).hs.s.leftEndPoint);
            else
                fPoints.push_back((*iter).hs.s.rightEndPoint);*/
        }
        for(Region2D::iterator iter = g.begin(); iter != g.end(); iter++)
        {
            gSegments.push_back(*iter);
            /*if((*iter).hs.isDominatingPointLeft)
                gPoints.push_back((*iter).hs.s.leftEndPoint);
            else
                gPoints.push_back((*iter).hs.s.rightEndPoint);*/
        }

        PlaneSweep sweep;
        ParallelObjT pot(fSegments, gSegments);   // start of parallel object traversal
        AttributedHalfSegment2D next = pot.SelectNext().attrHalfSeg;
        AttributedHalfSegment2D last_dp_in_f;
        AttributedHalfSegment2D last_dp_in_g;

        unordered_map<pair<int, int>, bool> vf;
        unordered_map<pair<int, int>, bool> vg;
        while(pot.status == 0 && !(flags[0] && flags[1] && flags[2] && flags[3] && flags[4] && flags[5] && flags[6] && flags[7] && flags[8] && flags[9] && flags[10] && flags[11]))
        {
            if(pot.object == 1)      // if f, set last_dp_in_f
            {
                last_dp_in_f = next;
            }
            else if(pot.object == 2) // if g, set last_dp_in_g
            {
                last_dp_in_g = next;
            }
            else                     // if both, set both
            {
                last_dp_in_f = next;
                last_dp_in_g = next;
            }
            if(last_dp_in_f == last_dp_in_g || last_dp_in_f == sweep.look_ahead_2(last_dp_in_g, gSegments) || last_dp_in_g == sweep.look_ahead_2(last_dp_in_f, fSegments))
                flags[7] = true; // bound_poi_shared
            if(!next.hs.isDominatingPointLeft)
            {
                pair<int, int> overlap_numbers = sweep.get_attr_2(next.hs.s);
                if(pot.object == 1)      // if f, add to vf
                    if(vf.find(overlap_numbers) == vf.end())
                        vf.insert(make_pair(overlap_numbers, true));
                else if(pot.object == 2) // if g, add to vg
                    if(vg.find(overlap_numbers) == vg.end())
                        vg.insert(make_pair(overlap_numbers, true));
                else                     // if both, set both
                {
                    if(vf.find(overlap_numbers) == vf.end())
                        vf.insert(make_pair(overlap_numbers, true));
                    if(vg.find(overlap_numbers) == vg.end())
                        vg.insert(make_pair(overlap_numbers, true));
                }
                sweep.del_right(next.hs.s);
            }
            else
            {
                pair<int, int> mn_pred;
                sweep.add_left(next.hs.s);
                if(sweep.coincident(next.hs.s))
                    pot.object = 3;
                if(!sweep.pred_exists(next.hs.s))
                    mn_pred = make_pair(3, 0);       // 3 = *
                else
                    mn_pred = sweep.get_pred_attr_2(next.hs.s);
                pair<int, int> mn = make_pair(mn_pred.second, mn_pred.second);
                if(pot.object == 1 || pot.object == 3)
                {
                    if(next.above)
                        mn.second += 1;
                    else
                        mn.second -= 1;
                }
                if(pot.object == 2 || pot.object == 3)
                {
                    if(next.above)
                        mn.second += 1;
                    else
                        mn.second -= 1;
                }
                sweep.set_attr_2(next.hs.s, mn);
            }
            next = pot.SelectNext().attrHalfSeg;
        }
        if(pot.status == 1)
        {
            if(vg.find(make_pair(0, 1)) == vg.end())
                vg.insert(make_pair(make_pair(0, 1), true));
            if(vg.find(make_pair(1, 0)) == vg.end())
                vg.insert(make_pair(make_pair(1, 0), true));
        }
        else if(pot.status == 2)
        {
            if(vf.find(make_pair(0, 1)) == vf.end())
                vf.insert(make_pair(make_pair(0, 1), true));
            if(vf.find(make_pair(1, 0)) == vf.end())
                vf.insert(make_pair(make_pair(1, 0), true));
        }

        // convert vf and vg to bool vector
        if(vf.find(make_pair(0, 1)) != vf.end())
            flags[0] = true;
        if(vf.find(make_pair(1, 0)) != vf.end())
            flags[1] = true;
        if(vf.find(make_pair(1, 2)) != vf.end())
            flags[2] = true;
        if(vf.find(make_pair(2, 1)) != vf.end())
            flags[3] = true;
        if(vf.find(make_pair(0, 2)) != vf.end())
            flags[4] = true;
        if(vf.find(make_pair(2, 0)) != vf.end())
            flags[5] = true;
        if(vf.find(make_pair(1, 1)) != vf.end())
            flags[6] = true;
        if(vg.find(make_pair(0, 1)) != vg.end())
            flags[8] = true;
        if(vg.find(make_pair(1, 0)) != vg.end())
            flags[9] = true;
        if(vg.find(make_pair(1, 2)) != vg.end())
            flags[10] = true;
        if(vg.find(make_pair(2, 1)) != vg.end())
            flags[11] = true;
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

    std::vector<bool> VerifyPredicate::PointLineAlgorithm(Point2D obj1, Line2D obj2)
    {
        vector<bool> features {false, false, false, false};
        PlaneSweep S = PlaneSweep();
        SimplePoint2D last_dp;
        Point2D::Iterator ptr;
        Line2D::iterator ptr2;
        vector<SimplePoint2D> obj1V; 
        vector<HalfSegment2D> obj2HV;

        // Pushing event points into the vectors.
        for (ptr = obj1.begin(); ptr < obj1.end(); ptr++)
        {
            obj1V.push_back(*ptr);
        }

        for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
        {
            obj2HV.push_back(*ptr2);
        }

        // Creating parallel object traverssal object
        ParallelObjT pt(obj1V, obj2HV);
        EventPoint eventPoint = pt.SelectNext();

        do
        {

            // If the current event point we are considering is from the Point2D
            if (pt.object == 1)
            {
                // We check that this point is contained in the Line2D object
                if (S.poi_on_seg(eventPoint.point))
                {
                    // If it is, then the poi_on_interior flag is flipped
                    features[1] = true;
                }
                else
                {
                    // If it is not, then the poi_disjoint flag is flipped
                    features[0] = true;
                }
            }
            
            // If the current event point we are considering is from the Line2D
            else if (pt.object = 2)
            {
                // if this halfsegment is a left dominant halfsegment
                if (eventPoint.halfSeg.isDominatingPointLeft)
                {
                    // add it to the planesweep
                    S.add_left(eventPoint.halfSeg.s);
                }
                else
                {
                    // delete it from the planesweep
                    S.del_right(eventPoint.halfSeg.s);
                }

                // if the current halfsegment's dominating point is not equal to the last dominating point. 
                if (eventPoint.halfSeg.getDP() != last_dp)
                {
                    // change that
                    last_dp = eventPoint.halfSeg.getDP();
                }

                // if the current halfSegment does not share a dominating point with the next half segment
                if (!S.look_ahead(eventPoint.halfSeg, obj2HV))
                {
                    // the flag bound_point_disjoint is flipped
                    features[3] == true;
                }
            }

            // from both objects
            else
            {
                // if the halfseg is left dominant
                if (eventPoint.halfSeg.isDominatingPointLeft)
                {
                    // add it to the planesweep
                    S.add_left(eventPoint.halfSeg.s);
                }
                else
                {
                    // delete it from the planesweep
                    S.del_right(eventPoint.halfSeg.s);
                }
                // the last dominating point is set equal to the event point's dominating point
                last_dp = eventPoint.halfSeg.getDP();

                // if the halfsegment's dominating point is the same as the next one's
                if (S.look_ahead(eventPoint.halfSeg, obj2HV))
                {
                    // poi_on_interior is flipped
                    features[1] = true;
                }
                else
                {
                    // poi_on_bound is flipped
                    features[2] = true;
                }
            }
            // parallel object traverssal chooses the next event point
            eventPoint = pt.SelectNext();
        }
        while (pt.status != 2 && pt.status != 3 && !(features[0] && features[1] && features[2] && features[3]));
        // if the status is end of second
        if (pt.status == 2)
        {
            // poi_disjoint is true
            features[0] = true;
        }
        return features;
    }

    std::vector<bool> VerifyPredicate::LineRegionAlgorithm(Line2D obj1, Region2D obj2)
    {
        // 0 seg_inside, 1 seg_shared, 2 seg_outside, 3 poi_shared, 4 bound_inside, 5 bound_shared, 6 bound_disjoint, 7 seg_unshared
        vector<bool> features{false, false, false, false, false, false, false, false};
        PlaneSweep S = PlaneSweep();
        SimplePoint2D last_dp_in_F;
        SimplePoint2D last_dp_in_G;
        SimplePoint2D last_bound_in_F;
        Line2D::iterator ptr1;
        Region2D::iterator ptr2;
        vector<HalfSegment2D> obj1HV;
        vector<AttributedHalfSegment2D> obj2HV;

        for (ptr1 = obj1.begin(); ptr1 < obj1.end(); ptr1++)
        {
            obj1HV.push_back(*ptr1);
        }

        for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
        {
            obj2HV.push_back(*ptr2);
        }

        ParallelObjT pt(obj1HV, obj2HV);
        EventPoint eventPoint = pt.SelectNext();
        do 
        {
            // if the current object is the Line2D, this means that the event point 
            // is a halfsegment
            if (pt.object == 1)
            {
                // if this halfsegment is left dominant
                if (eventPoint.halfSeg.isDominatingPointLeft)
                {
                    // add it to the sweep
                    S.add_left(eventPoint.halfSeg.s);
                }
                else
                {
                    // check if there is a predisesor in the plane sweep
                    if (S.pred_exists(eventPoint.halfSeg.s))
                    {
                        // if there is, find the attr values and store them in this pair
                        pair<bool, bool> MpOverNp = S.get_pred_attr_2(eventPoint.halfSeg.s);

                        // if MpOverNp is true
                        if (MpOverNp.second == 1)
                        {
                            // seg_inside is true
                            features[0] = true;
                        }
                        else
                        {
                            // seg_outside is true
                            features[2] = true;
                        }
                    }
                    else
                    {
                        // seg_outside is true
                        features[2] = true;
                    }
                    // delete the halfsegment from the sweep
                    S.del_right(eventPoint.halfSeg.s);
                }
                // get the dominating point from the eventPoint.
                SimplePoint2D p = eventPoint.halfSeg.getDP();

                // if this dominating point is not the last dp in F
                if (p != last_dp_in_F)
                {
                    // make it so
                    last_dp_in_F = p;

                    // if the current halfseg and the next one in the POT do not share a dp
                    if (!S.look_ahead(eventPoint.halfSeg, obj1HV))
                    {
                        // last_bound_in_F is now p
                        last_bound_in_F = p;

                        // We find the Attributed halfsegment version of eventPoint so we can use look_ahead_3
                        AttributedHalfSegment2D halfA = GetAttrHalfSeg(obj2HV, p);

                        // if the last boundary point in F is equal to the last dominating point in G
                        // or the halfsegment exists in G and shares a dominating point with the next one
                        if ((last_bound_in_F == last_dp_in_G) || S.look_ahead_3(halfA, obj2HV))
                        {
                            // bound_shared is true
                            features[5] = true;
                        }
                        else
                        {
                            // if the current event point has a predecessor in the planesweep
                            if (S.pred_exists(eventPoint.halfSeg.s))
                            {
                                // calculate the attr for this event point, store it in the pair
                                pair<bool, bool> MpOverNp = S.get_pred_attr_2(eventPoint.halfSeg.s);
                                if (MpOverNp.second == 1)
                                {
                                    // bound_inside is flipped to true
                                    features[4] = true;
                                }
                                else
                                {
                                    // bound_disjoint is flipped to true
                                    features[6] = true;
                                }
                            }
                            else 
                            {
                                // bound_disjoint is flipped to true
                                features[6] = true;
                            }
                        }
                    }
                }

                // same thing as earlier, getting the attrhalfsegment
                AttributedHalfSegment2D halfA = GetAttrHalfSeg(obj2HV, p);

                if (p != last_bound_in_F && (p == last_dp_in_G || S.look_ahead_3(halfA, obj2HV)))
                {
                    // poi_shared is flipped
                    features[3];
                }
            }

            // if the event point is from the region
            else if (pt.object == 2)
            {
                // ia gets the attribute of the current attrhalfseg
                bool ia = S.get_attr(eventPoint.attrHalfSeg.hs.s);

                // if this attrhalfseg is left dominant
                if (eventPoint.attrHalfSeg.hs.isDominatingPointLeft)
                {
                    // add it to the planesweep
                    S.add_left(eventPoint.halfSeg.s);
                    // set the attr of the segment we added to the planesweep
                    S.set_attr(eventPoint.halfSeg.s, ia);
                }
                else 
                {
                    // delete from plansweep
                    S.del_right(eventPoint.halfSeg.s);
                    // seg_unshared flipped to true
                    features[7] = true;
                }

                // get the dominating point of the halfsegment
                SimplePoint2D p = eventPoint.attrHalfSeg.hs.getDP();

                // if it is not the last dominating point in G
                if (p != last_dp_in_G)
                {
                    // make it so
                    last_dp_in_G = p;
                }
            }

            else
            {
                // seg_shared is true
                features[1] = true;

                // get the attr from the attrhalfseg
                bool ia = S.get_attr(eventPoint.attrHalfSeg.hs.s);

                // if it is a left dominant halfsegment
                if (eventPoint.attrHalfSeg.hs.isDominatingPointLeft)
                {
                    // add the segment to the sweep and set its attr
                    S.add_left(eventPoint.attrHalfSeg.hs.s);
                    S.set_attr(eventPoint.attrHalfSeg.hs.s, ia);
                }
                else
                {
                    // delete it from the sweep
                    S.del_right(eventPoint.attrHalfSeg.hs.s);
                }

                // get the dominating point of the hs
                SimplePoint2D p = eventPoint.attrHalfSeg.hs.getDP();

                // if this point is not the last dp in F
                if (p != last_dp_in_F)
                {
                    // make it so
                    last_dp_in_F = p;

                    // if the current halfsegment does not share a dp with the next in line
                    if (!S.look_ahead(eventPoint.attrHalfSeg.hs, obj1HV))
                    {
                        // bound_shared is flipped to true
                        features[5] = true;
                    }
                    else
                    {
                        // poi_shared is flipped to true
                        features[3] = true;
                    }
                }

                // if this point is not the last dp in G
                if (p != last_dp_in_G)
                {
                    // make it so
                    last_dp_in_G = p;
                }
            }

            // if the POT is at the end of the second object
            if (pt.status == 2)
            {
                // seg_outside is flipped to true
                features[2] = true;
            }

            // POT gets the next event point
            eventPoint = pt.SelectNext();
        }
        while (pt.status != 1 && pt.status != 3 && !(features[0] && features[1] && features[2] && features[3] && features[4] && features[5] && features[6] && features[7]));

        // if POT is at the end of the first object
        if (pt.status = 1)
        {
            // seg_unshared flipped to true
            features[7] = true;
        }
        return features;
    }

    /* for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
        {
            obj2HV.push_back(*ptr2);
            if (obj2HV.back().isDominatingPointLeft)
            {
                obj2PV.push_back(obj2HV.back().s.leftEndPoint);
            }
            else
            {
                obj2PV.push_back(obj2HV.back().s.rightEndPoint);
            }
        }
    */

    HalfSegment2D VerifyPredicate::findHS(vector<HalfSegment2D> HS, SimplePoint2D point)
    {
        for (int i = 0; i < HS.size(); i++)
        {
            if (HS[i].getDP() == point)
            {
                return HS[i];
            }
        }
    }