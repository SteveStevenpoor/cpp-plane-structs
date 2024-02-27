#include "Line.h"

Line::Line(const Point& x1,const Point& x2)
{
    coefX = x2.y - x1.y;
    coefY = x1.x - x2.x;
    coefD = x1.y*(x2.x - x1.x) - x1.x;
}
Line::Line(const int& a, const int& b, const int& c) : coefX(a), coefY(b), coefD(c) {};

Point Line::findInsn(const Line& other) const {
    int delta = coefX*other.coefY - coefY*other.coefX;
    if (delta == 0) {
        std::cout << "Lines are parallel" << std::endl;
        return Point{0};
    }
    int deltaX = -coefD*other.coefY + coefY*other.coefD;
    int deltaY = coefX*(-other.coefD) - other.coefX*(-coefD);
    if (deltaX%delta != 0 || deltaY%delta != 0) {
        std::cout << "Lines intersect at real point" << std::endl;
        return Point{(int)(deltaX/delta), (int)(deltaY/delta)};
    } else {
        return Point{deltaX/delta, deltaY/delta};
    }
}

Line Line::findOrtoLine(const Point p) const {
    return Line(-coefY, coefX, coefY*p.x - coefX*p.y);
}

void Line::print() const {
    std::cout << coefX << "x + " << coefY << "y + " << coefD << " = 0" << std::endl;
}

std::string Line::getString() const {
    std::string strline = std::to_string(coefX) + "x + ";
    strline += std::to_string(coefY) + "y + " + std::to_string(coefD);
    return strline;
}

Line::~Line()
{
    //dtor
}
