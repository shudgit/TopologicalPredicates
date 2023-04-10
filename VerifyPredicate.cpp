#include "VerifyPredicate.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "SimplePoint2D.h"
#include "EventPoint.h"
#include <vector>
#include <unordered_map>


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
    
    //Line || Line
    std::vector<bool> LineLineAlgorithm(Line2D line1, Line2D line2)
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
    std::vector<bool> PointRegionAlgorithm(Point2D points, Region2D region)
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
        std::vector<SimplePoint2D> fPoints;
        std::vector<SimplePoint2D> gPoints;
        for(Region2D::iterator iter = f.begin(); iter != f.end(); iter++)
        {
            fSegments.push_back(*iter);
            if((*iter).hs.isDominatingPointLeft)
                fPoints.push_back((*iter).hs.s.leftEndPoint);
            else
                fPoints.push_back((*iter).hs.s.rightEndPoint);
        }
        for(Region2D::iterator iter = g.begin(); iter != g.end(); iter++)
        {
            gSegments.push_back(*iter);
            if((*iter).hs.isDominatingPointLeft)
                gPoints.push_back((*iter).hs.s.leftEndPoint);
            else
                gPoints.push_back((*iter).hs.s.rightEndPoint);
        }

        PlaneSweep sweep;
        ParallelObjT pot(fPoints, gPoints);   // start of parallel object traversal
        SimplePoint2D next = pot.SelectNext();
        SimplePoint2D last_dp_in_f;
        SimplePoint2D last_dp_in_g;

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
            // find the ahs corresponding 
            /*if(!ahs.hs.isDominatingPointLeft)
            {
                pair<int, int> overlap_numbers = get_attr_2(seg)
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
                sweep.del_right(seg);
            }
            else
            {
                pair<int, int> mn_pred;
                sweep.add_left(seg);
                if(sweep.coincident(seg))
                    pot.object = 3;
                if(!sweep.pred_exists(seg))
                    mn_pred = make_pair(3, 0);       // 3 = *
                else
                    mn_pred = get_pred_attr_2(seg);
                pair<int, int> mn = make_pair(mn_pred.second, mn_pred.second);
                if(pot.object == 1 || pot.object == 3)
                {
                    if(get_attr_2())
                        mn.second += 1;
                    else
                        mn.second -= 1;
                }
                if(pot.object == 2 || pot.object == 3)
                {
                    if(get_attr_2())
                        mn.second += 1;
                    else
                        mn.second -= 1;
                }
                set_attr_2(seg, mn);
            }
            next = pot.SelectNext();
            */
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
        vector<SimplePoint2D> obj2PV;


        for (ptr = obj1.begin(); ptr < obj1.end(); ptr++)
        {
            obj1V.push_back(*ptr);
        }

        for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
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

        ParallelObjT pt(obj1V, obj2PV);
        EventPoint eventPoint = pt.SelectNext();

        do
        {
            if (pt.object == 1)
            {
                if (S.poi_on_seg(eventPoint.point))
                {
                    features[1] = true;
                }
                else
                {
                    features[0] = true;
                }
            }
            else if (pt.object = 2)
            {
                HalfSegment2D half = findHS(obj2HV, eventPoint.point);
                if (half.isDominatingPointLeft)
                {
                    S.add_left(half.s);
                }
                else
                {
                    S.del_right(half.s);
                }
                if (eventPoint.point != last_dp)
                {
                    last_dp = eventPoint.point;
                }
                if (!S.look_ahead(half, obj2HV))
                {
                    features[3] == true;
                }
            }
            else
            {
                HalfSegment2D half = findHS(obj2HV, eventPoint.point);
                if (half.isDominatingPointLeft)
                {
                    S.add_left(half.s);
                }
                else
                {
                    S.del_right(half.s);
                }
                last_dp = eventPoint.point;
                if (S.look_ahead(half,obj2HV))
                {
                    features[1] = true;
                }
                else
                {
                    features[2] = true;
                }
            }
            eventPoint = pt.SelectNext();
        }
        while (pt.status != 2 && pt.status != 3 && !(features[0] && features[1] && features[2] && features[3]));
        if (pt.status == 2)
        {
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
        vector<SimplePoint2D> obj1PV;
        vector<AttributedHalfSegment2D> obj2HV;
        vector<SimplePoint2D> obj2PV;

        for (ptr1 = obj1.begin(); ptr1 < obj1.end(); ptr1++)
        {
            obj1HV.push_back(*ptr1);
            if (obj1HV.back().isDominatingPointLeft)
            {
                obj1PV.push_back(obj1HV.back().s.leftEndPoint);
            }
            else
            {
                obj1PV.push_back(obj1HV.back().s.rightEndPoint);
            }
        }

        for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
        {
            obj2HV.push_back(*ptr2);
            if (obj2HV.back().hs.isDominatingPointLeft)
            {
                obj2PV.push_back(obj2HV.back().hs.s.leftEndPoint);
            }
            else
            {
                obj2PV.push_back(obj2HV.back().hs.s.rightEndPoint);
            }
        }

        ParallelObjT pt(obj1PV, obj2PV);
        EventPoint eventPoint = pt.SelectNext();
        do 
        {
            if (pt.object == 1)
            {
                HalfSegment2D half = findHS(obj1HV, eventPoint.point);
                if (half.isDominatingPointLeft)
                {
                    S.add_left(half.s);
                }
                else
                {
                    if (S.pred_exists(half.s))
                    {
                        pair<bool, bool> MpOverNp = S.get_pred_attr_2(half.s);
                        if (MpOverNp.second == 1)
                        {
                            features[0] = true;
                        }
                        else
                        {
                            features[2] = true;
                        }
                    }
                    else
                    {
                        features[2] = true;
                    }
                    S.del_right(half.s);
                }
                SimplePoint2D p = half.getDP();
                if (p != last_dp_in_F)
                {
                    last_dp_in_F = p;
                    if (!S.look_ahead(half, obj1HV))
                    {
                        last_bound_in_F = p;
                        AttributedHalfSegment2D halfA = GetAttrHalfSeg(obj2HV, p);
                        if ((last_bound_in_F == last_dp_in_G) || S.look_ahead_3(halfA, obj2HV))
                        {
                            features[5] = true;
                        }
                        else
                        {
                            if (S.pred_exists(half.s))
                            {
                                pair<bool, bool> MpOverNp = S.get_pred_attr_2(half.s);
                                if (MpOverNp.second == 1)
                                {
                                    features[4] = true;
                                }
                                else
                                {
                                    features[6] = true;
                                }
                            }
                            else 
                            {
                                features[6] = true;
                            }
                        }
                    }
                }
                AttributedHalfSegment2D halfA = GetAttrHalfSeg(obj2HV, p);
                if (p != last_bound_in_F && (p == last_dp_in_G || S.look_ahead_3(halfA, obj2HV)))
                {
                    features[3];
                }
            }
            else if (pt.object == 2)
            {
                HalfSegment2D half = findHS(obj1HV, eventPoint.point);
                bool ia = S.get_attr(half.s);
                if (half.isDominatingPointLeft)
                {
                    S.add_left(half.s);
                    S.set_attr(half.s, ia);
                }
                else 
                {
                    S.del_right(half.s);
                    features[7] = true;
                }
                SimplePoint2D p = half.getDP();
                if (p != last_dp_in_G)
                {
                    last_dp_in_G = p;
                }
            }
            else
            {
                features[1] = true;
                HalfSegment2D half = findHS(obj1HV, eventPoint.point);
                bool ia = S.get_attr(half.s);
                if (half.isDominatingPointLeft)
                {
                    S.add_left(half.s);
                    S.set_attr(half.s, ia);
                }
                else
                {
                    S.del_right(half.s);
                }
                SimplePoint2D p = half.getDP();
                if (p != last_dp_in_F)
                {
                    last_dp_in_F = p;
                    if (!S.look_ahead(half, obj1HV))
                    {
                        features[5] = true;
                    }
                    else
                    {
                        features[3] = true;
                    }
                }
                if (p != last_dp_in_G)
                {
                    last_dp_in_G = p;
                }
            }
            if (pt.status == 2)
            {
                features[2] = true;
            }
            eventPoint = pt.SelectNext();
        }
        while (pt.status != 1 && pt.status != 3 && !(features[0] && features[1] && features[2] && features[3] && features[4] && features[5] && features[6] && features[7]));
        if (pt.status = 1)
        {
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