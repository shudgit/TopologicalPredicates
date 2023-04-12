#include "ParallelObjTraversal.h"
#include <iostream>

ParallelObjT::ParallelObjT(std::vector<SimplePoint2D> obj1, std::vector<SimplePoint2D> obj2) 
{
    object1Type = 0;
    object2Type = 0;
    for(int i = 0; i < obj1.size(); i++) 
    {
        point1Queue.push(obj1[i]);
    }
    for(int i = 0; i < obj2.size(); i++) 
    {
        point2Queue.push(obj2[i]);
    }
}

ParallelObjT::ParallelObjT(std::vector<SimplePoint2D> obj1, std::vector<HalfSegment2D> obj2) 
{
    object1Type = 0;
    object2Type = 1;
    for(int i = 0; i < obj1.size(); i++) 
    {
        point1Queue.push(obj1[i]);
    }
    for(int i = 0; i < obj2.size(); i++) 
    {
        line2Queue.push(obj2[i]);
    }
}

ParallelObjT::ParallelObjT(std::vector<SimplePoint2D> obj1, std::vector<AttributedHalfSegment2D> obj2) 
{
    object1Type = 0;
    object2Type = 2;
    for(int i = 0; i < obj1.size(); i++) 
    {
        point1Queue.push(obj1[i]);
    }
    for(int i = 0; i < obj2.size(); i++) 
    {
        region2Queue.push(obj2[i]);
    }
}

ParallelObjT::ParallelObjT(std::vector<HalfSegment2D> obj1, std::vector<HalfSegment2D> obj2) 
{
    object1Type = 1;
    object2Type = 1;
    for(int i = 0; i < obj1.size(); i++) 
    {
        line1Queue.push(obj1[i]);
    }
    for(int i = 0; i < obj2.size(); i++) 
    {
        line2Queue.push(obj2[i]);
    }
}

ParallelObjT::ParallelObjT(std::vector<HalfSegment2D> obj1, std::vector<AttributedHalfSegment2D> obj2) 
{
    object1Type = 1;
    object2Type = 2;
    for(int i = 0; i < obj1.size(); i++) 
    {
        line1Queue.push(obj1[i]);
    }
    for(int i = 0; i < obj2.size(); i++) 
    {
        region2Queue.push(obj2[i]);
    }
}

ParallelObjT::ParallelObjT(std::vector<AttributedHalfSegment2D> obj1, std::vector<AttributedHalfSegment2D> obj2) 
{
    object1Type = 2;
    object2Type = 2;
    for(int i = 0; i < obj1.size(); i++) 
    {
        region1Queue.push(obj1[i]);
    }
    for(int i = 0; i < obj2.size(); i++) 
    {
        region2Queue.push(obj2[i]);
    }
}

EventPoint ParallelObjT::SelectNext() 
{
    if(object1Type == 0 && object2Type == 0)
        return PointPointNext();
    else if(object1Type == 0 && object2Type == 1)
        return PointLineNext();
    else if(object1Type == 0 && object2Type == 2)
        return PointRegionNext();
    else if(object1Type == 1 && object2Type == 1)
        return LineLineNext();
    else if(object1Type == 1 && object2Type == 2)
        return LineRegionNext();
    else if(object1Type == 2 && object2Type == 2)
        return RegionRegionNext();
}

EventPoint ParallelObjT::PointPointNext() 
{
    EventPoint newEvent;
    SimplePoint2D obj1NextPoint;
    if(!point1Queue.empty()) {
        if(point1Dynamic.empty() || point1Queue.front() < point1Dynamic.front()) 
        {
            obj1NextPoint = point1Queue.front();
        }
        else if (point1Queue.front() > point1Dynamic.front()) 
        {
            obj1NextPoint = point1Dynamic.front();
        }
    }

    SimplePoint2D obj2NextPoint;
    if(!point2Queue.empty()) {
        if(point2Dynamic.empty() || point2Queue.front() < point2Dynamic.front()) 
        {
            obj2NextPoint = point2Queue.front();
        }
        else if (point2Queue.front() > point2Dynamic.front()) 
        {
            obj2NextPoint = point2Dynamic.front();
        }
    }

    
    if(!point1Queue.empty() && (point2Queue.empty() || obj1NextPoint < obj2NextPoint)) 
    {
        if(obj1NextPoint == point1Queue.front())
        {
            point1Queue.pop();
        }
        else 
        {
            point1Dynamic.pop();
        }
        object = 1;

        if(point1Queue.empty() && point1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

        newEvent.point = obj1NextPoint;
        return newEvent;
    }
    else if(!point2Queue.empty() && (point1Queue.empty() || obj1NextPoint > obj2NextPoint))
    {
        if(obj2NextPoint == point2Queue.front())
        {
            point2Queue.pop();
        }
        else 
        {
            point2Dynamic.pop();
        }
        object = 2;

        if(point2Queue.empty() && point2Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }

        newEvent.point = obj2NextPoint;
        return newEvent;
    }
    else if(!point1Queue.empty() && !point2Queue.empty())
    {
        if(obj1NextPoint == point1Queue.front())
        {
            point1Queue.pop();
        }
        else 
        {
            point1Dynamic.pop();
        }
        if(obj2NextPoint == point2Queue.front())
        {
            point2Queue.pop();
        }
        else 
        {
            point2Dynamic.pop();
        }
        object = 3;

        if(point1Queue.empty() && point1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

            if(point2Queue.empty() && point2Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }
        
        newEvent.point = obj1NextPoint;
        return newEvent;
    }
}

EventPoint ParallelObjT::PointLineNext()
{
    EventPoint newEvent;
    SimplePoint2D obj1NextPoint;
    if(!point1Queue.empty()) {
        if(point1Dynamic.empty() || point1Queue.front() < point1Dynamic.front()) 
        {
            obj1NextPoint = point1Queue.front();
        }
        else if (point1Queue.front() > point1Dynamic.front()) 
        {
            obj1NextPoint = point1Dynamic.front();
        }
    }

    HalfSegment2D obj2NextHalfSeg;
    if(!line2Queue.empty()) {
        if(line2Dynamic.empty() || line2Queue.front() < line2Dynamic.front()) 
        {
            obj2NextHalfSeg = line2Queue.front();
        }
        else if (line2Queue.front() > line2Dynamic.front()) 
        {
            obj2NextHalfSeg = line2Dynamic.front();
        }
    }

    std::cout << point1Queue.size() << " " << line2Queue.size() << std::endl;
    if((!point1Queue.empty()) && (line2Queue.empty() || obj1NextPoint < obj2NextHalfSeg.getDP())) 
    {
        std::cout << "1" << std::endl;
        if(obj1NextPoint == point1Queue.front())
        {
            point1Queue.pop();
        }
        else 
        {
            point1Dynamic.pop();
        }
        object = 1;

        if(point1Queue.empty() && point1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

        newEvent.point = obj1NextPoint;
        return newEvent;
    }
    else if((!line2Queue.empty()) && (point1Queue.empty() || obj1NextPoint > obj2NextHalfSeg.getDP()))
    {
        std::cout << "2" << std::endl;
        if(obj2NextHalfSeg == line2Queue.front())
        {
            line2Queue.pop();
        }
        else 
        {
            line2Dynamic.pop();
        }
        object = 2;

        if(line2Queue.empty() && line2Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }

        newEvent.halfSeg = obj2NextHalfSeg;
        return newEvent;
    }
    else if(!point1Queue.empty() && !line2Queue.empty())
    {
        std::cout << "3" << std::endl;
        if(obj1NextPoint == point1Queue.front())
        {
            point1Queue.pop();
        }
        else 
        {
            point1Dynamic.pop();
        }
        if(obj2NextHalfSeg == line2Queue.front())
        {
            line2Queue.pop();
        }
        else 
        {
            line2Dynamic.pop();
        }
        object = 3;

        if(point1Queue.empty() && point1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

        if(line2Queue.empty() && line2Queue.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }
        
        newEvent.point = obj1NextPoint;
        newEvent.halfSeg = obj2NextHalfSeg;
        return newEvent;
    }
}

EventPoint ParallelObjT::PointRegionNext() 
{
    EventPoint newEvent;
    SimplePoint2D obj1NextPoint;
    if(!point1Queue.empty()) {
        if(point1Dynamic.empty() || point1Queue.front() < point1Dynamic.front()) 
        {
            obj1NextPoint = point1Queue.front();
        }
        else if (point1Queue.front() > point1Dynamic.front()) 
        {
            obj1NextPoint = point1Dynamic.front();
        }
    }

    AttributedHalfSegment2D obj2NextHalfSeg;
    if(!region2Queue.empty()) {
        if(region2Dynamic.empty() || region2Queue.front() < region2Dynamic.front()) 
        {
            obj2NextHalfSeg = region2Queue.front();
        }
        else if (region2Queue.front() > region2Dynamic.front()) 
        {
            obj2NextHalfSeg = region2Dynamic.front();
        }
    }
    
    if(!point1Queue.empty() && (region2Queue.empty() || obj1NextPoint < obj2NextHalfSeg.hs.getDP())) 
    {
        if(obj1NextPoint == point1Queue.front())
        {
            point1Queue.pop();
        }
        else 
        {
            point1Dynamic.pop();
        }
        object = 1;

        if(point1Queue.empty() && point1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

        newEvent.point = obj1NextPoint;
        return newEvent;
    }
    else if(!region2Queue.empty() &&  (point1Queue.empty() || obj1NextPoint > obj2NextHalfSeg.hs.getDP()))
    {
        if(obj2NextHalfSeg == region2Queue.front())
        {
            region2Queue.pop();
        }
        else 
        {
            region2Dynamic.pop();
        }
        object = 2;

        if(region2Queue.empty() && region2Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }

        newEvent.attrHalfSeg = obj2NextHalfSeg;
        return newEvent;
    }
    else if(!point1Queue.empty() && !region2Queue.empty())
    {
        if(obj1NextPoint == point1Queue.front())
        {
            point1Queue.pop();
        }
        else 
        {
            point1Dynamic.pop();
        }
        if(obj2NextHalfSeg == region2Queue.front())
        {
            region2Queue.pop();
        }
        else 
        {
            region2Dynamic.pop();
        }
        object = 3;

        if(point1Queue.empty() && point1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

            if(region2Queue.empty() && region2Queue.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }
        
        newEvent.point = obj1NextPoint;
        newEvent.attrHalfSeg = obj2NextHalfSeg;
        return newEvent;
    }
}

EventPoint ParallelObjT::LineLineNext() 
{
    EventPoint newEvent;
    HalfSegment2D obj1NextHalfSeg;
    if(!line1Queue.empty()) {
        if(line1Dynamic.empty() || line1Queue.front() < line1Dynamic.front()) 
        {
            obj1NextHalfSeg = line1Queue.front();
        }
        else if (line1Queue.front() > line1Dynamic.front()) 
        {
            obj1NextHalfSeg = line1Dynamic.front();
        }
    }

    HalfSegment2D obj2NextHalfSeg;
    if(!line2Queue.empty()) {
        if(line2Dynamic.empty() || line2Queue.front() < line2Dynamic.front()) 
        {
            obj2NextHalfSeg = line2Queue.front();
        }
        else if (line2Queue.front() > line2Dynamic.front()) 
        {
            obj2NextHalfSeg = line2Dynamic.front();
        }
    }

    
    if(!line1Queue.empty() && (line2Queue.empty() || obj1NextHalfSeg < obj2NextHalfSeg)) 
    {
        if(obj1NextHalfSeg == line1Queue.front())
        {
            line1Queue.pop();
        }
        else 
        {
            line1Dynamic.pop();
        }
        object = 1;

        if(line1Queue.empty() && line1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

        newEvent.halfSeg = obj1NextHalfSeg;
        return newEvent;
    }
    else if(!line2Queue.empty() && (line1Queue.empty() || obj1NextHalfSeg > obj2NextHalfSeg))
    {
        if(obj2NextHalfSeg == line2Queue.front())
        {
            line2Queue.pop();
        }
        else 
        {
            line2Dynamic.pop();
        }
        object = 2;

        if(line2Queue.empty() && line2Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }

        newEvent.halfSeg = obj2NextHalfSeg;
        return newEvent;
    }
    else if(!line1Queue.empty() && !line2Queue.empty())
    {
        if(obj1NextHalfSeg == line1Queue.front())
        {
            line1Queue.pop();
        }
        else 
        {
            line1Dynamic.pop();
        }
        if(obj2NextHalfSeg == line2Queue.front())
        {
            line2Queue.pop();
        }
        else 
        {
            line2Dynamic.pop();
        }
        object = 3;

        if(line1Queue.empty() && line1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

            if(line2Queue.empty() && line2Queue.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }
        
        newEvent.halfSeg = obj1NextHalfSeg;
        return newEvent;
    }
}

EventPoint ParallelObjT::LineRegionNext()
{
    EventPoint newEvent;
    HalfSegment2D obj1NextHalfSeg;
    if(!line1Queue.empty()) {
        if(line1Dynamic.empty() || line1Queue.front() < line1Dynamic.front()) 
        {
            obj1NextHalfSeg = line1Queue.front();
        }
        else if (line1Queue.front() > line1Dynamic.front()) 
        {
            obj1NextHalfSeg = line1Dynamic.front();
        }
    }

    AttributedHalfSegment2D obj2NextHalfSeg;
    if(!region2Queue.empty()) {
        if(region2Dynamic.empty() || region2Queue.front() < region2Dynamic.front()) 
        {
            obj2NextHalfSeg = region2Queue.front();
        }
        else if (region2Queue.front() > region2Dynamic.front()) 
        {
            obj2NextHalfSeg = region2Dynamic.front();
        }
    }

    
    if(!line1Queue.empty() && (region2Queue.empty() || obj1NextHalfSeg < obj2NextHalfSeg.hs)) 
    {
        if(obj1NextHalfSeg == line1Queue.front())
        {
            line1Queue.pop();
        }
        else 
        {
            line1Dynamic.pop();
        }
        object = 1;

        if(line1Queue.empty() && line1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

        newEvent.halfSeg = obj1NextHalfSeg;
        return newEvent;
    }
    else if(!region2Queue.empty() && (line1Queue.empty() || obj1NextHalfSeg > obj2NextHalfSeg.hs))
    {
        if(obj2NextHalfSeg == region2Queue.front())
        {
            region2Queue.pop();
        }
        else 
        {
            region2Dynamic.pop();
        }
        object = 2;

        if(region2Queue.empty() && region2Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }

        newEvent.attrHalfSeg = obj2NextHalfSeg;
        return newEvent;
    }
    else if(!line1Queue.empty() && !region2Queue.empty())
    {
        if(obj1NextHalfSeg == line1Queue.front())
        {
            line1Queue.pop();
        }
        else 
        {
            line1Dynamic.pop();
        }
        if(obj2NextHalfSeg == region2Queue.front())
        {
            region2Queue.pop();
        }
        else 
        {
            region2Dynamic.pop();
        }
        object = 3;

        if(line1Queue.empty() && line1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

            if(region2Queue.empty() && region2Queue.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }
        
        newEvent.halfSeg = obj1NextHalfSeg;
        newEvent.attrHalfSeg = obj2NextHalfSeg;
        return newEvent;
    }
}

EventPoint ParallelObjT::RegionRegionNext()
{
    EventPoint newEvent;
    AttributedHalfSegment2D obj1NextHalfSeg;
    if(!region1Queue.empty()) {
        if(region1Dynamic.empty() || region1Queue.front() < region1Dynamic.front()) 
        {
            obj1NextHalfSeg = region1Queue.front();
        }
        else if (region1Queue.front() > region1Dynamic.front()) 
        {
            obj1NextHalfSeg = region1Dynamic.front();
        }
    }

    AttributedHalfSegment2D obj2NextHalfSeg;
    if(!region2Queue.empty()) {
        if(region2Dynamic.empty() || region2Queue.front() < region2Dynamic.front()) 
        {
            obj2NextHalfSeg = region2Queue.front();
        }
        else if (region2Queue.front() > region2Dynamic.front()) 
        {
            obj2NextHalfSeg = region2Dynamic.front();
        }
    }

    
    if(!region1Queue.empty() && (region2Queue.empty() || obj1NextHalfSeg < obj2NextHalfSeg)) 
    {
        if(obj1NextHalfSeg == region1Queue.front())
        {
            region1Queue.pop();
        }
        else 
        {
            region1Dynamic.pop();
        }
        object = 1;

        if(region1Queue.empty() && region1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

        newEvent.attrHalfSeg = obj1NextHalfSeg;
        return newEvent;
    }
    else if(!region2Queue.empty() && (region1Queue.empty() || obj1NextHalfSeg > obj2NextHalfSeg))
    {
        if(obj2NextHalfSeg == region2Queue.front())
        {
            region2Queue.pop();
        }
        else 
        {
            region2Dynamic.pop();
        }
        object = 2;

        if(region2Queue.empty() && region2Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }

        newEvent.attrHalfSeg = obj2NextHalfSeg;
        return newEvent;
    }
    else if(!region1Queue.empty() && !region2Queue.empty())
    {
        if(obj1NextHalfSeg == region1Queue.front())
        {
            region1Queue.pop();
        }
        else 
        {
            region1Dynamic.pop();
        }
        if(obj2NextHalfSeg == region2Queue.front())
        {
            region2Queue.pop();
        }
        else 
        {
            region2Dynamic.pop();
        }
        object = 3;

        if(region1Queue.empty() && region1Dynamic.empty()) 
        {
            if(status == 0) 
            {
                status = 1;
            }
            else if(status == 2)
            {
                status = 3;
            }
        }

            if(region2Queue.empty() && region2Queue.empty()) 
        {
            if(status == 0) 
            {
                status = 2;
            }
            else if(status == 1)
            {
                status = 3;
            }
        }
        
        newEvent.attrHalfSeg = obj1NextHalfSeg;
        newEvent.attrHalfSeg2 = obj2NextHalfSeg;
        return newEvent;
    }
}