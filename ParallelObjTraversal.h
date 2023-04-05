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
    int object = 0;
    int status = 0;
    ParallelObjT(std::vector obj1, std::vector obj2);
}