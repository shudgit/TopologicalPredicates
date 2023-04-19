#include "PlaneSweep.h"
#include <algorithm>
#include <iostream>

//constructor
PlaneSweep::PlaneSweep() {
   //
}

//functions

bool CheckLessThan(Segment2D segToAdd, Segment2D prevSeg) 
{
    SimplePoint2D dp = segToAdd.leftEndPoint;
    SimplePoint2D left = prevSeg.leftEndPoint;
    SimplePoint2D right = prevSeg.rightEndPoint;

    // handle infinite slope
    if (right.x == left.x) {
        return dp < left;
    }

    Number slope = (right.y - left.y) / (right.x - left.x);
    Number b = left.y - (slope * left.x);   // The minus '-' was originally a '/'. I think this is supposed to be based on y=mx+b, which rewrites into b=y-mx.
    Number halfSegY = (dp.x * slope) + b;

    return dp.y < halfSegY;
 
}

bool pointGreaterThan(SimplePoint2D point, Segment2D segment)
{
    SimplePoint2D left = segment.leftEndPoint;
    SimplePoint2D right = segment.rightEndPoint;

    // handle infinite slope
    if (right.x == left.x) {
        return point.y > left.y;
    }

    Number slope = (right.y - left.y) / (right.x - left.x);
    Number b = left.y - (slope * left.x);   
    Number SegY = (point.x * slope) + b;

    return point.y > SegY;
}

void PlaneSweep::add_left(Segment2D segment)
{
    if(sweepStatus.empty())
        sweepStatus.push_back(segment); //add half segment to sweep status at beginning
    else 
    {
        if(segment.leftEndPoint == sweepStatus.back().leftEndPoint) //add half segment to sweep status at end
        {
            sweepStatus.push_back(segment);
        }
        else if(segment.leftEndPoint.x == sweepStatus.back().leftEndPoint.x && segment.leftEndPoint.y > sweepStatus.back().leftEndPoint.y)
        {
            sweepStatus.push_back(segment);
        }
        else if(CheckLessThan(segment, sweepStatus[0])) 
            sweepStatus.emplace(sweepStatus.begin(), segment);
        else //add halfsegment to sweep status somewhere in the middle
        {
            int index = 0;
            while((index < sweepStatus.size()) && !CheckLessThan(segment, sweepStatus[index])) //find index
                index++;
            sweepStatus.emplace(sweepStatus.begin() + index, segment); //emplace at index
        } 
    }   
}

void PlaneSweep::del_right(Segment2D segment)
{
    sweepStatus.erase(find(sweepStatus.begin(), sweepStatus.end(), segment));
    if(attributes.find(segment) != attributes.end())
        attributes.erase(segment);
}

bool PlaneSweep::pred_exists(Segment2D segment)
{
    if(sweepStatus.empty() || sweepStatus[0] == segment) 
        return false;
    else 
        return true;
}

bool PlaneSweep::pred_of_p_exists(SimplePoint2D point)
{
    if(sweepStatus.empty()) {
        return false;
    }
    else {
        SimplePoint2D left = sweepStatus[0].leftEndPoint;
        SimplePoint2D right = sweepStatus[0].rightEndPoint;

        // handle infinite slope
        if (right.x == left.x)
            return point.y > left.y;

        Number slope = (right.y - left.y) / (right.x - left.x);
        Number b = left.y - (slope * left.x);   
        Number SegY = (point.x * slope) + b;

        return point.y > SegY;
    }
}

Segment2D PlaneSweep::pred_of_p(SimplePoint2D point) 
{
    Segment2D returnSeg;
    for(int i = 0; i < sweepStatus.size(); i++)
    {
        if(pointGreaterThan(point, sweepStatus[i]))
            returnSeg = sweepStatus[i];
        else
            break;
    }
    return returnSeg;
}

// Sam and Cody (I think we both independently did this)
bool PlaneSweep::poi_on_seg(SimplePoint2D point) 
{
    for(int i = 0; i < sweepStatus.size(); i++) 
        if(sweepStatus[i].poiOnSeg(point))
            return true;
    return false;
}

bool PlaneSweep::get_attr(Segment2D segment)
{
    bool attr = attributes[segment];
    return attr;
}

void PlaneSweep::set_attr(Segment2D segment, bool attr)
{
    attributes[segment] = attr;
}

bool PlaneSweep::get_pred_attr(SimplePoint2D point)
{
    Segment2D seg = pred_of_p(point);
    return attributes[seg];
}

// Sam
bool PlaneSweep::look_ahead(HalfSegment2D half, std::vector<HalfSegment2D> halfSegs)
{
    for (int i = 0; i < halfSegs.size() - 1; i++)
    {
        if (halfSegs[i] == half)
        {
            if (halfSegs[i].getDP() == halfSegs[i+1].getDP())
            {
                return true;
            }
        }
    }
    return false;
}

// Sam
bool PlaneSweep::look_ahead_3(AttributedHalfSegment2D ahs, std::vector<AttributedHalfSegment2D> segments)
{
    for (int i = 0; i < segments.size() - 1; i++)
    {
        if (segments[i] == ahs)
        {
            if (segments[i].hs.getDP() == segments[i+1].hs.getDP())
            {
                return true;
            }
        }
    }
    return false;
}

/*
    for (int i = 0; i < halfSegs.size(); i++)
    {
        if (halfSegs[i] == half)
        {
            if (halfSegs[i].getDP() == halfSegs[i+1].getDP())
            {
                return true;
            }
        }
    }
    return false; 
    */

// Region Region Functions

std::pair<int, int> PlaneSweep::get_attr_2(Segment2D segment)
{
    return attributes2[segment];
}

void PlaneSweep::set_attr_2(Segment2D segment, std::pair<int, int> p)
{
    attributes2[segment] = p;
}

std::pair<int, int> PlaneSweep::get_pred_attr_2(Segment2D segment)
{
    for(int i = 0; i < sweepStatus.size() - 1; ++i)
        if(sweepStatus[i + 1] == segment)
            return get_attr_2(sweepStatus[i]);
    return std::make_pair(0, 0);
}

AttributedHalfSegment2D PlaneSweep::look_ahead_2(AttributedHalfSegment2D ahs, std::vector<AttributedHalfSegment2D> segments)
{

    for (int i = 0; i < segments.size() - 1; ++i)
        if (segments[i] == ahs)
        {
            AttributedHalfSegment2D ans = segments[i + 1];
            /*if(ans.hs.isDominatingPointLeft)
                return ans.hs.s.leftEndPoint;
            else
                return ans.hs.s.rightEndPoint;*/
            return ans;
        }
    // if it was not found in the for loop, it must be the last segment
    // if last segment just return its own point as it is checked before the look_ahead call anyway so will not impact the result.
    /*if(ahs.hs.isDominatingPointLeft)
                return ahs.hs.s.leftEndPoint;
            else
                return ahs.hs.s.rightEndPoint;*/
    return ahs;
}

bool PlaneSweep::coincident(Segment2D segment)
{
    std::cout << "entered coincident" << std::endl;
    for(int i = 0; i < sweepStatus.size(); ++i)
    {
        if(sweepStatus[i] == segment)               // technically cannot intersect with a segment from its own object
        {
            if(i > 0)                               //check intersect with sweepStatus[i - 1]
                if((segment.findIntersection_excludeEndpoints(sweepStatus[i - 1])).first)
                {
                    SimplePoint2D iPoint = segment.findIntersection_excludeEndpoints(sweepStatus[i - 1]).second;

                    Segment2D seg1 = Segment2D(iPoint, segment.rightEndPoint);
                    Segment2D seg2 = Segment2D(segment.leftEndPoint, iPoint);
                    Segment2D seg3 = Segment2D(iPoint, sweepStatus[i - 1].rightEndPoint);
                    Segment2D seg4 = Segment2D(sweepStatus[i - 1].leftEndPoint, iPoint);

                    HalfSegment2D hs1 = HalfSegment2D(seg1, false);
                    HalfSegment2D hs2 = HalfSegment2D(seg1, true);
                    HalfSegment2D hs3 = HalfSegment2D(seg2, false);
                    HalfSegment2D hs4 = HalfSegment2D(seg2, true);
                    HalfSegment2D hs5 = HalfSegment2D(seg3, false);
                    HalfSegment2D hs6 = HalfSegment2D(seg3, true);
                    HalfSegment2D hs7 = HalfSegment2D(seg4, false);
                    HalfSegment2D hs8 = HalfSegment2D(seg4, true);

                    std::cout << "exited coincident if" << std::endl;
                    return true;
                }
            else if(i < sweepStatus.size() - 1)     //check intersect with sweepStatus[i + 1]
                if((segment.findIntersection_excludeEndpoints(sweepStatus[i + 1])).first)
                {
                    SimplePoint2D iPoint = segment.findIntersection_excludeEndpoints(sweepStatus[i + 1]).second;

                    Segment2D seg1 = Segment2D(iPoint, segment.rightEndPoint);
                    Segment2D seg2 = Segment2D(segment.leftEndPoint, iPoint);
                    Segment2D seg3 = Segment2D(iPoint, sweepStatus[i + 1].rightEndPoint);
                    Segment2D seg4 = Segment2D(sweepStatus[i + 1].leftEndPoint, iPoint);

                    HalfSegment2D hs1 = HalfSegment2D(seg1, false);
                    HalfSegment2D hs2 = HalfSegment2D(seg1, true);
                    HalfSegment2D hs3 = HalfSegment2D(seg2, false);
                    HalfSegment2D hs4 = HalfSegment2D(seg2, true);
                    HalfSegment2D hs5 = HalfSegment2D(seg3, false);
                    HalfSegment2D hs6 = HalfSegment2D(seg3, true);
                    HalfSegment2D hs7 = HalfSegment2D(seg4, false);
                    HalfSegment2D hs8 = HalfSegment2D(seg4, true);

                    std::cout << "exited coincident else " << std::endl;
                    return true;
                }
        }
    }
    std::cout << "exited coincident end" << std::endl;
    return false;
}