#ifndef LINE_H
#define LINE_H

#include <iostream>

struct Point {
    int x, y;
    void print() const {
        std::cout << x << " " << y << std::endl;
    }
};
class Line
{
    int coefX, coefY, coefD;

    public:
        Line(const Point& x1,const Point& x2);
        Line(const int& a, const int& b, const int& c);
        Point findInsn(const Line& other) const;
        Line findOrtoLine(const Point p) const;
        void print() const;
        virtual ~Line();

    protected:

    private:
};

#endif // LINE_H
