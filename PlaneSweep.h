#include "Segment2D.h"
#include "SimplePoint2D.h"
#include <vector>
#include <queue>

class PlaneSweep {
    protected:
        SimplePoint2D currentEventPoint;
        std::vector<Segment2D> sweepStatus;
        //possibly keep sweep queues here and implement parallel traversal here
        //std::queue<SimplePoint2D> 
    public:
        PlaneSweep();
        SimplePoint2D get_event();
        //bool look_ahead();
        void add_left(Segment2D segment);    
        void del_right(Segment2D segment);   
        //bool get_attr();
        //void set_attr();  
        //bool get_pred_attr(); 
        bool pred_exists(Segment2D segment);
        Segment2D pred_of_p(Segment2D segment);
        //bool poi_on_seg();  
};
