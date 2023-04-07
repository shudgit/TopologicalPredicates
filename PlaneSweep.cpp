#include "PlaneSweep.h"

//constructor
PlaneSweep::PlaneSweep() {
   //
}

//functions
void PlaneSweep::add_left(Segment2D segment)
{
    if(sweepStatus.empty())
    {
        sweepStatus.push_back(segment); //add half segment to sweep status at beginning
    }
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
        else //add halfsegment to sweep status somewhere in the middle
        {
            int index = sweepStatus.size() - 1;
            while(!CheckLessThan(segment, sweepStatus[index])) //find index
            {
                index -= 1;
            }
            sweepStatus.emplace(sweepStatus.begin() + index, segment); //emplace at index
            segment.findIntersection(sweepStatus[index]);
        } 
    }   
}

void PlaneSweep::del_right(Segment2D segment)
{
    sweepStatus.erase(std::find(sweepStatus.begin(), sweepStatus.end(), segment));
}

SimplePoint2D PlaneSweep::get_event() //Not sure if this is needed
{
    return currentEventPoint; 
}

bool PlaneSweep::pred_exists(Segment2D segment)
{
    if(sweepStatus[0] == segment) 
    {
        return false;
    }
    else 
    {
        return true;
    }
}

Segment2D PlaneSweep::pred_of_p(Segment2D segment) 
{
    //find segment in vector and return that index - 1;
    auto itr = std::find(sweepStatus.begin(), sweepStatus.end(), segment);
    itr = itr--;
    return *itr;
}

bool PlaneSweep::poi_on_seg(SimplePoint2D point) {
    for(int i = 0; i < sweepStatus.size(); i++) 
    {
        if(sweepStatus[i].poiOnSeg(point))
        {
            return true;
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