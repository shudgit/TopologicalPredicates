#include "Segment2D.h"
#include "SimplePoint2D.h"
#include <vector>
#include <queue>
#include <map>

class PlaneSweep {
    protected:
        SimplePoint2D currentEventPoint;
        std::vector<Segment2D> sweepStatus;
        std::map<Segment2D, bool> attributes;
    public:
        PlaneSweep();
        bool look_ahead(HalfSegment2D half, std::vector<HalfSegment2D> halfSegs);
        void add_left(Segment2D segment);    
        void del_right(Segment2D segment);   
        bool get_attr(Segment2D segment);
        void set_attr(Segment2D segment, bool attr);  
        bool get_pred_attr(SimplePoint2D point); 
        bool pred_exists(Segment2D segment);
        bool pred_of_p_exists(SimplePoint2D point);
        Segment2D pred_of_p(SimplePoint2D point);
        bool poi_on_seg(SimplePoint2D point);  
};
