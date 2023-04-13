#include "Segment2D.h"
#include <cmath>

Segment2D::Segment2D()		// Created default constructor so that HalfSegment2D works.
{
}

Segment2D::Segment2D(const Segment2D& s)
{
	this->leftEndPoint = s.leftEndPoint;
	this->rightEndPoint = s.rightEndPoint;
}

Segment2D::Segment2D(SimplePoint2D l, SimplePoint2D r)
{
	if (l < r)
	{
		this->leftEndPoint = l;
		this->rightEndPoint = r;
	}
	else
	{
		this->leftEndPoint = r;
		this->rightEndPoint = l;
	}
}

Segment2D::Segment2D(Segment2D&& s)
{
	this->leftEndPoint = std::move(s.leftEndPoint);
	this->rightEndPoint = std::move(s.rightEndPoint);
}

Segment2D& Segment2D::operator=(const Segment2D& s)
{
	this->leftEndPoint = s.leftEndPoint;
	this->rightEndPoint = s.rightEndPoint;
	return *this;
}

Segment2D& Segment2D::operator=(Segment2D&& s)
{
	this->leftEndPoint = std::move(s.leftEndPoint);
	this->rightEndPoint = std::move(s.rightEndPoint);
	return *this;
}

bool Segment2D::operator==(const Segment2D& s) const
{
	return (this->leftEndPoint == s.leftEndPoint && (*this).rightEndPoint == s.rightEndPoint);
	
}

bool Segment2D::operator>=(const Segment2D& s) const
{
	return !((*this) < s);
}

bool Segment2D::operator>(const Segment2D& s) const
{
	return !((*this) <= s);
}

bool Segment2D::operator<(const Segment2D& s) const
{
	if (this->leftEndPoint < s.leftEndPoint)
		return true;
	else
		return (this->leftEndPoint == s.leftEndPoint && this->rightEndPoint < s.rightEndPoint);
}

bool Segment2D::operator<=(const Segment2D& s) const
{
	return ((*this) < s || (*this) == s);
}

bool Segment2D::operator!=(const Segment2D& s) const
{
	return !((*this) == s);
}

std::pair<bool, SimplePoint2D> Segment2D::findIntersection(Segment2D s)
{
	Number x1 = leftEndPoint.x;
	Number y1 = leftEndPoint.y;
	Number x2 = rightEndPoint.x;
	Number y2 = rightEndPoint.y;
	Number x3 = s.leftEndPoint.x;
	Number y3 = s.leftEndPoint.y;
	Number x4 = s.rightEndPoint.x;
	Number y4 = s.rightEndPoint.y;

	Number denominator = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
	SimplePoint2D empty;
	Number zero = "0.0";
	if (denominator == zero)
		return std::make_pair(false, empty);
	else 
	{
		Number ia = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denominator;
		Number ib = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denominator;
		Number one = "1.0";
		if (ia < zero || ia > one || ib < zero || ib > one) 
		{
			// The intersection point does not exist in at least one of the segments.
			return std::make_pair(false, empty);
		} 
		else 
		{
			Number x = x1 + ia * (x2 - x1);
			Number y = y1 + ia * (y2 - y1);
			SimplePoint2D p(x, y);
			return std::make_pair(true, p);
		}
	}
	return std::make_pair(false, empty);
}

std::pair<bool, SimplePoint2D> Segment2D::findIntersection_excludeEndpoints(Segment2D s)
{
	std::pair<bool, SimplePoint2D> p = findIntersection(s);
	if(p.first)
	{
		if(p.second == leftEndPoint || p.second == rightEndPoint)
			return std::make_pair(false, p.second);
	}
}

bool Segment2D::poiOnSeg(SimplePoint2D p)
{
    Number x1 = leftEndPoint.x;
    Number y1 = leftEndPoint.y;
    Number x2 = rightEndPoint.x;
    Number y2 = rightEndPoint.y;
    Number dx = x2 - x1;
    Number dy = y2 - y1;
    Number a = dy;
    Number b = -dx;
    Number c = dx * y1 - dy * x1;
    Number x = p.x;
    Number y = p.y;

    // Check if the point (x, y) lies on the line
    if (a * x + b * y + c != 0) {
        return false;
    }

    // Check if the point (x, y) lies between (x1, y1) and (x2, y2)
    if ((x1 <= x && x <= x2 || x2 <= x && x <= x1) &&
        (y1 <= y && y <= y2 || y2 <= y && y <= y1)) {
        return true;
    }

    return false;
	if(fh + sh == dis)
		return true;
	return false;
}	
