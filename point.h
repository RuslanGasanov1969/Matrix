#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point
{
public:
    double x, y;
    Point();
    Point(double _x, double _y);
    static Point createRandomPoint(int from = -10, int to = 10);

    static void ShowPoints(Point *points, int n);
    static Point *CreatePointArray(int n,int from = -10, int to = 10);
    static double GetDistance(const Point& a, const Point& b);
    int GetQurter()const;
    static double GetTotalDistance(const Point& a, Point* points, int n);
    static double GetTrianglePerim(const Point& a, const Point& b, const Point& c);
//    static void SortArrayMax(Point* points, n);
    static int compare1(const Point& a, const Point& b);//1, 0, -1
    static int compare2(const Point& a, const Point& b);//1, 0, -1
};

ostream& operator<<(ostream& out, const Point& point);

#endif // POINT_H
