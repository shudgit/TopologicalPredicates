#include "VerifyPredicate.h"
#include "HalfSegment2D.h"
#include "AttributedHalfSegment2D.h"
#include "SimplePoint2D.h"
#include "EventPoint.h"
#include <vector>
#include <map>
#include <iostream>

    // Douglas
    vector<bool> createRegionRegion9IM(vector<bool> flags)
    {
        vector<bool> im;
        im.resize(9, false);
        im[0] = flags[4] || flags[5] || flags[2] || flags[3] || flags[10] || flags[11];
        im[1] = flags[10] || flags[11];
        im[2] = flags[6] || flags[0] || flags[1] || flags[2] || flags[3];
        im[3] = flags[2] || flags[3];
        im[4] = flags[4] || flags[5] || flags[6] || flags[7];
        im[5] = flags[0] || flags[1];
        im[6] = flags[6] || flags[2] || flags[3] || flags[0] || flags[1];
        im[7] = flags[8] || flags[9];
        im[8] = true;
        return im;
    }
    //cody
    vector<bool> createLineLine9IM(vector<bool> flags)
    {
        vector<bool> im;
        im.resize(9, false);
        im[0] = flags[0] || flags[1];
        im[1] = flags[7];
        im[2] = flags[2];
        im[3] = flags[3];
        im[4] = flags[4];
        im[5] = flags[5];
        im[6] = flags[6];
        im[7] = flags[8];
        im[8] = true;
        
        return im;
    }

    // Sam and Douglas
    VerifyPredicate::VerifyPredicate()
    {
        predicates.insert(std::pair<int, vector<bool>>(1, {false, false, true, false, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(2, {false, false, true, false, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(3, {false, false, true, false, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(4, {false, false, true, false, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(5, {false, false, true, false, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(6, {false, false, true, false, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(7, {false, false, true, false, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(8, {false, false, true, false, true, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(9, {false, false, true, true, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(10, {false, false, true, true, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(11, {false, false, true, true, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(12, {false, false, true, true, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(13, {false, false, true, true, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(14, {false, false, true, true, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(15, {false, false, true, true, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(16, {false, false, true, true, true, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(17, {false, true, true, false, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(18, {false, true, true, false, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(19, {false, true, true, false, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(20, {false, true, true, false, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(21, {false, true, true, false, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(22, {false, true, true, false, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(23, {false, true, true, false, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(24, {false, true, true, false, true, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(25, {false, true, true, true, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(26, {false, true, true, true, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(27, {false, true, true, true, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(28, {false, true, true, true, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(29, {false, true, true, true, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(30, {false, true, true, true, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(31, {false, true, true, true, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(32, {false, true, true, true, true, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(33, {true, false, false, false, false, false, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(34, {true, false, false, false, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(35, {true, false, false, false, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(36, {true, false, false, false, true, false, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(37, {true, false, false, false, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(38, {true, false, false, false, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(39, {true, false, false, true, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(40, {true, false, false, true, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(41, {true, false, false, true, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(42, {true, false, false, true, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(43, {true, false, true, false, false, false, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(44, {true, false, true, false, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(45, {true, false, true, false, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(46, {true, false, true, false, false, true, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(47, {true, false, true, false, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(48, {true, false, true, false, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(49, {true, false, true, false, true, false, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(50, {true, false, true, false, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(51, {true, false, true, false, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(52, {true, false, true, false, true, true, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(53, {true, false, true, false, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(54, {true, false, true, false, true, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(55, {true, false, true, true, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(56, {true, false, true, true, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(57, {true, false, true, true, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(58, {true, false, true, true, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(59, {true, false, true, true, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(60, {true, false, true, true, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(61, {true, false, true, true, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(62, {true, false, true, true, true, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(63, {true, true, true, false, false, false, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(64, {true, true, true, false, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(65, {true, true, true, false, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(66, {true, true, true, false, false, true, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(67, {true, true, true, false, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(68, {true, true, true, false, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(69, {true, true, true, false, true, false, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(70, {true, true, true, false, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(71, {true, true, true, false, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(72, {true, true, true, false, true, true, false, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(73, {true, true, true, false, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(74, {true, true, true, false, true, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(75, {true, true, true, true, false, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(76, {true, true, true, true, false, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(77, {true, true, true, true, false, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(78, {true, true, true, true, false, true, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(79, {true, true, true, true, true, false, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(80, {true, true, true, true, true, false, true, true, true}));
        predicates.insert(std::pair<int, vector<bool>>(81, {true, true, true, true, true, true, true, false, true}));
        predicates.insert(std::pair<int, vector<bool>>(82, {true, true, true, true, true, true, true, true, true}));

        lineRegionPredicates.insert(std::pair<int, vector<bool>>(1, {false, false, true, false, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(2, {false, false, true, false, false, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(3, {false, false, true, false, true, false, false, false, false}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(4, {false, false, true, false, true, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(5, {false, true, false, false, false, false, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(6, {false, true, false, false, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(7, {false, true, false, false, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(8, {false, true, true, false, false, false, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(9, {false, true, true, false, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(10, {false, true, true, false, false, true, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(11, {false, true, true, false, false, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(12, {false, true, true, false, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(13, {false, true, true, false, true, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(14, {true, false, false, false, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(15, {true, false, false, false, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(16, {true, false, false, true, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(17, {true, false, false, true, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(18, {true, false, true, false, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(19, {true, false, true, false, false, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(20, {true, false, true, false, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(21, {true, false, true, false, true, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(22, {true, false, true, true, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(23, {true, false, true, true, false, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(24, {true, false, true, true, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(25, {true, false, true, true, true, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(26, {true, true, false, false, false, false, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(27, {true, true, false, false, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(28, {true, true, false, false, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(29, {true, true, false, true, false, false, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(30, {true, true, false, true, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(31, {true, true, false, true, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(32, {true, true, true, false, false, false, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(33, {true, true, true, false, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(34, {true, true, true, false, false, true, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(35, {true, true, true, false, false, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(36, {true, true, true, false, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(37, {true, true, true, false, true, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(38, {true, true, true, true, false, false, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(39, {true, true, true, true, false, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(40, {true, true, true, true, false, true, true, false, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(41, {true, true, true, true, false, true, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(42, {true, true, true, true, true, false, true, true, true}));
        lineRegionPredicates.insert(std::pair<int, vector<bool>>(43, {true, true, true, true, true, true, true, true, true}));
        
        pointLinePredicates.insert(std::pair<int, vector<bool>>(1, {false, false, true, false, false, false, true, false, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(2, {false, false, true, false, false, false, true, true, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(3, {false, true, false, false, false, false, true, false, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(4, {false, true, false, false, false, false, true, true, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(5, {false, true, true, false, false, false, true, false, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(6, {false, true, true, false, false, false, true, true, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(7, {true, false, false, false, false, false, true, false, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(8, {true, false, false, false, false, false, true, true, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(9, {true, false, true, false, false, false, true, false, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(10, {true, false, true, false, false, false, true, true, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(11, {true, true, false, false, false, false, true, false, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(12, {true, true, false, false, false, false, true, true, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(13, {true, true, true, false, false, false, true, false, true}));
        pointLinePredicates.insert(std::pair<int, vector<bool>>(14, {true, true, true, false, false, false, true, true, true}));

        pointRegionPredicates.insert(std::pair<int, vector<bool>>(1, {false, false, true, false, false, false, true, true, true}));
        pointRegionPredicates.insert(std::pair<int, vector<bool>>(2, {false, true, false, false, false, false, true, true, true}));
        pointRegionPredicates.insert(std::pair<int, vector<bool>>(3, {false, true, true, false, false, false, true, true, true}));
        pointRegionPredicates.insert(std::pair<int, vector<bool>>(4, {true, false, false, false, false, false, true, true, true}));
        pointRegionPredicates.insert(std::pair<int, vector<bool>>(5, {true, false, true, false, false, false, true, true, true}));
        pointRegionPredicates.insert(std::pair<int, vector<bool>>(6, {true, true, false, false, false, false, true, true, true}));
        pointRegionPredicates.insert(std::pair<int, vector<bool>>(7, {true, true, true, false, false, false, true, true, true}));

    }

    // Douglas
    bool VerifyPredicate::disjoint(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[0])
            return false;
        return true;
    }

    // Sam
    bool VerifyPredicate::disjoint(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (!(flags[1] && flags[2]))
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::disjoint(Point2D obj1, Region2D obj2)
    {
        vector<bool> flags = PointRegionAlgorithm(obj1, obj2);
        if(flags[2] && !(flags[0] && flags[1]))
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::disjoint(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        for(int i = 1; i < 5; i++) {
            if(flags == predicates[i])
                return true;
        }
        return false;
    }

    // Sam
    bool VerifyPredicate::disjoint(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if (!(flags[0] && (flags[1] || flags[3]) && flags[4] && flags[5]))
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::disjoint(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[1])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::meet(Point2D obj1, Point2D obj2)
    {
        return false;
    }

    // Sam
    bool VerifyPredicate::meet(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (!flags[1] && flags[2])
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::meet(Point2D obj1, Region2D obj2)
    {
        vector<bool> flags = PointRegionAlgorithm(obj1, obj2);
        if(flags[1] && !(flags[0] && flags[2]))
            return true;
        return false;

    }
    //cody
    bool VerifyPredicate::meet(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        for (int i = 5; i < 33; i++) {
            if(flags == predicates[i]) {
                return true;
            }
        }
        return false;
    }

    // Sam
    bool VerifyPredicate::meet(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if ((!flags[0] && (flags[1] || flags[3])) || (!flags[0] && flags[4]) || (!flags[0] && flags[5]))
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::meet(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[2] || im == predicates[3] || im == predicates[4])
            return true;
        return false;
    }

    bool VerifyPredicate::equal(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[1] || flags[2])
            return false;
        return true;
    }

    // Sam
    bool VerifyPredicate::equal(Point2D obj1, Line2D obj2)
    {
       return false;
    }
    //cody
    bool VerifyPredicate::equal(Point2D obj1, Region2D obj2)
    {
        return false;
    }
    //cody
    bool VerifyPredicate::equal(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        if(flags == predicates[33] || flags == predicates[36])
            return true;
        return false;
    }

    // Sam
    bool VerifyPredicate::equal(Line2D obj1, Region2D obj2)
    {
        return false;
    }

    // Douglas
    bool VerifyPredicate::equal(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[5])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::inside(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[1])
            return false;
        return true;
    }

    // Sam
    bool VerifyPredicate::inside(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (flags[1] && !flags[0])
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::inside(Point2D obj1, Region2D obj2)
    {
        vector<bool> flags = PointRegionAlgorithm(obj1, obj2);
        if(!flags[0] && flags[1])
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::inside(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        if(flags == predicates[34] || flags == predicates[35] || flags == predicates[39] || flags == predicates[40])
            return true;
        return false;
    }

    // Sam
    bool VerifyPredicate::inside(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if (flags[0] && !flags[2] && !flags[6])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::inside(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[7])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::covered_by(Point2D obj1, Point2D obj2)
    {
        return false;
    }

    // Sam
    bool VerifyPredicate::covered_by(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if ((flags[1] && !flags[0]) || (flags[2] && !flags[0]))
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::covered_by(Point2D obj1, Region2D obj2)
    {
        return false;
    }
    //cody
    bool VerifyPredicate::covered_by(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        if(flags == predicates[37] || flags == predicates[38] || flags == predicates[41] || flags == predicates[42])
            return true;
        return false;
    }

    // Sam
    bool VerifyPredicate::covered_by(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if ((flags[0] && !flags[2] && !flags[6])||((flags[1] || flags[3]) && !flags[2] && !flags[6])||(flags[4] && !flags[2] && !flags[6])||(flags[5] && !flags[2] && !flags[6]))
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::covered_by(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[6] || im == predicates[8] || im == predicates[9])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::contains(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[2])
            return false;
        return true;
    }

    // Sam
    bool VerifyPredicate::contains(Point2D obj1, Line2D obj2)
    {
        return false;
    }
    //cody
    bool VerifyPredicate::contains(Point2D obj1, Region2D obj2)
    {
        return false;
    }
    //cody
    bool VerifyPredicate::contains(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        if(flags == predicates[43] || flags == predicates[46] || flags == predicates[63] || flags == predicates[66])
            return true;
        return false;
    }

    // Sam
    bool VerifyPredicate::contains(Line2D obj1, Region2D obj2)
    {
        return false;
    }

    // Douglas
    bool VerifyPredicate::contains(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[19])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::covers(Point2D obj1, Point2D obj2)
    {
        return false;
    }

    // Sam
    bool VerifyPredicate::covers(Point2D obj1, Line2D obj2)
    {
        return false;
    }
    //cody
    bool VerifyPredicate::covers(Point2D obj1, Region2D obj2)
    {
        return false;
    }
    //cody
    bool VerifyPredicate::covers(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        if(flags == predicates[49] || flags == predicates[52] || flags == predicates[69] || flags == predicates[72])
            return true;
        return false;
    }

    // Sam
    bool VerifyPredicate::covers(Line2D obj1, Region2D obj2)
    {
        return false;
    }

    // Douglas
    bool VerifyPredicate::covers(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[11] || im == predicates[21] || im == predicates[24])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::overlap(Point2D obj1, Point2D obj2)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if(flags[0] && flags[1] && flags[2])
            return true;
        return false;
    }

    // Sam
    bool VerifyPredicate::overlap(Point2D obj1, Line2D obj2)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (flags[1] && flags[0])
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::overlap(Point2D obj1, Region2D obj2)
    {
        vector<bool> flags = PointRegionAlgorithm(obj1, obj2);
        if(flags[0] && flags[2])
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::overlap(Line2D obj1, Line2D obj2)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        if(flags == predicates[44] || flags == predicates[45] || flags == predicates[47] || flags == predicates[48] || flags == predicates[50] || flags == predicates[51]
         || flags == predicates[53] || flags == predicates[54] || flags == predicates[55] || flags == predicates[56] || flags == predicates[57] || flags == predicates[58]
          || flags == predicates[59] || flags == predicates[60] || flags == predicates[61] || flags == predicates[62] || flags == predicates[64] || flags == predicates[65]
           || flags == predicates[67] || flags == predicates[68] || flags == predicates[70] || flags == predicates[71] || flags == predicates[73] || flags == predicates[74]
            || flags == predicates[75] || flags == predicates[76] || flags == predicates[77] || flags == predicates[78] || flags == predicates[79] || flags == predicates[80]
             || flags == predicates[81] || flags == predicates[82]) 
        {
            return true;
        }
        return false;
    }

    // Sam
    bool VerifyPredicate::overlap(Line2D obj1, Region2D obj2)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if (flags[0] && flags[2])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::overlap(Region2D obj1, Region2D obj2)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if(im == predicates[10] || im == predicates[12] || im == predicates[13] || im == predicates[14] || im == predicates[15] || im == predicates[16] || im == predicates[17] || im == predicates[18] || im == predicates[20] || im == predicates[22] || im == predicates[23] || im == predicates[25] || im == predicates[26] || im == predicates[27] || im == predicates[28] || im == predicates[29] || im == predicates[30] || im == predicates[31] || im == predicates[32] || im == predicates[33])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::verify(Point2D obj1, Point2D obj2, int predicateNumber)
    {
        vector<bool> flags = PointPointAlgorithm(obj1, obj2);
        if (flags == predicates[predicateNumber])
            return true;
        return false;
    } 

    // Sam
    bool VerifyPredicate::verify(Point2D obj1, Line2D obj2, int predicateNumber)
    {
        vector<bool> flags = PointLineAlgorithm(obj1, obj2);
        if (flags[0] == pointLinePredicates[predicateNumber][3] && flags[1] == predicates[predicateNumber][0] && flags[2] == predicates[predicateNumber][1] && flags[3] == predicates[predicateNumber][7])
            return true;
        return false;
    }
    bool VerifyPredicate::verify(Point2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> flags = PointRegionAlgorithm(obj1, obj2);
        if (flags == predicates[predicateNumber])
            return true;
        return false;
    }
    //cody
    bool VerifyPredicate::verify(Line2D obj1, Line2D obj2, int predicateNumber)
    {
        vector<bool> flags = createLineLine9IM(LineLineAlgorithm(obj1, obj2));
        if (flags == predicates[predicateNumber])
            return true;
        return false;
    }

    // Sam
    bool VerifyPredicate::verify(Line2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> flags = LineRegionAlgorithm(obj1, obj2);
        if (flags[0] == lineRegionPredicates[predicateNumber][0] && (flags[1] == predicates[predicateNumber][1] || flags[3] == predicates[predicateNumber][1]) && flags[2] == predicates[predicateNumber][2] && flags[4] == predicates[predicateNumber][3] && flags[5] == predicates[predicateNumber][4] && flags[6] == predicates[predicateNumber][5] && flags[7] == predicates[predicateNumber][7])
            return true;
        return false;
    }

    // Douglas
    bool VerifyPredicate::verify(Region2D obj1, Region2D obj2, int predicateNumber)
    {
        vector<bool> flags = RegionRegionAlgorithm(obj1, obj2);
        vector<bool> im = createRegionRegion9IM(flags);
        if (flags == predicates[predicateNumber])
            return true;
        return false;
    }

    // Douglas
    std::vector<bool> VerifyPredicate::PointPointAlgorithm(Point2D p1, Point2D p2)
    {
        std::vector<bool> flags; // poi_shared, poi_disjoint p1, poi_disjoint p2
        flags.resize(3, false);
        std::vector<SimplePoint2D> p1Points;
        std::vector<SimplePoint2D> p2Points;
        for(Point2D::Iterator iter = p1.begin(); iter != p1.end(); iter++) 
            p1Points.push_back(*iter);
        for(Point2D::Iterator iter = p2.begin(); iter != p2.end(); iter++) 
            p2Points.push_back(*iter);
        
        ParallelObjT pot(p1Points, p2Points);   // start of parallel object traversal
        SimplePoint2D next = pot.SelectNext().point;
        while(pot.status == 0 && !(flags[0] && flags[1] && flags[2]))       // while not end of either and not all flags have been set
        {
            if(pot.object == 1)         // if p1, then p1 has a disjoint point
                flags[1] = true;
            else if(pot.object == 2)    // if p2, then p2 has a disjoint point
                flags[2] = true;
            else                        // if both, they have a shared point
                flags[0] = true;
            next = pot.SelectNext().point;
        }

        if(pot.status == 1)             // ended early on p1 means p2 still has points which are disjoint
            flags[2] = true;
        else if(pot.status == 2)        // ended early on p2 means p1 still has points which are disjoint
            flags[1] = true;

        return flags;
    }
    
    //Line || Line
    std::vector<bool> VerifyPredicate::LineLineAlgorithm(Line2D line1, Line2D line2)
    {
        std::vector<HalfSegment2D> line1Vector;
        std::vector<HalfSegment2D> line2Vector;
        std::vector<bool> featureVector;
        featureVector.resize(9, false);

        for(Line2D::iterator ptr = line1.begin(); ptr != line1.end(); ptr++)
         {
            line1Vector.push_back(*ptr);
        }
        for(Line2D::iterator ptr = line2.begin(); ptr != line2.end(); ptr++) 
        {
            line2Vector.push_back(*ptr);
        }
        PlaneSweep newSweep;
        ParallelObjT objT(line1Vector, line2Vector);

        SimplePoint2D lastDpF;
        SimplePoint2D lastDpG;
        SimplePoint2D lastBoundPointF;
        SimplePoint2D lastBoundPointG;

        EventPoint eventPoint = objT.SelectNext();
        while(objT.status != 3 && (featureVector[0] == false || featureVector[1] == false || featureVector[2] == false || featureVector[3] == false || featureVector[4] == false || featureVector[5] == false || featureVector[6] == false || featureVector[7] == false || featureVector[8] == false))
        {
            if(objT.object == 1)
            {
                HalfSegment2D halfSeg = eventPoint.halfSeg;
                if(halfSeg.isDominatingPointLeft)
                    newSweep.add_left(halfSeg.s, objT.object);
                else
                {
                    newSweep.del_right(halfSeg.s);
                    featureVector[2] = true; //seg unshared
                }

                if(halfSeg.getDP() != lastDpF)
                {
                    lastDpF = halfSeg.getDP();
                }
                if(!newSweep.look_ahead(halfSeg, line1Vector))
                {
                    lastBoundPointF = halfSeg.getDP();
                    if(lastBoundPointF == lastBoundPointG)
                    {
                        featureVector[4] = true; //bound point shared
                    }
                    else if(lastBoundPointF == lastDpG)
                    {
                        featureVector[3] = true; //bound point on interior
                    }
                    else if(!newSweep.look_ahead(halfSeg, line2Vector))
                    {
                        featureVector[5] = true; //obj1 boundary disjoint
                    }
                }
                if(halfSeg.getDP() != lastBoundPointF)
                {
                    if(halfSeg.getDP() == lastBoundPointG)
                    {
                        featureVector[7] = true; //obj2 bound on interior
                    }
                    else if(halfSeg.getDP() == lastDpG)
                    {
                        featureVector[1] = true; //interior point shared
                    }
                }
            }
            else if(objT.object == 2)
            {
                HalfSegment2D halfSeg = eventPoint.halfSeg;
                if(halfSeg.isDominatingPointLeft)
                {
                    newSweep.add_left(halfSeg.s, objT.object);
                }
                else
                {
                    newSweep.del_right(halfSeg.s);
                    featureVector[6] = true; //seg unshared
                }

                if(halfSeg.getDP() != lastDpG)
                {
                    lastDpG = halfSeg.getDP();
                }
                if(!newSweep.look_ahead(halfSeg, line2Vector))
                {
                    lastBoundPointG = halfSeg.getDP();
                    if(lastBoundPointG == lastBoundPointF)
                    {
                        featureVector[4] = true; //bound point shared
                    }
                    else if(lastBoundPointG == lastDpF)
                    {
                        featureVector[7] = true; //bound point on interior
                    }
                    else if(!newSweep.look_ahead(halfSeg, line1Vector))
                    {
                        featureVector[8] = true; //obj2 boundary disjoint
                    }
                }

                if(halfSeg.getDP() != lastBoundPointG)
                {
                    if(halfSeg.getDP() == lastBoundPointF)
                    {
                        featureVector[3] = true; //obj1 bound on interior
                    }
                    else if(halfSeg.getDP() == lastDpF)
                    {
                        featureVector[1] = true; //interior point shared
                    }
                }
            }
            else
            {
                featureVector[0] = true;
                HalfSegment2D halfSeg = eventPoint.halfSeg;
                if(halfSeg.isDominatingPointLeft)
                {
                    newSweep.add_left(halfSeg.s, objT.object);
                }
                else
                {
                    newSweep.del_right(halfSeg.s);
                }
                if(halfSeg.getDP() != lastDpF)
                {
                    lastDpF = halfSeg.getDP();

                    if(!newSweep.look_ahead(halfSeg, line2Vector))
                    {
                        lastBoundPointF = halfSeg.getDP();
                    }
                }
                if(halfSeg.getDP() != lastDpG)
                {
                    lastDpG = halfSeg.getDP();

                    if(!newSweep.look_ahead(halfSeg, line2Vector))
                    {
                        lastBoundPointG = halfSeg.getDP();
                    }
                }
                if(lastBoundPointF == lastBoundPointG)
                {
                    featureVector[4] = true;
                }
                else
                {
                    if(lastBoundPointF == lastDpG)
                    {
                        featureVector[3] = true;
                    }
                    if(lastBoundPointG == lastDpF)
                    {
                        featureVector[7] = true;
                    }
                }
            }
            if(objT.status == 1)
            {
                featureVector[6] = true;
            }
            else if(objT.status == 2)
            {
                featureVector[2] = true;
            }
            eventPoint = objT.SelectNext();
        }
        return featureVector;
    }

    //Point || Region
    std::vector<bool> VerifyPredicate::PointRegionAlgorithm(Point2D points, Region2D region)
    {
        std::vector<SimplePoint2D> pointVector;
        std::vector<AttributedHalfSegment2D> regionVector;

        std::vector<bool> featureVector;
        featureVector.resize(3, false);

        for(Point2D::Iterator ptr = points.begin(); ptr != points.end(); ptr++) 
        {
            pointVector.push_back(*ptr);
        }
        for(Region2D::iterator ptr = region.begin(); ptr != region.end(); ptr++) 
        {
            regionVector.push_back(*ptr);
        }
        
        PlaneSweep newSweep;
        ParallelObjT objT(pointVector, regionVector);
        EventPoint eventPoint = objT.SelectNext();
        while(objT.status == 0 && (featureVector[0] == false || featureVector[1] == false || featureVector[2] == false)) 
        {
            if(objT.object == 1) //object is a point
            {
                SimplePoint2D point = eventPoint.point;
                if(newSweep.poi_on_seg(point))
                {
                    //Point on bound = true
                    featureVector[1] = true;
                }
                else if(newSweep.pred_of_p_exists(point))
                {
                    Segment2D newBound = newSweep.pred_of_p(point);
                    bool isAbove = newSweep.get_attr(newBound);
                    if(isAbove) //attribute = above 
                    {
                        featureVector[0] = true; //point on inside
                    }
                    else //attribute below
                    {
                        featureVector[2] = true; //point on outside
                    }
                }
                else //point below region
                {
                    featureVector[2] = true;
                }
            }
            else //object is the region or object is both
            {
                //get half segment from event point
                AttributedHalfSegment2D attrHalfSeg = eventPoint.attrHalfSeg;
                if(attrHalfSeg.hs.isDominatingPointLeft) 
                {
                    newSweep.add_left(attrHalfSeg.hs.s, objT.object);
                    newSweep.set_attr(attrHalfSeg.hs.s, attrHalfSeg.above);
                }
                else
                {
                    newSweep.del_right(attrHalfSeg.hs.s);
                }
                
                if(objT.object == 3)
                {
                    featureVector[1] = true; //point on boundary
                }
            }

            eventPoint = objT.SelectNext(); //call select next
        }

        if(objT.status == 2) //status = end of second
        {
            featureVector[2] = true; //point on outside
        }

        return featureVector;
    }

    // Douglas
    std::vector<bool> VerifyPredicate::RegionRegionAlgorithm(Region2D f, Region2D g)
    {
        std::vector<bool> flags; // 0/1, 1/0, 1/2, 2/1, 0/2, 2/0, 1/1, bound_poi_shared, 0/1g, 1/0g, 1/2g, 2/1g
        flags.resize(12, false);
        std::vector<AttributedHalfSegment2D> fSegments;
        std::vector<AttributedHalfSegment2D> gSegments;
        //std::vector<SimplePoint2D> fPoints;
        //std::vector<SimplePoint2D> gPoints;
        for(Region2D::iterator iter = f.begin(); iter != f.end(); iter++)
        {
            fSegments.push_back(*iter);
            /*if((*iter).hs.isDominatingPointLeft)
                fPoints.push_back((*iter).hs.s.leftEndPoint);
            else
                fPoints.push_back((*iter).hs.s.rightEndPoint);*/
        }
        for(Region2D::iterator iter = g.begin(); iter != g.end(); iter++)
        {
            gSegments.push_back(*iter);
            /*if((*iter).hs.isDominatingPointLeft)
                gPoints.push_back((*iter).hs.s.leftEndPoint);
            else
                gPoints.push_back((*iter).hs.s.rightEndPoint);*/
        }

        PlaneSweep sweep;
        ParallelObjT pot(fSegments, gSegments);   // start of parallel object traversal
        AttributedHalfSegment2D next = pot.SelectNext().attrHalfSeg;
        AttributedHalfSegment2D next2 = pot.SelectNext().attrHalfSeg2;
        AttributedHalfSegment2D last_dp_in_f;
        AttributedHalfSegment2D last_dp_in_g;

        map<pair<int, int>, bool> vf;
        map<pair<int, int>, bool> vg;
        while(pot.status == 0 && !(flags[0] && flags[1] && flags[2] && flags[3] && flags[4] && flags[5] && flags[6] && flags[7] && flags[8] && flags[9] && flags[10] && flags[11]))
        {
            if(pot.object == 1)      // if f, set last_dp_in_f
                last_dp_in_f = next;
            else if(pot.object == 2) // if g, set last_dp_in_g
                last_dp_in_g = next;
            else                     // if both, set both
            {
                last_dp_in_f = next;
                last_dp_in_g = next2;
            }
            if(last_dp_in_f == last_dp_in_g || last_dp_in_f == sweep.look_ahead_2(last_dp_in_g, gSegments) || last_dp_in_g == sweep.look_ahead_2(last_dp_in_f, fSegments))
                flags[7] = true; // bound_poi_shared
            if(!next.hs.isDominatingPointLeft)
            {
                pair<int, int> overlap_numbers = sweep.get_attr_2(next.hs.s);
                if(pot.object == 1)      // if f, add to vf
                    if(vf.find(overlap_numbers) == vf.end())
                        vf.insert(make_pair(overlap_numbers, true));
                else if(pot.object == 2) // if g, add to vg
                    if(vg.find(overlap_numbers) == vg.end())
                        vg.insert(make_pair(overlap_numbers, true));
                else                     // if both, set both
                {
                    if(vf.find(overlap_numbers) == vf.end())
                        vf.insert(make_pair(overlap_numbers, true));
                    if(vg.find(overlap_numbers) == vg.end())
                        vg.insert(make_pair(overlap_numbers, true));
                }
                sweep.del_right(next.hs.s);
            }
            else
            {
                pair<int, int> mn_pred;
                sweep.add_left(next.hs.s, pot.object);
                if(sweep.coincident(next.hs.s, pot.region1Dynamic, pot.region2Dynamic))
                    pot.object = 3;
                if(!sweep.pred_exists(next.hs.s))
                    mn_pred = make_pair(3, 0);       // 3 = *
                else
                    mn_pred = sweep.get_pred_attr_2(next.hs.s);
                pair<int, int> mn = make_pair(mn_pred.second, mn_pred.second);
                if(pot.object == 1 || pot.object == 3)
                {
                    if(next.above)
                        mn.second += 1;
                    else
                        mn.second -= 1;
                }
                if(pot.object == 2 || pot.object == 3)
                {
                    if(next2.above)
                        mn.second += 1;
                    else
                        mn.second -= 1;
                }
                sweep.set_attr_2(next.hs.s, mn);
            }
            next = pot.SelectNext().attrHalfSeg;
        }
        if(pot.status == 1)
        {
            if(vg.find(make_pair(0, 1)) == vg.end())
                vg.insert(make_pair(make_pair(0, 1), true));
            if(vg.find(make_pair(1, 0)) == vg.end())
                vg.insert(make_pair(make_pair(1, 0), true));
        }
        else if(pot.status == 2)
        {
            if(vf.find(make_pair(0, 1)) == vf.end())
                vf.insert(make_pair(make_pair(0, 1), true));
            if(vf.find(make_pair(1, 0)) == vf.end())
                vf.insert(make_pair(make_pair(1, 0), true));
        }

        // convert vf and vg to bool vector
        if(vf.find(make_pair(0, 1)) != vf.end())
            flags[0] = true;
        if(vf.find(make_pair(1, 0)) != vf.end())
            flags[1] = true;
        if(vf.find(make_pair(1, 2)) != vf.end())
            flags[2] = true;
        if(vf.find(make_pair(2, 1)) != vf.end())
            flags[3] = true;
        if(vf.find(make_pair(0, 2)) != vf.end())
            flags[4] = true;
        if(vf.find(make_pair(2, 0)) != vf.end())
            flags[5] = true;
        if(vf.find(make_pair(1, 1)) != vf.end())
            flags[6] = true;
        if(vg.find(make_pair(0, 1)) != vg.end())
            flags[8] = true;
        if(vg.find(make_pair(1, 0)) != vg.end())
            flags[9] = true;
        if(vg.find(make_pair(1, 2)) != vg.end())
            flags[10] = true;
        if(vg.find(make_pair(2, 1)) != vg.end())
            flags[11] = true;

        return flags;
    }
    
    // Sam (I think)
    AttributedHalfSegment2D GetAttrHalfSeg(std::vector<AttributedHalfSegment2D> halfSegVec, SimplePoint2D point)
    {
        for(int i = 0; i < halfSegVec.size(); i++)
        {
            if(halfSegVec[i].hs.isDominatingPointLeft)
            {
                if(halfSegVec[i].hs.s.leftEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
            else
            {
                if(halfSegVec[i].hs.s.rightEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
        }
    }

    // Sam (I think)
    HalfSegment2D GetHalfSeg(std::vector<HalfSegment2D> halfSegVec, SimplePoint2D point)
    {
        for(int i = 0; i < halfSegVec.size(); i++)
        {
            if(halfSegVec[i].isDominatingPointLeft)
            {
                if(halfSegVec[i].s.leftEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
            else
            {
                if(halfSegVec[i].s.rightEndPoint == point)
                {
                    return halfSegVec[i];
                }
            }
        }
    }

    // Sam
    std::vector<bool> VerifyPredicate::PointLineAlgorithm(Point2D obj1, Line2D obj2)
    {
        vector<bool> features {false, false, false, false};
        PlaneSweep S = PlaneSweep();
        SimplePoint2D last_dp;
        Point2D::Iterator ptr;
        Line2D::iterator ptr2;
        vector<SimplePoint2D> obj1V; 
        vector<HalfSegment2D> obj2HV;
        // Pushing event points into the vectors.
        for (ptr = obj1.begin(); ptr < obj1.end(); ptr++)
        {
            obj1V.push_back(*ptr);
        }

        for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
        {
            obj2HV.push_back(*ptr2);
        }
        // Creating parallel object traverssal object
        ParallelObjT pt(obj1V, obj2HV);
        EventPoint eventPoint = pt.SelectNext();
        do
        {

            // If the current event point we are considering is from the Point2D
            if (pt.object == 1)
            {
                // We check that this point is contained in the Line2D object
                if (S.poi_on_seg(eventPoint.point))
                {
                    // If it is, then the poi_on_interior flag is flipped
                    features[1] = true;
                }
                else
                {
                    // If it is not, then the poi_disjoint flag is flipped
                    features[0] = true;
                }
            }
            
            // If the current event point we are considering is from the Line2D
            else if (pt.object == 2)
            {
                // if this halfsegment is a left dominant halfsegment
                if (eventPoint.halfSeg.isDominatingPointLeft)
                {
                    // add it to the planesweep
                    S.add_left(eventPoint.halfSeg.s, pt.object);
                }
                else
                {
                    // delete it from the planesweep
                    S.del_right(eventPoint.halfSeg.s);
                }

                // if the current halfsegment's dominating point is not equal to the last dominating point. 
                if (eventPoint.halfSeg.getDP() != last_dp)
                {
                    // change that
                    last_dp = eventPoint.halfSeg.getDP();
                }

                // if the current halfSegment does not share a dominating point with the next half segment
                if (!S.look_ahead(eventPoint.halfSeg, obj2HV))
                {
                    // the flag bound_point_disjoint is flipped
                    features[3] = true;
                }
            }

            // from both objects
            else
            {
                // if the halfseg is left dominant
                if (eventPoint.halfSeg.isDominatingPointLeft)
                {
                    // add it to the planesweep
                    S.add_left(eventPoint.halfSeg.s, pt.object);
                }
                else
                {
                    // delete it from the planesweep
                    S.del_right(eventPoint.halfSeg.s);
                }
                // the last dominating point is set equal to the event point's dominating point
                last_dp = eventPoint.halfSeg.getDP();

                // if the halfsegment's dominating point is the same as the next one's
                if (S.look_ahead(eventPoint.halfSeg, obj2HV))
                {
                    // poi_on_interior is flipped
                    features[1] = true;
                }
                else
                {
                    // poi_on_bound is flipped
                    features[2] = true;
                }
            }
            // parallel object traverssal chooses the next event point
            eventPoint = pt.SelectNext();
        }
        while (pt.status != 2 && pt.status != 3 && !(features[0] && features[1] && features[2] && features[3]));
        // if the status is end of second
        if (pt.status == 2)
        {
            // poi_disjoint is true
            features[0] = true;
        }
        return features;
    }

    // Sam
    std::vector<bool> VerifyPredicate::LineRegionAlgorithm(Line2D obj1, Region2D obj2)
    {
        // 0 seg_inside, 1 seg_shared, 2 seg_outside, 3 poi_shared, 4 bound_inside, 5 bound_shared, 6 bound_disjoint, 7 seg_unshared
        vector<bool> features{false, false, false, false, false, false, false, false};
        PlaneSweep S = PlaneSweep();
        SimplePoint2D last_dp_in_F;
        SimplePoint2D last_dp_in_G;
        SimplePoint2D last_bound_in_F;
        Line2D::iterator ptr1;
        Region2D::iterator ptr2;
        vector<HalfSegment2D> obj1HV;
        vector<AttributedHalfSegment2D> obj2HV;

        for (ptr1 = obj1.begin(); ptr1 < obj1.end(); ptr1++)
        {
            obj1HV.push_back(*ptr1);
        }

        for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
        {
            obj2HV.push_back(*ptr2);
        }

        ParallelObjT pt(obj1HV, obj2HV);
        EventPoint eventPoint = pt.SelectNext();
        do 
        {
            // if the current object is the Line2D, this means that the event point 
            // is a halfsegment
            if (pt.object == 1)
            {
                // if this halfsegment is left dominant
                if (eventPoint.halfSeg.isDominatingPointLeft)
                {
                    // add it to the sweep
                    S.add_left(eventPoint.halfSeg.s, pt.object);
                }
                else
                {
                    // check if there is a predisesor in the plane sweep
                    if (S.pred_exists(eventPoint.halfSeg.s))
                    {
                        // if there is, find the attr values and store them in this pair
                        pair<bool, bool> MpOverNp = S.get_pred_attr_2(eventPoint.halfSeg.s);

                        // if MpOverNp is true
                        if (MpOverNp.second == 1)
                        {
                            // seg_inside is true
                            features[0] = true;
                        }
                        else
                        {
                            // seg_outside is true
                            features[2] = true;
                        }
                    }
                    else
                    {
                        // seg_outside is true
                        features[2] = true;
                    }
                    // delete the halfsegment from the sweep
                    S.del_right(eventPoint.halfSeg.s);
                }
                // get the dominating point from the eventPoint.
                SimplePoint2D p = eventPoint.halfSeg.getDP();
                // if this dominating point is not the last dp in F
                if (p != last_dp_in_F)
                {
                    // make it so
                    last_dp_in_F = p;

                    // if the current halfseg and the next one in the POT do not share a dp
                    if (!S.look_ahead(eventPoint.halfSeg, obj1HV))
                    {
                        // last_bound_in_F is now p
                        last_bound_in_F = p;

                        // if the last boundary point in F is equal to the last dominating point in G
                        // or the halfsegment exists in G and shares a dominating point with the next one
                        if ((last_bound_in_F == last_dp_in_G) || S.look_ahead_3(eventPoint.attrHalfSeg, obj2HV))
                        {
                            // bound_shared is true
                            features[5] = true;
                        }
                        else
                        {   
                            // if the current event point has a predecessor in the planesweep
                            if (S.pred_exists(eventPoint.halfSeg.s))
                            {
                                // calculate the attr for this event point, store it in the pair
                                pair<bool, bool> MpOverNp = S.get_pred_attr_2(eventPoint.halfSeg.s);
                                if (MpOverNp.second == 1)
                                {
                                    // bound_inside is flipped to true
                                    features[4] = true;
                                }
                                else
                                {
                                    // bound_disjoint is flipped to true
                                    features[6] = true;
                                }
                            }
                            else 
                            {
                                // bound_disjoint is flipped to true
                                features[6] = true;
                            }
                        }
                    }
                }

                if (p != last_bound_in_F && (p == last_dp_in_G || S.look_ahead_3(eventPoint.attrHalfSeg, obj2HV)))
                {
                    // poi_shared is flipped
                    features[3];
                }
            }

            // if the event point is from the region
            else if (pt.object == 2)
            {
                // ia gets the attribute of the current attrhalfseg
                bool ia = S.get_attr(eventPoint.attrHalfSeg.hs.s);

                // if this attrhalfseg is left dominant
                if (eventPoint.attrHalfSeg.hs.isDominatingPointLeft)
                {
                    // add it to the planesweep
                    S.add_left(eventPoint.halfSeg.s, pt.object);
                    // set the attr of the segment we added to the planesweep
                    S.set_attr(eventPoint.halfSeg.s, ia);
                }
                else 
                {
                    // delete from plansweep
                    S.del_right(eventPoint.halfSeg.s);
                    // seg_unshared flipped to true
                    features[7] = true;
                }

                // get the dominating point of the halfsegment
                SimplePoint2D p = eventPoint.attrHalfSeg.hs.getDP();

                // if it is not the last dominating point in G
                if (p != last_dp_in_G)
                {
                    // make it so
                    last_dp_in_G = p;
                }
            }

            else
            {
                // seg_shared is true
                features[1] = true;

                // get the attr from the attrhalfseg
                bool ia = S.get_attr(eventPoint.attrHalfSeg.hs.s);

                // if it is a left dominant halfsegment
                if (eventPoint.attrHalfSeg.hs.isDominatingPointLeft)
                {
                    // add the segment to the sweep and set its attr
                    S.add_left(eventPoint.attrHalfSeg.hs.s, pt.object);
                    S.set_attr(eventPoint.attrHalfSeg.hs.s, ia);
                }
                else
                {
                    // delete it from the sweep
                    S.del_right(eventPoint.attrHalfSeg.hs.s);
                }

                // get the dominating point of the hs
                SimplePoint2D p = eventPoint.attrHalfSeg.hs.getDP();

                // if this point is not the last dp in F
                if (p != last_dp_in_F)
                {
                    // make it so
                    last_dp_in_F = p;

                    // if the current halfsegment does not share a dp with the next in line
                    if (!S.look_ahead(eventPoint.attrHalfSeg.hs, obj1HV))
                    {
                        // bound_shared is flipped to true
                        features[5] = true;
                    }
                    else
                    {
                        // poi_shared is flipped to true
                        features[3] = true;
                    }
                }

                // if this point is not the last dp in G
                if (p != last_dp_in_G)
                {
                    // make it so
                    last_dp_in_G = p;
                }
            }

            // if the POT is at the end of the second object
            if (pt.status == 2)
            {
                // seg_outside is flipped to true
                features[2] = true;
            }

            // POT gets the next event point
            eventPoint = pt.SelectNext();
        }
        while (pt.status != 1 && pt.status != 3 && !(features[0] && features[1] && features[2] && features[3] && features[4] && features[5] && features[6] && features[7]));

        // if POT is at the end of the first object
        if (pt.status = 1)
        {
            // seg_unshared flipped to true
            features[7] = true;
        }
        return features;
    }

    /* for (ptr2 = obj2.begin(); ptr2 < obj2.end(); ptr2++)
        {
            obj2HV.push_back(*ptr2);
            if (obj2HV.back().isDominatingPointLeft)
            {
                obj2PV.push_back(obj2HV.back().s.leftEndPoint);
            }
            else
            {
                obj2PV.push_back(obj2HV.back().s.rightEndPoint);
            }
        }
    */

   // Sam
    HalfSegment2D VerifyPredicate::findHS(vector<HalfSegment2D> HS, SimplePoint2D point)
    {
        for (int i = 0; i < HS.size(); i++)
        {
            if (HS[i].getDP() == point)
            {
                return HS[i];
            }
        }
    }