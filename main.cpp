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

    // point-point meets: N/A
    /*
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

    // point-point covered by: N/A

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

    // point-point covers: N/A

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
    */
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
    /*
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
    */
    vector<Segment2D> outer_square;
    outer_square.push_back(left_long);
    outer_square.push_back(top_long);
    outer_square.push_back(right_long);
    outer_square.push_back(bottom_long);
    Region2D outer_square_region = Region2D(outer_square);

    Segment2D left_short_lower = left_short;
    Segment2D left_short_upper = Segment2D(mid_left, top_left);
    Segment2D top_short_left = Segment2D(top_left, top_mid);
    Segment2D top_short_right = Segment2D(top_mid, top_right);
    Segment2D right_short_upper = Segment2D(top_right, mid_right);
    Segment2D right_short_lower = Segment2D(mid_right, bottom_right);
    Segment2D bottom_short_right = Segment2D(bottom_mid, bottom_right);
    Segment2D bottom_short_left = Segment2D(bottom_left, bottom_mid);
    Segment2D prime_meridian = Segment2D(bottom_mid, top_mid);
    Segment2D prime_meridian_lower = Segment2D(bottom_mid, mid_mid);
    Segment2D prime_meridian_upper = Segment2D(mid_mid, top_mid);
    Segment2D equator = Segment2D(mid_left, mid_right);
    Segment2D equator_left = Segment2D(mid_left, mid_mid);
    Segment2D equator_right = Segment2D(mid_mid, mid_right);

    vector<Segment2D> lower_left_square;
    lower_left_square.push_back(left_short);
    lower_left_square.push_back(equator_left);
    lower_left_square.push_back(prime_meridian_lower);
    lower_left_square.push_back(bottom_short_left);
    Region2D lower_left_square_region = Region2D(lower_left_square);

    vector<Segment2D> upper_left_square;
    upper_left_square.push_back(equator_left);
    upper_left_square.push_back(top_short_left);
    upper_left_square.push_back(left_short_upper);
    upper_left_square.push_back(prime_meridian_upper);
    Region2D upper_left_square_region = Region2D(upper_left_square);

    vector<Segment2D> upper_right_square;
    upper_right_square.push_back(top_short_right);
    upper_right_square.push_back(equator_right);
    upper_right_square.push_back(right_short_upper);
    upper_right_square.push_back(prime_meridian_upper);
    Region2D upper_right_square_region = Region2D(upper_right_square);

    vector<Segment2D> lower_right_square;
    lower_right_square.push_back(equator_right);
    lower_right_square.push_back(bottom_short_right);
    lower_right_square.push_back(right_short_lower);
    lower_right_square.push_back(prime_meridian_lower);
    Region2D lower_right_square_region = Region2D(lower_right_square);

    vector<Segment2D> lower_rectangle;
    lower_rectangle.push_back(bottom_long);
    lower_rectangle.push_back(right_short_lower);
    lower_rectangle.push_back(left_short_lower);
    lower_rectangle.push_back(equator);
    Region2D lower_rectangle_region = Region2D(lower_rectangle);

    vector<Segment2D> upper_rectangle;
    upper_rectangle.push_back(top_long);
    upper_rectangle.push_back(left_short_upper);
    upper_rectangle.push_back(right_short_upper);
    upper_rectangle.push_back(equator);
    Region2D upper_rectangle_region = Region2D(upper_rectangle);

    vector<Segment2D> left_rectangle;
    left_rectangle.push_back(left_long);
    left_rectangle.push_back(bottom_short_left);
    left_rectangle.push_back(top_short_left);
    left_rectangle.push_back(prime_meridian);
    Region2D left_rectangle_region = Region2D(left_rectangle);

    vector<Segment2D> right_rectangle;
    right_rectangle.push_back(right_long);
    right_rectangle.push_back(top_short_right);
    right_rectangle.push_back(bottom_short_right);
    right_rectangle.push_back(prime_meridian);
    Region2D right_rectangle_region = Region2D(right_rectangle);

    Number e = "4.0";
    SimplePoint2D four_four = SimplePoint2D(e, e);
    SimplePoint2D three_four = SimplePoint2D(d, e);
    SimplePoint2D four_three = SimplePoint2D(e, d);

    vector<Segment2D> far_square;
    far_square.push_back(Segment2D(three_four, four_four));
    far_square.push_back(Segment2D(four_three, four_four));
    far_square.push_back(Segment2D(top_right, three_four));
    far_square.push_back(Segment2D(top_right, four_three));
    Region2D far_square_region = Region2D(far_square);

    SimplePoint2D four_zero = SimplePoint2D(e, a);
    SimplePoint2D zero_four = SimplePoint2D(a, e);

    vector<Segment2D> giant_square;
    giant_square.push_back(Segment2D(bottom_left, zero_four));
    giant_square.push_back(Segment2D(bottom_left, four_zero));
    giant_square.push_back(Segment2D(four_four, four_zero));
    giant_square.push_back(Segment2D(four_four, zero_four));
    Region2D giant_square_region = Region2D(giant_square);

    vector<Segment2D> left_overlap_rectangle;
    left_overlap_rectangle.push_back(Segment2D(bottom_left, mid_left));
    left_overlap_rectangle.push_back(Segment2D(mid_left, mid_right));
    left_overlap_rectangle.push_back(Segment2D(mid_right, bottom_right));
    left_overlap_rectangle.push_back(Segment2D(bottom_right, bottom_left));
    Region2D left_overlap_rectangle_region = Region2D(left_overlap_rectangle);

    vector<Segment2D> right_overlap_rectangle;
    right_overlap_rectangle.push_back(Segment2D(bottom_mid, zero_four));
    right_overlap_rectangle.push_back(Segment2D(zero_four, four_zero));
    right_overlap_rectangle.push_back(Segment2D(four_zero, four_four));
    right_overlap_rectangle.push_back(Segment2D(four_four, bottom_mid));
    Region2D right_overlap_rectangle_region = Region2D(right_overlap_rectangle);

    vector<SimplePoint2D> middle_points;
    middle_points.push_back(mid_mid);
    middle_points.push_back(mid_right);
    Point2D middle_point_set = Point2D(middle_points);

    vector<SimplePoint2D> ll_points;
    ll_points.push_back(bottom_left);
    Point2D origin = Point2D(ll_points);

    vector<Segment2D> shorter_left_and_bottom_segs;
    shorter_left_and_bottom_segs.push_back(left_short_lower);
    shorter_left_and_bottom_segs.push_back(bottom_short_left);
    Line2D shorter_left_and_bottom_segments = Line2D(shorter_left_and_bottom_segs);

    // point-region disjoint: 
    if(vp.disjoint(bottom_points, lower_rectangle_region))
        cout << "Point-Region Disjoint Failed Test 1" << endl;
    else
        cout << "Point-Region Disjoint Passed Test 1" << endl;

    if(vp.disjoint(bottom_points, upper_rectangle_region))
        cout << "Point-Region Disjoint Passed Test 2" << endl;
    else
        cout << "Point-Region Disjoint Failed Test 2" << endl;

    if(vp.disjoint(bottom_points, lower_left_square_region))
        cout << "Point-Region Disjoint Passed Test 3" << endl;
    else
        cout << "Point-Region Disjoint Failed Test 3" << endl;
    /*
    // point-region meets:
    if(vp.meet(bottom_points, lower_rectangle_region))
        cout << "Point-Region Meet Passed Test 1" << endl;
    else
        cout << "Point-Region Meet Failed Test 1" << endl;

    if(vp.meet(bottom_points, upper_rectangle_region))
        cout << "Point-Region Meet Failed Test 2" << endl;
    else
        cout << "Point-Region Meet Passed Test 2" << endl;

    if(vp.meet(middle_point_set, giant_square_region))
        cout << "Point-Region Meet Failed Test 3" << endl;
    else
        cout << "Point-Region Meet Passed Test 3" << endl;

    // point-region equal: N/A

    // point-region inside:
    if(vp.inside(bottom_points, lower_rectangle_region))
        cout << "Point-Region Inside Failed Test 1" << endl;
    else
        cout << "Point-Region Inside Passed Test 1" << endl;

    if(vp.inside(bottom_points, upper_rectangle_region))
        cout << "Point-Region Inside Failed Test 2" << endl;
    else
        cout << "Point-Region Inside Passed Test 2" << endl;

    if(vp.inside(middle_point_set, giant_square_region))
        cout << "Point-Region Inside Passed Test 3" << endl;
    else
        cout << "Point-Region Inside Failed Test 3" << endl;

    // point-region covered by: N/A

    // point-region contains: N/A

    // point-region covers: N/A
    
    // point-region overlaps:
    if(vp.overlap(bottom_points, lower_rectangle_region))
        cout << "Point-Region Overlap Failed Test 1" << endl;
    else
        cout << "Point-Region Overlap Passed Test 1" << endl;

    if(vp.overlap(bottom_points, upper_rectangle_region))
        cout << "Point-Region Overlap Failed Test 2" << endl;
    else
        cout << "Point-Region Overlap Passed Test 2" << endl;

    if(vp.overlap(bottom_points, lower_right_square_region))
        cout << "Point-Region Overlap Passed Test 3" << endl;
    else
        cout << "Point-Region Overlap Failed Test 3" << endl;
    */

    // line-line disjoint: 
    if(vp.disjoint(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Disjoint Failed Test 1" << endl;
    else
        cout << "Line-Line Disjoint Passed Test 1" << endl;

    if(vp.disjoint(left_and_bottom_segments, top_and_right_segments))
        cout << "Line-Line Disjoint Passed Test 2" << endl;
    else
        cout << "Line-Line Disjoint Failed Test 2" << endl;

    if(vp.disjoint(left_and_bottom_segments, short_left_and_bottom_segments))
        cout << "Line-Line Disjoint Passed Test 3" << endl;
    else
        cout << "Line-Line Disjoint Failed Test 3" << endl;
    /*
    // line-line meets:
    if(vp.meet(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Meet Failed Test 1" << endl;
    else
        cout << "Line-Line Meet Passed Test 1" << endl;

    if(vp.meet(left_and_bottom_segments, top_and_right_segments))
        cout << "Line-Line Meet Passed Test 2" << endl;
    else
        cout << "Line-Line Meet Failed Test 2" << endl;

    if(vp.meet(left_and_bottom_segments, short_left_and_bottom_segments))
        cout << "Line-Line Meet Failed Test 3" << endl;
    else
        cout << "Line-Line Meet Passed Test 3" << endl;

    // line-line equal:
    if(vp.equal(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Equal Passed Test 1" << endl;
    else
        cout << "Line-Line Equal Failed Test 1" << endl;

    if(vp.equal(left_and_bottom_segments, top_and_right_segments))
        cout << "Line-Line Equal Failed Test 2" << endl;
    else
        cout << "Line-Line Equal Passed Test 2" << endl;

    if(vp.equal(left_and_bottom_segments, short_left_and_bottom_segments))
        cout << "Line-Line Equal Failed Test 3" << endl;
    else
        cout << "Line-Line Equal Passed Test 3" << endl;

    // line-line inside:
    if(vp.inside(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Inside Failed Test 1" << endl;
    else
        cout << "Line-Line Inside Passed Test 1" << endl;

    if(vp.inside(shorter_left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Inside Passed Test 2" << endl;
    else
        cout << "Line-Line Inside Failed Test 2" << endl;

    if(vp.inside(left_and_bottom_segments, shorter_left_and_bottom_segments))
        cout << "Line-Line Inside Failed Test 3" << endl;
    else
        cout << "Line-Line Inside Passed Test 3" << endl;

    // line-line covered by:
    if(vp.covered_by(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Covered By Failed Test 1" << endl;
    else
        cout << "Line-Line Covered By Passed Test 1" << endl;

    if(vp.covered_by(shorter_left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Covered By Failed Test 2" << endl;
    else
        cout << "Line-Line Covered By Passed Test 2" << endl;

    if(vp.covered_by(short_left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Covered By Passed Test 3" << endl;
    else
        cout << "Line-Line Covered By Failed Test 3" << endl;

    // line-line contains:
    if(vp.contains(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Contains Failed Test 1" << endl;
    else
        cout << "Line-Line Contains Passed Test 1" << endl;

    if(vp.contains(shorter_left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Contains Failed Test 2" << endl;
    else
        cout << "Line-Line Contains Passed Test 2" << endl;

    if(vp.contains(left_and_bottom_segments, shorter_left_and_bottom_segments))
        cout << "Line-Line Contains Passed Test 3" << endl;
    else
        cout << "Line-Line Contains Failed Test 3" << endl;

    // line-line covers:
    if(vp.covers(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Covers Failed Test 1" << endl;
    else
        cout << "Line-Line Covers Passed Test 1" << endl;

    if(vp.covers(left_and_bottom_segments, shorter_left_and_bottom_segments))
        cout << "Line-Line Covers Failed Test 2" << endl;
    else
        cout << "Line-Line Covers Passed Test 2" << endl;

    if(vp.covers(left_and_bottom_segments, short_left_and_bottom_segments))
        cout << "Line-Line Covers Passed Test 3" << endl;
    else
        cout << "Line-Line Covers Failed Test 3" << endl;

    // line-line overlaps:
    if(vp.overlap(left_and_bottom_segments, left_and_bottom_segments))
        cout << "Line-Line Overlap Failed Test 1" << endl;
    else
        cout << "Line-Line Overlap Passed Test 1" << endl;

    if(vp.overlap(left_and_bottom_segments, shorter_left_and_bottom_segments))
        cout << "Line-Line Overlap Failed Test 2" << endl;
    else
        cout << "Line-Line Overlap Passed Test 2" << endl;

    if(vp.overlap(left_and_top_segments, top_and_right_segments))
        cout << "Line-Line Overlap Passed Test 3" << endl;
    else
        cout << "Line-Line Overlap Failed Test 3" << endl;
    */

    // line-region disjoint: 
    if(vp.disjoint(short_left_and_bottom_segments, lower_rectangle_region))
        cout << "Line-Region Disjoint Failed Test 1" << endl;
    else
        cout << "Line-Region Disjoint Passed Test 1" << endl;

    if(vp.disjoint(right_segments, upper_rectangle_region))
        cout << "Line-Region Disjoint Passed Test 2" << endl;
    else
        cout << "Line-Region Disjoint Failed Test 2" << endl;

    if(vp.disjoint(right_segments, lower_left_square_region))
        cout << "Line-Region Disjoint Passed Test 3" << endl;
    else
        cout << "Line-Region Disjoint Failed Test 3" << endl;

    // line-region meets:

    // line-region equal: N/A

    // line-region inside:

    // line-region covered by:

    // line-region contains: N/A

    // line-region covers: N/A

    // line-region overlaps:


    // region-region disjoint: 
    if(vp.disjoint(lower_rectangle_region, lower_rectangle_region))
        cout << "Region-Region Disjoint Failed Test 1" << endl;
    else
        cout << "Region-Region Disjoint Passed Test 1" << endl;

    if(vp.disjoint(lower_rectangle_region, upper_rectangle_region))
        cout << "Region-Region Disjoint Passed Test 2" << endl;
    else
        cout << "Region-Region Disjoint Failed Test 2" << endl;

    if(vp.disjoint(lower_left_square_region, far_square_region))
        cout << "Region-Region Disjoint Passed Test 3" << endl;
    else
        cout << "Region-Region Disjoint Failed Test 3" << endl;
    /*
    // region-region meets:
    if(vp.meet(upper_left_square_region, upper_rectangle_region))
        cout << "Region-Region Meet Failed Test 1" << endl;
    else
        cout << "Region-Region Meet Passed Test 1" << endl;

    if(vp.meet(lower_left_square_region, upper_right_square_region))
        cout << "Region-Region Meet Passed Test 2" << endl;
    else
        cout << "Region-Region Meet Failed Test 2" << endl;

    if(vp.meet(lower_left_square_region, far_square_region))
        cout << "Region-Region Meet Failed Test 3" << endl;
    else
        cout << "Region-Region Meet Passed Test 3" << endl;

    // region-region equal:
    if(vp.equal(upper_left_square_region, upper_rectangle_region))
        cout << "Region-Region Equal Failed Test 1" << endl;
    else
        cout << "Region-Region Equal Passed Test 1" << endl;

    if(vp.equal(lower_left_square_region, lower_left_square_region))
        cout << "Region-Region Equal Passed Test 2" << endl;
    else
        cout << "Region-Region Equal Failed Test 2" << endl;

    if(vp.equal(lower_left_square_region, far_square_region))
        cout << "Region-Region Equal Failed Test 3" << endl;
    else
        cout << "Region-Region Equal Passed Test 3" << endl;

    // region-region inside:
    if(vp.inside(upper_left_square_region, upper_rectangle_region))
        cout << "Region-Region Inside Failed Test 1" << endl;
    else
        cout << "Region-Region Inside Passed Test 1" << endl;

    if(vp.inside(upper_left_square_region, giant_square_region))
        cout << "Region-Region Inside Passed Test 2" << endl;
    else
        cout << "Region-Region Inside Failed Test 2" << endl;

    if(vp.inside(lower_left_square_region, far_square_region))
        cout << "Region-Region Inside Failed Test 3" << endl;
    else
        cout << "Region-Region Inside Passed Test 3" << endl;

    // region-region covered by:
    if(vp.covered_by(upper_left_square_region, upper_rectangle_region))
        cout << "Region-Region Covered By Passed Test 1" << endl;
    else
        cout << "Region-Region Covered By Failed Test 1" << endl;

    if(vp.covered_by(upper_left_square_region, giant_square_region))
        cout << "Region-Region Covered By Failed Test 2" << endl;
    else
        cout << "Region-Region Covered By Passed Test 2" << endl;

    if(vp.covered_by(lower_left_square_region, far_square_region))
        cout << "Region-Region Covered By Failed Test 3" << endl;
    else
        cout << "Region-Region Covered By Passed Test 3" << endl;

    // region-region contains:
    if(vp.contains(upper_left_square_region, upper_rectangle_region))
        cout << "Region-Region Contains Failed Test 1" << endl;
    else
        cout << "Region-Region Contains Passed Test 1" << endl;

    if(vp.contains(giant_square_region, upper_left_square_region))
        cout << "Region-Region Contains Passed Test 2" << endl;
    else
        cout << "Region-Region Contains Failed Test 2" << endl;

    if(vp.contains(lower_left_square_region, far_square_region))
        cout << "Region-Region Contains Failed Test 3" << endl;
    else
        cout << "Region-Region Contains Passed Test 3" << endl;

    if(vp.contains(upper_rectangle_region, upper_left_square_region))
        cout << "Region-Region Contains Failed Test 4" << endl;
    else
        cout << "Region-Region Contains Passed Test 4" << endl;

    // region-region covers:
    if(vp.covers(upper_rectangle_region, upper_left_square_region))
        cout << "Region-Region Covers Passed Test 1" << endl;
    else
        cout << "Region-Region Covers Failed Test 1" << endl;

    if(vp.covers(upper_left_square_region, giant_square_region))
        cout << "Region-Region Covers Failed Test 2" << endl;
    else
        cout << "Region-Region Covers Passed Test 2" << endl;

    if(vp.covers(lower_left_square_region, far_square_region))
        cout << "Region-Region Covers Failed Test 3" << endl;
    else
        cout << "Region-Region Covers Passed Test 3" << endl;

    if(vp.covers(giant_square_region, upper_left_square_region))
        cout << "Region-Region Covers Failed Test 4" << endl;
    else
        cout << "Region-Region Covers Passed Test 4" << endl;

    // region-region overlaps:
    if(vp.overlap(upper_left_square_region, upper_rectangle_region))
        cout << "Region-Region Overlap Failed Test 1" << endl;
    else
        cout << "Region-Region Overlap Passed Test 1" << endl;

    if(vp.overlap(lower_left_square_region, far_square_region))
        cout << "Region-Region Overlap Failed Test 2" << endl;
    else
        cout << "Region-Region Overlap Passed Test 2" << endl;

    if(vp.overlap(left_overlap_rectangle_region, right_overlap_rectangle_region))
        cout << "Region-Region Overlap Passed Test 3" << endl;
    else
        cout << "Region-Region Overlap Failed Test 3" << endl;
    */
    return 0;
}
