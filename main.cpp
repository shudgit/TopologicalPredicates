#include "Number.h"
#include <iostream>
#include "SimplePoint2D.h"
#include "Segment2D.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "Line2D.h"
#include "Point2D.h"
#include "Region2D.h"

using namespace std;

int main ()
{
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
    cout << (*itr).hs.s.leftEndPoint.x << " " << (*itr).hs.s.leftEndPoint.y << " " << (*itr).hs.s.rightEndPoint.x << " " << (*itr).hs.s.rightEndPoint.y << endl;
    itr++;
    cout << (*itr).hs.s.leftEndPoint.x << " " << (*itr).hs.s.leftEndPoint.y << " " << (*itr).hs.s.rightEndPoint.x << " " << (*itr).hs.s.rightEndPoint.y << endl;
    return 0;
}
