#include "SimplePoint2D.h"
#include <vector>
#include <queue>

class ParallelObjT 
{
    std::queue obj1Queue;
    std::queue obj2Queue;
    std::queue obj1Dynamic;
    std::queue obj2Dynamic;

    std::vector<int> SelectNext();

    public:
    int object = 0; //1 = object 1, 2 = object 2, 3 = both objects
    int status = 0; // 0 = end of none, 1 = end of first, 2 = end of second, 3 = end of both
    ParallelObjT(std::vector obj1, std::vector obj2);
}