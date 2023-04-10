#include "PlaneSweep.h"
#include <algorithm>

//constructor
PlaneSweep::PlaneSweep() {
   //
}

//functions
void PlaneSweep::add_left(Segment2D segment)
{
    if(sweepStatus.empty())
        sweepStatus.push_back(segment); //add half segment to sweep status at beginning
    else 
    {
        if(segment.leftEndPoint == sweepStatus.back().leftEndPoint) //add half segment to sweep status at end
        {
            sweepStatus.push_back(segment);
            auto itr = sweepStatus.end();
            segment.findIntersection(*(itr--));
        }
        else if(segment.leftEndPoint.x == sweepStatus.back().leftEndPoint.x && segment.leftEndPoint.y > sweepStatus.back().leftEndPoint.y)
        {
            sweepStatus.push_back(segment);
            auto itr = sweepStatus.end();
            segment.findIntersection(*(itr--));
        }
        else if(CheckLessThan(segment, sweepStatus[0])) 
            sweepStatus.emplace(sweepStatus.begin(), segment);
        else //add halfsegment to sweep status somewhere in the middle
        {
            int index = 0;
            while((index < sweepStatus.size()) && !CheckLessThan(segment, sweepStatus[index])) //find index
                index++;
            sweepStatus.emplace(sweepStatus.begin() + index, segment); //emplace at index
            segment.findIntersection(sweepStatus[index]);
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
    if(sweepStatus[0] == segment) 
        return false;
    else 
        return true;
}

bool PlaneSweep::pred_of_p_exists(SimplePoint2D point)
{
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

bool PlaneSweep::look_ahead(HalfSegment2D half, std::vector<HalfSegment2D> halfSegs)
{
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
}

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

SimplePoint2D PlaneSweep::look_ahead_2(AttributedHalfSegment2D ahs, std::vector<AttributedHalfSegment2D> segments)
{

    for (int i = 0; i < segments.size() - 1; ++i)
        if (segments[i] == ahs)
        {
            AttributedHalfSegment2D ans = segments[i + 1];
            if(ans.hs.isDominatingPointLeft)
                return ans.hs.s.leftEndPoint;
            else
                return ans.hs.s.rightEndPoint;
        }
    // if it was not found in the for loop, it must be the last segment
    // if last segment just return its own point as it is checked before the look_ahead call anyway so will not impact the result.
    if(ahs.hs.isDominatingPointLeft)
                return ahs.hs.s.leftEndPoint;
            else
                return ahs.hs.s.rightEndPoint;
}

bool PlaneSweep::look_ahead_3(AttributedHalfSegment2D ahs, std::vector<AttributedHalfSegment2D> segments)
{
    for (int i = 0; i < segments.size(); i++)
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