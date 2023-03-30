#include "Segment2D.h"
#include "SimplePoint2D.h"
#include <vector>

class PlaneSweep {
    protected:
        SimplePoint2D currentEventPoint;
        std::vector<Segment2D> sweepStatus;
    public:
        PlaneSweep();
        SimplePoint2D get_event();
        //bool look_ahead();
        void add_left(SimplePoint2D dp, Segment2D segment);    
        void del_right(SimplePoint2D dp, Segment2D segment);   
        //bool get_attr();
        //void set_attr();  
        //bool get_pred_attr(); 
        bool pred_exists();
        Segment2D pred_of_p();
        //bool poi_on_seg();  
};
