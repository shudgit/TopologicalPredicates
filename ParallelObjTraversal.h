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
    int elementOf;
    int endOf;
    ParallelObjT(std::vector obj1, std::vector obj2);
}