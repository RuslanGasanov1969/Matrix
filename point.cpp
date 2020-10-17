#include "point.h"
#include <math.h>
#include <stdlib.h>

Point::Point()
{
   x = 0;
   y = 0;
}

Point::Point(double _x, double _y){
    x = _x;
    y = _y;
}

Point Point::createRandomPoint(int from, int to){
    double x = (from * 100 + rand() % ((to - from) * 100)) / 100.0;
    double y = (from * 100 + rand() % ((to - from) * 100)) / 100.0;
    return Point(x, y);
}

ostream& operator<<(ostream& out, const Point& point){
    out << "(" << point.x << ", " << point.y << " Sum = " << point.x+point.y << ") \n";
    return out;
}

void Point::ShowPoints(Point *points, int n){
    for(int i = 0; i < n; i++){
        cout << points[i] << " ";
    }
    cout << endl;
}

Point* Point::CreatePointArray(int n,int from, int to){
    Point *points = new Point[n];
    for(int i = 0; i < n; i++){
        points[i] = createRandomPoint(from, to);
    }
    return points;
}

double Point::GetDistance(const Point& a, const Point& b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx*dx + dy*dy);
}

int Point::GetQurter()const{
    if(x > 0 && y > 0) return 1;
    if(x < 0 && y > 0) return 2;
    if(x < 0 && y < 0) return 3;
    if(x > 0 && y < 0) return 4;
    return 0;
}

double Point::GetTotalDistance(const Point& a, Point* points, int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        double dist = GetDistance(a, points[i]);
        sum = sum + dist;
    }
    return sum;
}

double Point::GetTrianglePerim(const Point& a, const Point& b, const Point& c){
    double ab = GetDistance(a, b);
    double bc = GetDistance(b, c);
    double ac = GetDistance(a, c);

    return ab + bc + ac;
}

int Point::compare1(const Point& a, const Point& b){
    if (a.x > b.x) return 1;
    if (a.x < b.x) return -1;
    if (a.y > b.y) return 1;
    if (a.y < b.y) return -1;
    return 0;
}

int Point::compare2(const Point& a, const Point& b){
    if ( (a.x+a.y) > (b.x+b.y) ) return  1;
    if ( (a.x+a.y) < (b.x+b.y) ) return -1;
    //cout << a << b << "<====================================" << endl;
    if (a.x > b.x) return  1;
    if (a.x < b.x) return -1;
    return 0;
}

//void Point::SortArrayMax(Point* points, n){
//    for(int i = 0; i < n-1; i++){
//        for(int j = i+1; j < n; j++){
//
//        }
//    }
//}
