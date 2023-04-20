#pragma once
#include "HalfSegment2D.h"
#include "SimplePoint2D.h"
#include "AttributedHalfSegment2D.h"

//cody
struct EventPoint {
    SimplePoint2D point;
    HalfSegment2D halfSeg;
    AttributedHalfSegment2D attrHalfSeg;
    AttributedHalfSegment2D attrHalfSeg2;
    EventPoint();
};