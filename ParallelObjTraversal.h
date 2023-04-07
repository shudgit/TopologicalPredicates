#include "SimplePoint2D.h"
#include <vector>
#include <queue>

class ParallelObjT 
{
    std::queue<SimplePoint2D> obj1Queue;
    std::queue<SimplePoint2D> obj2Queue;
    std::queue<SimplePoint2D> obj1Dynamic;
    std::queue<SimplePoint2D> obj2Dynamic;

    public:
    int object = 0; //1 = object 1, 2 = object 2, 3 = both objects
    int status = 0; // 0 = end of none, 1 = end of first, 2 = end of second, 3 = end of both
    ParallelObjT(std::vector<SimplePoint2D> obj1, std::vector<SimplePoint2D> obj2);
    SimplePoint2D SelectNext();
}