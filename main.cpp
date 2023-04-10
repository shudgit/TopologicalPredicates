#include "Number.h"
#include <iostream>
#include "SimplePoint2D.h"
#include "Segment2D.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "Line2D.h"
#include "Point2D.h"
#include "Region2D.h"
#include "VerifyPredicate.h"

using namespace std;

int main ()
{
    // iterator testing
    /*
    Number a = "0.0";
    Number b = "1.0";
    Number c = "2.0";
    SimplePoint2D left = SimplePoint2D(a, a);
    SimplePoint2D top = SimplePoint2D(b, b);
    SimplePoint2D right = SimplePoint2D(c, a);
    vector<SimplePoint2D> ps;
    ps.push_back(left);
    ps.push_back(top);
    ps.push_back(right);
    Point2D points = Point2D(ps);
    Point2D::Iterator itrp = points.begin();
    cout << (*itrp).x << " " << (*itrp).y << endl;
    itrp++;
    cout << (*itrp).x << " " << (*itrp).y << endl;
    Segment2D l = Segment2D(left, top);
    Segment2D r = Segment2D(top, right);
    Segment2D u = Segment2D(left, right);
    HalfSegment2D hs = HalfSegment2D(l, true);
    AttributedHalfSegment2D ahs = AttributedHalfSegment2D(hs, true);
    cout << ahs.hs.s.leftEndPoint.x << endl;
    vector<Segment2D> segs;
    segs.push_back(l);
    segs.push_back(r);
    segs.push_back(u);
    Region2D reg = Region2D(segs);
    cout << "constructor worked" << endl;
    Region2D::iterator itr = reg.begin();
    
    //cout << (*itr).hs.s.leftEndPoint.x << " " << (*itr).hs.s.leftEndPoint.y << " " << (*itr).hs.s.rightEndPoint.x << " " << (*itr).hs.s.rightEndPoint.y << endl;
    while(itr != reg.end())
    {
        cout << (*itr).hs.s.leftEndPoint.x << " " << (*itr).hs.s.leftEndPoint.y << " " << (*itr).hs.s.rightEndPoint.x << " " << (*itr).hs.s.rightEndPoint.y << " above flag: " << (*itr).above << endl;
        itr++;
    }
    */

    VerifyPredicate vp;

    Number a = "0.0";
    Number b = "1.0";
    Number c = "2.0";
    Number d = "3.0";

    SimplePoint2D bottom_left = SimplePoint2D(a, a);
    SimplePoint2D bottom_mid = SimplePoint2D(b, a);
    SimplePoint2D bottom_right = SimplePoint2D(c, a);

    SimplePoint2D mid_left = SimplePoint2D(a, b);
    SimplePoint2D mid_mid = SimplePoint2D(b, b);
    SimplePoint2D mid_right = SimplePoint2D(c, b);

    SimplePoint2D top_left = SimplePoint2D(a, c);
    SimplePoint2D top_mid = SimplePoint2D(b, c);
    SimplePoint2D top_right = SimplePoint2D(c, c);

    // disjoint: 
    vector<SimplePoint2D> bottomPoints;
    bottomPoints.push_back(bottom_left);
    bottomPoints.push_back(bottom_mid);
    bottomPoints.push_back(bottom_right);
    Point2D bottom = Point2D(bottomPoints);

    vector<SimplePoint2D> topPoints;
    topPoints.push_back(top_left);
    topPoints.push_back(top_mid);
    topPoints.push_back(top_right);
    Point2D top = Point2D(topPoints);

    if(vp.disjoint(bottom, top))
        cout << "Point Disjoint Passed Test" << endl;
    else
        cout << "Point Disjoint Failed Test" << endl;
        
    return 0;
}
