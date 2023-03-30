#include "PlaneSweep.h"

//constructor
PlaneSweep::PlaneSweep() {
    
}

//functions
void PlaneSweep::add_left(SimplePoint2D dp, Segment2D segment)
{
            if(sweepStatus.empty())
            {
                sweepStatus.push_back(segment); //add half segment to sweep status at beginning
            }
            else if(dp == sweepStatus.back().leftEndPoint) //add half segment to sweep status at end
            {
                sweepStatus.push_back(segment);
            }
            else if(dp == sweepStatus.back().rightEndPoint) {

            }
            else //add halfsegment to sweep status somewhere in the middle
            {
                int index = sweepStatus.size() - 1;
                while(!CheckLessThan(GetDominatePoint(currentHalfSeg), sweepStatus[index])) //find index
                {
                    index -= 1;
                }
                sweepStatus.emplace(sweepStatus.begin() + index, segment); //emplace at index
            }
}

void PlaneSweep::del_right(SimplePoint2D dp, Segment2D segment)
{

}

SimplePoint2D PlaneSweep::get_event()
{

}

bool PlaneSweep::pred_exists()
{

}

Segment2D PlaneSweep::pred_of_p() 
{

}