#include <Line.h>
#include <gtest/gtest.h>

TEST(findInsn, Parallel) {
    Line l1{1, 2, 3};
    Line l2{2, 4, 6};
    Point p = l1.findInsn(l2);

    EXPECT_TRUE(p.x == 0 && p.y == 0);
}

TEST(findInsn, IntegerIntersection) {
    Line l1{1, 2, 4};
    Line l2{2, 3, 5};
    Point p = l1.findInsn(l2);

    EXPECT_TRUE(p.x == 2 && p.y == -3);
}

TEST(findInsn, RealIntersection) {
    Line l1{1, -1, 3};
    Line l2{12, -1, -1};
    Point p = l1.findInsn(l2);
    p.print();

    EXPECT_TRUE(p.x == 0 && p.y == 3);
}

TEST(findOrtoLine, PointOnTheLine) {
    Line l1{1, 2, 3};
    Line l2 = l1.findOrtoLine(Point{-1, -1});
    
    EXPECT_TRUE(l2.getString() == "-2x + 1y + -1");
}

TEST(findOrtoLine, RemotePoint) {
    Line l1{1, 2, 3};
    Line l2 = l1.findOrtoLine(Point{10, -150});
    
    EXPECT_TRUE(l2.getString() == "-2x + 1y + 170");
}
