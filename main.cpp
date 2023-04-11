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

    vector<SimplePoint2D> bottomPoints;
    bottomPoints.push_back(bottom_left);
    bottomPoints.push_back(bottom_mid);
    bottomPoints.push_back(bottom_right);
    Point2D bottom_points = Point2D(bottomPoints);

    bottomPoints.push_back(mid_left);
    bottomPoints.push_back(mid_mid);
    bottomPoints.push_back(mid_right);
    Point2D bottom_and_mid_points = Point2D(bottomPoints);

    vector<SimplePoint2D> topPoints;
    topPoints.push_back(top_left);
    topPoints.push_back(top_mid);
    topPoints.push_back(top_right);
    Point2D top_points = Point2D(topPoints);

    topPoints.push_back(mid_left);
    topPoints.push_back(mid_mid);
    topPoints.push_back(mid_right);
    Point2D top_and_mid_points = Point2D(topPoints);

    // point-point disjoint: 
    if(vp.disjoint(bottom_points, top_points))
        cout << "Point-Point Disjoint Passed Test 1" << endl;
    else
        cout << "Point-Point Disjoint Failed Test 1" << endl;

    if(vp.disjoint(bottom_points, bottom_points))
        cout << "Point-Point Disjoint Failed Test 2" << endl;
    else
        cout << "Point-Point Disjoint Passed Test 2" << endl;

    if(vp.disjoint(bottom_and_mid_points, bottom_points))
        cout << "Point-Point Disjoint Failed Test 2" << endl;
    else
        cout << "Point-Point Disjoint Passed Test 2" << endl;

    // point-point meets: points have no boundary

    // point-point equal:
    if(vp.equal(bottom_points, bottom_points))
        cout << "Point-Point Equal Passed Test 1" << endl;
    else
        cout << "Point-Point Equal Failed Test 1" << endl;

    if(vp.equal(bottom_points, top_points))
        cout << "Point-Point Equal Failed Test 2" << endl;
    else
        cout << "Point-Point Equal Passed Test 2" << endl;

    if(vp.equal(bottom_and_mid_points, bottom_points))
        cout << "Point-Point Equal Failed Test 3" << endl;
    else
        cout << "Point-Point Equal Passed Test 3" << endl;

    // point-point inside:
    if(vp.inside(bottom_points, bottom_and_mid_points))
        cout << "Point-Point Inside Passed Test 1" << endl;
    else
        cout << "Point-Point Inside Failed Test 1" << endl;

    if(vp.inside(bottom_points, top_points))
        cout << "Point-Point Inside Failed Test 2" << endl;
    else
        cout << "Point-Point Inside Passed Test 2" << endl;

    if(vp.inside(bottom_and_mid_points, bottom_points))
        cout << "Point-Point Inside Failed Test 3" << endl;
    else
        cout << "Point-Point Inside Passed Test 3" << endl;

    // point-point covered by: points have no boundary

    // point-point contains:
    if(vp.contains(bottom_points, bottom_and_mid_points))
        cout << "Point-Point Contains Failed Test 1" << endl;
    else
        cout << "Point-Point Contains Passed Test 1" << endl;

    if(vp.contains(bottom_points, top_points))
        cout << "Point-Point Contains Failed Test 2" << endl;
    else
        cout << "Point-Point Contains Passed Test 2" << endl;

    if(vp.contains(bottom_and_mid_points, bottom_points))
        cout << "Point-Point Contains Passed Test 3" << endl;
    else
        cout << "Point-Point Contains Failed Test 3" << endl;

    // point-point covers: points have no boundary

    // point-point overlaps:
    if(vp.overlap(bottom_points, bottom_and_mid_points))
        cout << "Point-Point Overlap Passed Test 1" << endl;
    else
        cout << "Point-Point Overlap Failed Test 1" << endl;

    if(vp.overlap(bottom_points, top_points))
        cout << "Point-Point Overlap Failed Test 2" << endl;
    else
        cout << "Point-Point Overlap Passed Test 2" << endl;

    if(vp.overlap(bottom_and_mid_points, bottom_points))
        cout << "Point-Point Overlap Passed Test 3" << endl;
    else
        cout << "Point-Point Overlap Failed Test 3" << endl;
    
    Segment2D left_long = Segment2D(bottom_left, top_left);
    Segment2D left_short = Segment2D(bottom_left, mid_left);
    Segment2D top_long = Segment2D(top_left, top_right);
    Segment2D right_long = Segment2D(top_right, bottom_right);
    Segment2D bottom_long = Segment2D(bottom_left, bottom_right);

    vector<Segment2D> left_and_bottom_segs;
    left_and_bottom_segs.push_back(left_long);
    left_and_bottom_segs.push_back(bottom_long);
    Line2D left_and_bottom_segments = Line2D(left_and_bottom_segs);

    vector<Segment2D> short_left_and_bottom_segs;
    short_left_and_bottom_segs.push_back(left_short);
    short_left_and_bottom_segs.push_back(bottom_long);
    Line2D short_left_and_bottom_segments = Line2D(short_left_and_bottom_segs);

    vector<Segment2D> left_and_top_segs;
    left_and_top_segs.push_back(left_short);
    left_and_top_segs.push_back(bottom_long);
    Line2D left_and_top_segments = Line2D(left_and_top_segs);

    vector<Segment2D> top_and_right_segs;
    top_and_right_segs.push_back(top_long);
    top_and_right_segs.push_back(right_long);
    Line2D top_and_right_segments = Line2D(top_and_right_segs);

    vector<Segment2D> right_segs;
    right_segs.push_back(right_long);
    Line2D right_segments = Line2D(right_segs);

    // point-line disjoint: 
    if(vp.disjoint(bottom_points, top_and_right_segments))
        cout << "Point-Line Disjoint Passed Test 1" << endl;
    else
        cout << "Point-Line Disjoint Failed Test 1" << endl;

    if(vp.disjoint(bottom_points, left_and_bottom_segments))
        cout << "Point-Line Disjoint Failed Test 2" << endl;
    else
        cout << "Point-Line Disjoint Passed Test 2" << endl;

    if(vp.disjoint(bottom_points, right_segments))
        cout << "Point-Line Disjoint Passed Test 3" << endl;
    else
        cout << "Point-Line Disjoint Failed Test 3" << endl;

    // point-line meets:
    

    // point-line equal: N/A

    // point-line inside:
    if(vp.inside(bottom_points, top_and_right_segments))
        cout << "Point-Line Inside Failed Test 1" << endl;
    else
        cout << "Point-Line Inside Passed Test 1" << endl;

    if(vp.inside(bottom_points, left_and_bottom_segments))
        cout << "Point-Line Inside Passed Test 2" << endl;
    else
        cout << "Point-Line Inside Failed Test 2" << endl;

    if(vp.inside(bottom_points, right_segments))
        cout << "Point-Line Inside Failed Test 3" << endl;
    else
        cout << "Point-Line Inside Passed Test 3" << endl;

    // point-line covered by: N/A

    // point-line contains: N/A

    // point-line covers: N/A
    
    // point-line overlaps:



    // point-region disjoint: 

    // point-region meets:

    // point-region equal:

    // point-region inside:

    // point-region covered by:

    // point-region contains:

    // point-region covers:
    
    // point-region overlaps:


    // line-line disjoint: 

    // line-line meets:

    // line-line equal:

    // line-line inside:

    // line-line covered by:

    // line-line contains:

    // line-line covers:
    
    // line-line overlaps:


    // line-region disjoint: 

    // line-region meets:

    // line-region equal:

    // line-region inside:

    // line-region covered by:

    // line-region contains:

    // line-region covers:

    // line-region overlaps:


    // region-region disjoint: 

    // region-region meets:

    // region-region equal:

    // region-region inside:

    // region-region covered by:

    // region-region contains:

    // region-region covers:
    
    // region-region overlaps:

    return 0;
}
