// Douglas
#ifndef ATTRIBUTEDHALFSEGMENT2D_H
#define ATTRIBUTEDHALFSEGMENT2D_H
#include "HalfSegment2D.h"
struct AttributedHalfSegment2D
{
	HalfSegment2D hs;
	bool above;
	AttributedHalfSegment2D();
	AttributedHalfSegment2D(const AttributedHalfSegment2D& ahs);
	AttributedHalfSegment2D(HalfSegment2D hs, bool above);
	AttributedHalfSegment2D(AttributedHalfSegment2D&& ahs);
	AttributedHalfSegment2D& operator=(const AttributedHalfSegment2D& ahs);
	AttributedHalfSegment2D& operator=(AttributedHalfSegment2D&& ahs);
	bool operator<(const AttributedHalfSegment2D& ahs) const;
	bool operator<=(const AttributedHalfSegment2D& ahs) const;
	bool operator==(const AttributedHalfSegment2D& ahs) const;
	bool operator>=(const AttributedHalfSegment2D& ahs) const;
	bool operator>(const AttributedHalfSegment2D& ahs) const;
	bool operator!=(const AttributedHalfSegment2D& ahs) const;
};
#endif
