#include <iostream>
#include <Line.h>

using namespace std;

int main()
{
    Line l1{1, 1, 1};
    Line l2 = l1.findOrtoLine(Point{2, -3});
    Point p = l1.findInsn(l2);
    //l1.findOrtoLine(p).print();
    p.print();
    return 0;
}
