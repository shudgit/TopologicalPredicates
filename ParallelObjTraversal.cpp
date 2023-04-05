#include "ParallelObjTraversal.h"

ParallelObjT::ParallelObjT(std::vector obj1, std::vector obj2) 
{
    for(int i = 0; i < obj1.size(); i++) {
        obj1Queue.push_back(obj1[i]);
    }
    for(int i = 0; i < obj2.size(); i++) {
        obj2Queue.push_back(obj2[i]);
    }
}
SimplePoint2D ParallelObjT::SelectNext() 
    {
        SimplePoint2D obj1NextPoint;
        if(obj1Dynamic.empty() || obj1Queue.front() < obj1Dynamic.front()) 
        {
            obj1NextPoint = obj1Queue.front();
        }
        else if (obj1Queue.front() > obj1Dynamic.front()) 
        {
            obj1NextPoint = obj1Dynamic.front();
        }

        SimplePoint2D obj2NextPoint;
        if(obj2Dynamic.empty() || obj2Queue.front() < obj2Dynamic.front()) 
        {
            obj2NextPoint = obj2Queue.front();
        }
        else if (obj2Queue.front() > obj2Dynamic.front()) 
        {
            obj2NextPoint = obj2Dynamic.front();
        }

        
        if(obj1NextPoint < obj2NextPoint) 
        {
            if(obj1NextPoint == obj1Queue.front())
            {
                obj1Queue.pop_front();
            }
            else 
            {
                obj1Dynamic.pop_front();
            }
            object = 1;

            if(obj1Queue.empty() && obj1Dynamic.empty()) 
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

            return obj1NextPoint;
        }
        else if(obj1NextPoint > obj2NextPoint)
        {
            if(obj2NextPoint == obj2Queue.front())
            {
                obj2Queue.pop_front();
            }
            else 
            {
                obj2Dynamic.pop_front();
            }
            object = 2;

            if(obj2Queue.empty() && obj2Dynamic.empty()) 
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

            return obj2NextPoint;
        }
        else
        {
            if(obj1NextPoint == obj1Queue.front())
            {
                obj1Queue.pop_front();
            }
            else 
            {
                obj1Dynamic.pop_front();
            }
            if(obj2NextPoint == obj2Queue.front())
            {
                obj2Queue.pop_front();
            }
            else 
            {
                obj2Dynamic.pop_front();
            }
            object = 3;

            if(obj1Queue.empty() && obj1Dynamic.empty()) 
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

             if(obj2Queue.empty() && obj2Dynamic.empty()) 
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
            
            return obj1NextPoint;
        }
    }